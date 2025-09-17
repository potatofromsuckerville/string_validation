#include <stdio.h>
#include <string.h>

int main() {
	
	char input[7];
	printf("==== INPUT VALIDATION (PERSONAL BUILD V1) ==== \n");
	printf("Enter %zu characters max: \n", sizeof(input) - 1);
	fgets(input, sizeof(input), stdin);
	
	int stringLength; 
	stringLength = strlen(input);
	
	if (stringLength == 1) {
		printf("Empty input \n");
		}
	
	else if (input[stringLength - 1] == '\n') { // i.e. less than max
		input[stringLength - 1] = '\0';
		printf("Valid input (less than max). You entered: %s \n", input);
		}
			
	else {
		if (getchar() == '\n') {
			printf("Valid input(exactly max). You entered: %s \n", input);
			}
		else {
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {
				}
			printf("Invalid input. Truncation occured. \n");
			}	
		}		
	
	return 0;
	
	}

