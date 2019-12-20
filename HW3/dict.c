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

int HashWord(pKey word, int hashTableSize){
    if (!word || hashTableSize<0){
        return -1;
    }
    char *charWord=(char*)word;
    int wordIndex = ((int) (charWord[0]-'a')*26+(int)strlen(word))%hashTableSize;
    return wordIndex;
}
Result PrintEntry (pElement dictElement){
    if (!dictElement){
        return  FAIL;
    }
    printf("%s : %s\n", ((pDictElement)dictElement)->word, ((pDictElement)dictElement)->translation);
    return SUCCESS;
}
CompResult CompareWords ( pKey word1,  pKey word2){
    if (!word1 || !word2){
        return DIFFERENT;
    }
    if (!strcmp((char*)word1, (char*)word2)){
        return SAME;
    }
    return DIFFERENT;
}
pKey GetEntryKey (pElement dictElement){
    if (!dictElement){
        return NULL;
    }
    return  ((pDictElement)dictElement)->word;
}
void  DestroyEntry (pElement dictElement){
    if (!dictElement){
        return;
    }
    free(((pDictElement)dictElement)->word);
    free(((pDictElement)dictElement)->translation);
    free(dictElement);
}
pHash CreateDictionary(){
    return HashCreate (HASH_SIZE, HashWord, PrintEntry, CompareWords, GetEntryKey, DestroyEntry);
}
Result AddTranslation(pHash dict, char* word, char* translation){
    if (!dict || !word || !translation){
        return FAIL;
    }
    if(HashFind(dict,word)){
        return FAIL;
    }
    pDictElement newElement = (pDictElement)malloc(sizeof(DictElement));
    if (!newElement){
        return FAIL;
    }
    newElement->word = (char*)malloc(sizeof(char)*WORD_LENGTH);
    strcpy(newElement->word,word);
    newElement->translation =  (char*)malloc(sizeof(char)*WORD_LENGTH);
    strcpy(newElement->translation,translation);
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