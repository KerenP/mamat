#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"
#include "dict.h"

#define HASH_SIZE 650

typedef struct _DictElement{
    char* word;
    char* translation;
} DictElement;

int HashWord(char* word, int hashTableSize){
    if (!word || hashTableSize<0){
        return -1;
    }
    int word_index = ((int) (word[0]-'a')*26+strlen(word))%hashTableSize;
    return word_index;
}
Result PrintEntry (pDictElement dictElement){
    if (!dictElement){
        return  FAIL;
    }
    printf("%s : %s\n", dictElement->word, dictElement->translation);
    return SUCCESS;
}
CompResult CompareWords (char* word1, char* word2){
    if (!word1 || !word2){
        return DIFFERENT;
    }
    if (!strcmp(word1, word2)){
        return SAME;
    }
    return DIFFERENT;
}
char* GetEntryKey (pDictElement dictElement){
    if (!dictElement){
        return NULL;
    }
    return  dictElement->word;
}
void  DestroyEntry (pDictElement dictElement){
    if (!dictElement){
        return;
    }
    free(dictElement);
}
pHash CreateDictionary(){
    return HashCreate (HASH_SIZE, HashWord, PrintEntry, CompareWords, GetEntryKey, DestroyEntry);//TODO: add & or declare pointers to all functions
}
Result AddTranslation(pHash dict, char* word, char* translation){
    if (!dict || !word || !translation){
        return FAIL;
    }
    pDictElement newElement = (pDictElement)malloc(sizeof(DictElement));//TODO: free new_element
    if (!newElement){
        return FAIL;
    }
    newElement->word = word;
    newElement->translation = translation;
    return HashAdd(dict, newElement);
}
Result Translate (pHash dict, char* word){
    if (!dict || !word){
        return FAIL;
    }
    pDictElement wanted_element = (pDictElement)HashFind(dict, word);
    if (!wanted_element){
        return FAIL;
    }
    printf("Translation: %s : %s\n", wanted_element->word, wanted_element->translation);
    return SUCCESS;
}
Result DeleteTranslation (pHash dict, char* word){
    if (!dict || !word){
        return FAIL;
    }
    return HashRemove(dict, word);
}
Result PrintDictionary(pHash dict){
    if (!dict){
        return FAIL;
    }
    printf("Dictionary Contents\n");
    return HashPrint(dict);
}