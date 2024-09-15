#include <stdio.h>
#include <string.h>
#include <ctype.h>

void
clean (char before[], char after[]){
	
	int i, k;

/*
	for (i = 0; i <= strlen(before); i++){	
		if (isalpha(before[i]))
			after[i] = before[i];
		else if(!isalpha(before[i]))
			after[i] = ' ';
	}
	
	
	for (i = 0; i <= strlen(after); i++){	// 
		while (after[i] == ' '){
			if (isspace(after[i])){
				for (k = i; k <= strlen(after); k++)
					after[k] = after[k + 1];
			}
		}
	}
*/

	for (i = 0; i <= strlen(after); i++){
		
		if (isalpha(before[i]))
			after[i] = before[i];
		else if(!isalpha(before[i]) || isspace(after[i])){
			for (k = i; k <= strlen(before); k++){
					after[k] = before[k + 1];
				}
		}
		
	}



// Looks at new string and finds the last space and replaces it with end of array character		
	for (i = 0; i <= strlen(after); i++){
		if(!isalpha(after[i]))
			after[i] = '\0';
	}

// Looks at new string and converts any uppercase characters to lowercase characters	
	for (i = 0; i <= strlen(after); i++){
		if (isupper(after[i])){
			after[i] = tolower(after[i]);
		}
	}
}

void
reverse (char before[], char after[], int i){

// Checks if the current address is equal to the opposite address (counting backwards from the back of the string)
// If not true, swaps the two characters and calls itself again
	if (i == (int)(strlen(after)))
		after[strlen(after) + 1] = '\0';
	else {
		after[strlen(after) - i - 1] = before[i];
		reverse (before, after, i + 1);
	}
}

int
main (void){

	char input[50], cleaned[50], flipped[50];
	int i = 0;
	
	printf("Enter your word or statment (50 character max):\n");
	
	fgets(input, 50, stdin);
	
	printf("%s", input);
	
	clean(input, cleaned); // Calls clean function
	
	printf("%s\n", cleaned);
	
	strcpy(flipped, cleaned); // Sets flipped string equal to cleaned array
	
	reverse (cleaned, flipped, i); // calls reverse function
	
	printf("%s\n", flipped);
	
	i = strcmp(flipped, cleaned); // compares flipped to cleaned
	if (i == 0)
		printf("It's a palindrome!");
	else
		printf("It's not a palindrome!");

return 0;
}
