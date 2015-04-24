/*Maeda Hanafi
  Lab 1: String functions
  9/14/10
*/
#include<stdio.h>
#include<string.h>

//reverse the contents of the array
void reverse(char* s){
	char* reverseArray = malloc(strlen(s));
	int length = strlen(s);
	int i, j;
	j = length-1;

	//reverse
	for(i=0; i<length; i++){
		*(reverseArray+i) = *(s+j);
		j--;
	}

	//display results
	for(i=0; i<length; i++){
		printf("%c",*(reverseArray+i));
	}
}

//Returns the number of occurrences of the character c in string s.
int count(char* s, char c){
	int occurences = 0, i;
	for(i=0; i<strlen(s); i++){
		if(s[i] == c){
			occurences++;
		}
	}
	return occurences;
}

//Removes all occurrences of character c from string s and 
//returns result as a new string. String s should not be modifed.
char* removeChar(char* s, char c){
	int i, j = 0;
	char* newString = malloc(strlen(s)+1);

	for(i=0; i<strlen(s); i++){
		if(s[i] != c){//check if they aren't a match
			*(newString+j) = *(s+i);
			j++;
		}
	}
	//clear the rest of newstring
	while(j<strlen(s)){
		*(newString+j) = ' ';
		j++;
	}
	
	return newString;
}

//Shuffes the order of words in s and returns result as a new string. 
//Uses the space as a delimiter between words. String s should not be modifed.
char* shuffleWords(char* s){
	char* newString = NULL;
	char* word1 = NULL;
	char* word2 = NULL;
	char* word3 = NULL;
	char* str = malloc(strlen(s)+1);
	char *p;
	int length, i;

	//allocate enough memory space for newString
	newString = malloc(strlen(s)+1);
	
	//clear the contents of newString
	for(i=0; i<strlen(newString); i++){
		newString[i] = ' ';
	}
	
	//array copy
	for(i=0; i<strlen(s); i++){
		str[i] = s[i];
	}

	//get first word
	p = strtok (str," ");
	while (p != NULL){
		//store it in word1
		word1 = malloc(strlen(p));
		strcpy(word1, p);
		//get next word
		p = strtok (NULL, " ");
		//if last word then just concatenate to newString
		if(p==NULL){
			strcat(newString, word1);	
			break;
		}
		//while there are more words, store the next one in word2
		word2 = malloc(strlen(p));
		strcpy(word2,p);
			
		//shuffle word1 and word2
		strcat(newString, word2);
		strcat(newString, " ");
		strcat(newString, word1);
		strcat(newString, " ");
	
		//check if there are anymore words	
		p = strtok (NULL, " ");
		if(p==NULL) 
			break;
	}
	
	return newString;
}

main(){
	char* string = "I am taking operating systems (CSC 305) now.";

	printf("\nhello backwards: ");
	reverse("hello");

	printf("\nNumber of s in systems: %d", count("systems", 's'));

	printf("\nsystems without s: %s",removeChar("systems", 's'));

	printf("\noriginalString: %s \nshuffled string: %s",string, shuffleWords(string, strlen(string)));
	

}