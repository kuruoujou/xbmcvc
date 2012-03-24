/**********************************************
* This parses a config file, in theory.
**********************************************/
#define MAX_LINE_LENGTH 256

typedef char* string; //I'm lazy.

struct vocabList {
	string section;
	string vocab;
	string command;
	struct vocabList * next;
};

typedef struct vocabList vocabulary;

void parseFile(string filename)
{
	FILE *config;
	string line, curSection;
	vocabulary *current, *head;
	int i=0, linenum=0;
	head = NULL;
	config=fopen(filename, "r");
	if (config != NULL) {
		line = malloc(MAX_LINE_LENGTH);
		while(fgets(line, MAX_LINE_LENGTH, config) != NULL)
		{
			linenum++;
			if (line[0] == '#') continue; //ignore hashs as comments.
			else if (line[0] == '\n') continue; //ignore blank lines.
			else if(line[0] == '['){
					line++;
					line[strlen(line)-2] = 0;
					curSection = strdup(line);
			}
			else {
					current = (vocabulary *)malloc(sizeof(vocabulary));
					current->section = curSection;
					current->vocab = strtok(line,"=");
					current->command = strtok(NULL, "=");
					current->next = head;
					head = current;
			}
		}
		fclose(config);
	}
	else{	
		DIE("Configuration File Not Found");
	}
}
