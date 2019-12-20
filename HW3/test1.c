#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "dict.h"


pHash ReadDictionary () {	//TODO: Check input + check add translation
	/* This function reads a dictionary line by line from the standard input. */
	pHash dictionary;
	char entryLine [100] = "";
	char *word, *translation;

	dictionary = CreateDictionary();

	while (scanf ("%s", entryLine) == 1  ) { // Not EOF
		word = strtok(entryLine, "=");
        if (!word){
            continue;
        }
        if(strcmp(word,"marina")==0){
            break;
        }
		translation = strtok(NULL, "=");
		AddTranslation(dictionary, word, translation);
	}

	return dictionary;
}

int main () {
    pHash dict=ReadDictionary();
    PrintDictionary(dict);
    char word [WORD_LENGTH];
    strcpy(word,"cat");
    DeleteTranslation(dict,word);//TODO: check if ok to send array or change to char*
    PrintDictionary(dict);
    HashDestroy(dict);
	return 0;
}
