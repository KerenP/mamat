#ifndef _DICT_H_
#define _DICT_H_
#include "hash.h"
#define WORD_LENGTH 26
typedef struct _DictElement *pDictElement;
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
int HashWord(pKey word, int hashTableSize);
/*******************************************************************************************
function name: PrintEntry

description:
Print content of given element (word+translation).

parameters:
dictElement - pointer to element.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
Result PrintEntry (pElement dictElement);
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
CompResult CompareWords (pKey word1, pKey word2);
/*******************************************************************************************
function name: GetEntryKey

description:
Get key of given element.

parameters:
dictElement - pointer to element in hash table.

return values:
word - pointer to key (word).
*******************************************************************************************/
pKey GetEntryKey (pElement dictElement);
/*******************************************************************************************
function name: DestroyEntry

description:
Delete given element.

parameters:
dictElement - pointer to element in hash table.

return values:
NONE.
*******************************************************************************************/
void  DestroyEntry (pElement dictElement);
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
pHash CreateDictionary();
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
Result AddTranslation(pHash dict , char* word, char* translation);
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
Result Translate (pHash dict, char* word);
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
Result DeleteTranslation (pHash dict, char* word);
/*******************************************************************************************
function name: PrintDictionary

description:
Print hash table content.

parameters:
dict - pointer to hash table.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
Result PrintDictionary(pHash dict);
#endif
