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

vocabulary* parseFile(string filename)
{
	FILE *config;
	string line, curSection;
	vocabulary *current, *head;
	int i=0, linenum=0;
	head = NULL;
	config=fopen(filename, "r");
	if (config != NULL) {
		line = malloc(MAX_LINE_LENGTH);
		curSection = malloc(MAX_LINE_LENGTH);
		while(fgets(line, MAX_LINE_LENGTH, config) != NULL)
		{
			linenum++;
			if (line[0] == '#') continue; //ignore hashs as comments.
			else if (line[0] == '\n') continue; //ignore blank lines.
			else if(line[0] == '['){
					line++;
					line[strlen(line)-2] = 0;
					strcpy(curSection, line);
			}
			else {
					current = (vocabulary *)malloc(sizeof(vocabulary) + strlen(curSection) + strlen(line)-2);
					current->section = strdup(curSection);
					current->vocab = strdup(strtok(line,"="));
					current->command = strdup(strtok(NULL, "=\n"));
					current->next = head;
					head = current;
			}
		}
		fclose(config);
		return head;
	}
	else{	
		DIE("Configuration File Not Found");
	}
}

void generalConfig(vocabulary* config)
{
		while(config)
		{
			if(!strcmp(config->vocab,"HOSTNAME")){
  	         	config_json_rpc_host = realloc(config_json_rpc_host, strlen(config->command) + 1);
	            sprintf(config_json_rpc_host, "%s", config->command);
			}
			else if (!strcmp(config->vocab, "PORT")){
					snprintf(config_json_rpc_port, 6, "%s", config->command);
			}
			else if (!strcmp(config->vocab, "USERNAME")){
      	      config_json_rpc_user = realloc(config_json_rpc_user, strlen(config->command) + 1);
         	   sprintf(config_json_rpc_user, "%s", config->command);
			}
			else if (!strcmp(config->vocab, "PASSWORD")){
      	      config_json_rpc_pass = realloc(config_json_rpc_pass, strlen(config->command) +1);
         	   sprintf(config_json_rpc_pass, "%s", config->command);
			}
			else if (!strcmp(config->vocab, "DEVICE")){
      	      config_alsa_device = realloc(config_alsa_device, strlen(config->command) + 1);
         	   sprintf(config_alsa_device, "%s", config->command);
			}
			config = config->next;
		}
}
