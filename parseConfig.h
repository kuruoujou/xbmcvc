/**********************************************
* This parses a config file, in theory.
**********************************************/
typedef char* string; //I'm lazy.
void parseFile(string filename, string** section, string** vocab, string** command)
{
	FILE *config;
	string line;
	int i=0, linenum=0;

	config=fopen(filename, "r");
	while(fgets(line, 256, config) != NULL)
	{
		linenum++;
		if (line[0] == '#') continue; //ignore hashs as comments.
		if (line[0] == '\n') continue; //ignore blank lines.
		else{
			if (line[0] == '[') {
				*section[i] = malloc(256);
				sscanf(line, "%s", *section[i]);
				section[i]++; //remove opening '['
				section[i][strlen(*section[i])-1] = 0; //remove trailing ']'
			}
			else {
				if (i-1 < 0){ printf("Error in config, line number %d\n", linenum); DIE("Configuration file does not have initial section");}
				*section[i] = malloc(strlen(*section[i-1]));
				*section[i] = strdup(*section[i-1]);
				*vocab[i] = malloc(256);
				*command[i] = malloc(256);
				if(sscanf(line, "%s=%s", *vocab[i], *command[i]) != 2) DIE("Configuration file syntax error.");
			}
			i++;
		}
	}	
}
