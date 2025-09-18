#include <stdio.h>
#include <string.h>

int get_input(char* buffer, size_t buff_size) {
	
	fgets(buffer, buff_size, stdin);
	int stringLength; 
	stringLength = strlen(buffer);
	
	if (stringLength == 1) {
		return 2;
		}
	
	else if (buffer[stringLength - 1] == '\n') { // i.e. less than max
		buffer[stringLength - 1] = '\0';
		return 1;
		}
			
	else {
		if (getchar() == '\n') {
			return 1;
			}
		else {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {
				}
			return 0;
			}	
		}
	}

int main() {
	
	char input[7];
	printf("==== INPUT VALIDATION (PERSONAL BUILD V1) ==== \n");
	printf("Enter %zu characters max: \n", sizeof(input) - 1);
	int state = get_input(input, sizeof(input));
	
	switch (state) {
		case 0:
			printf("Warning: Buffer overflow. Truncation ocurred. \n");
			printf("You entered: %s \n", input);
			break;
			
		case 1:
			printf("Full input received. You entered: %s \n", input);
			break;
			
		case 2:
			printf("Empty input. Program terminated. \n");
			break;
			
		default:
			printf("Error reading input. Proogram terminated/ \n");
			break;
		}
	
	return 0;
	}
