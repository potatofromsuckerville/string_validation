#include <stdio.h>
#include <string.h>
#include "get_input.h"

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
			
		case INPUT_VALID_LTM:
			printf("Full input received (less than max). You entered: %s \n", input);
			break;

		case INPUT_VALID_MAX:
			printf("Full input received (Exactly max). You entered: %s \n", input);
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

