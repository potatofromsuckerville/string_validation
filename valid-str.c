#include <stdio.h>
#include <string.h>

#define INPUT_ERROR -1
#define INPUT_TRUNCATED 0
#define INPUT_VALID 1
#define INPUT_EMPTY 2

int get_input(char* buffer, size_t buff_size) {
	
	if (fgets(buffer, buff_size, stdin) == NULL) {
		return INPUT_ERROR;
		}
		
	int stringLength; 
	stringLength = strlen(buffer);
	
	if (stringLength == 1) {
		return INPUT_EMPTY;
		}
	
	else if (buffer[stringLength - 1] == '\n') { // i.e. less than max
		buffer[stringLength - 1] = '\0';
		return INPUT_VALID;
		}
			
	else {
		if (getchar() == '\n') {
			return INPUT_VALID;
			}
		else {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {
				}
			return INPUT_TRUNCATED;
			}	
		}
	}

int main() {
	
	char input[7];
	printf("==== INPUT VALIDATION (PERSONAL BUILD V1) ==== \n");
	printf("Enter %zu characters max: \n", sizeof(input) - 1);
	int state = get_input(input, sizeof(input));
	
	switch (state) {
		case INPUT_ERROR:
			printf("Error reading input. Program terminated \n");
			break;		
		
		case INPUT_TRUNCATED:
			printf("Warning: Buffer overflow. Input truncated to \"%s\". \n", input);
			break;
			
		case INPUT_VALID:
			printf("Full input received. You entered: %s \n", input);
			break;
			
		case INPUT_EMPTY:
			printf("Empty input. Program terminated. \n");
			break;
			
		default:
			printf("Unknown Error. Exiting program. \n");
			break;
		}
	
	return 0;
	}
