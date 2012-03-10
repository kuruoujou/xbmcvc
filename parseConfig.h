/**********************************************
* This parses a config file, in theory.
**********************************************/
#define MAX_LINE_LENGTH 256

typedef char* string; //I'm lazy.

void parseFile(string filename, string* section, string* vocab, string* command)
{
	FILE *config;
	string line, test;
	int i=0, linenum=0;

	config=fopen(filename, "r");
	if (config != NULL) {
		while(fgets(line, MAX_LINE_LENGTH, config) != NULL)
		{
			linenum++;
			if (line[0] == '#') continue; //ignore hashs as comments.
			else if (line[0] == '\n') continue; //ignore blank lines.
			else {
				printf("GO!\n");
				test = strdup(line);
				printf("DUPPED!\n");
				printf("%s\n", test);
				printf("PRINTED!\n");
				free(test);
				printf("FREED!\n");
				i++;
			}
		}
		fclose(config);
	}
	else{	
		DIE("Configuration File Not Found");
	}
}
