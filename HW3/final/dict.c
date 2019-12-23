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
/*******************************************************************************************
function name: HashWord

description:
The hash function, return index for given word (key).

parameters:
word - pointer to string.
hashTableSize - size of hash table array.

return values:
wordIndex - index of word in the hash table.
*******************************************************************************************/
int HashWord(pKey word, int hashTableSize){
    if (!word || hashTableSize<0){
        return -1;
    }
    char *charWord=(char*)word;
    int wordIndex = ((int) (charWord[0]-'a')*26+(int)strlen(word))%hashTableSize;
    return wordIndex;
}
/*******************************************************************************************
function name: PrintEntry

description:
Print content of given element (word+translation).

parameters:
dictElement - pointer to element.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
Result PrintEntry (pElement dictElement){
    if (!dictElement){
        return  FAIL;
    }
    printf("%s : %s\n", ((pDictElement)dictElement)->word, ((pDictElement)dictElement)->translation);
    return SUCCESS;
}
/*******************************************************************************************
function name: CompareWords

description:
Compare two given strings (word1, word2).

parameters:
word1 - pointer to string.
word2 - pointer to string.

return values:
CompResult parameter - DIFFERENT/SAME.
*******************************************************************************************/
CompResult CompareWords ( pKey word1,  pKey word2){
    if (!word1 || !word2){
        return DIFFERENT;
    }
    if (!strcmp((char*)word1, (char*)word2)){
        return SAME;
    }
    return DIFFERENT;
}
/*******************************************************************************************
function name: GetEntryKey

description:
Get key of given element.

parameters:
dictElement - pointer to element in hash table.

return values:
word - pointer to key (word).
*******************************************************************************************/
pKey GetEntryKey (pElement dictElement){
    if (!dictElement){
        return NULL;
    }
    return  ((pDictElement)dictElement)->word;
}
/*******************************************************************************************
function name: DestroyEntry

description:
Delete given element.

parameters:
dictElement - pointer to element in hash table.

return values:
NONE.
*******************************************************************************************/
void  DestroyEntry (pElement dictElement){
    if (!dictElement){
        return;
    }
    free(((pDictElement)dictElement)->word);
    ((pDictElement)dictElement)->word=NULL;
    free(((pDictElement)dictElement)->translation);
    ((pDictElement)dictElement)->translation=NULL;
    free(dictElement);
    dictElement=NULL;
}
/*******************************************************************************************
function name: CreateDictionary

description:
Create new hash table initialized to HASH_SIZE with functions: HashWord, PrintEntry,
CompareWords, GetEntryKey and DestroyEntry.

parameters:
NONE.

return values:
return value of HashCreate, pointer to hash table.
*******************************************************************************************/
pHash CreateDictionary(){
    return HashCreate (HASH_SIZE, HashWord, PrintEntry, CompareWords, GetEntryKey, DestroyEntry);
}
/*******************************************************************************************
function name: AddTranslation

description:
Create new element in hash table, containing two strings (word+translation).

parameters:
dict - pointer to hash table.
word - pointer to string.
translation - pointer to string.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
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
/*******************************************************************************************
function name: Translate

description:
Given specific word, find its element and return 'translation' string from this element.

parameters:
dict - pointer to hash table.
word - pointer to string.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
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
/*******************************************************************************************
function name: DeleteTranslation

description:
Delete element containing given word and its translation.

parameters:
dict - pointer to hash table.
word - pointer to string.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
Result DeleteTranslation (pHash dict, char* word){
    if (!dict || !word){
        return FAIL;
    }
    return HashRemove(dict, word);
}
/*******************************************************************************************
function name: PrintDictionary

description:
Print hash table content.

parameters:
dict - pointer to hash table.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
Result PrintDictionary(pHash dict){
    if (!dict){
        return FAIL;
    }
    printf("Dictionary Contents\n");
    return HashPrint(dict);
}