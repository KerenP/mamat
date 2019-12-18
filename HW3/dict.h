#ifndef _DICT_H_
#define _DICT_H_

#include "hash.h"
typedef struct _DictElement *pDictElement;
int HashWord(char* word, int hashTableSize);
Result PrintEntry (pDictElement dictElement);
CompResult CompareWords (char* word1, char* word2);
char* GetEntryKey (pDictElement dictElement);
void  DestroyEntry (pDictElement dictElement);
pHash CreateDictionary();
Result AddTranslation(pHash dict , char* word, char* translation);
Result Translate (pHash dict, char* word);//TODO: change to void?
Result DeleteTranslation (pHash dict, char* word);
Result PrintDictionary(pHash dict);
#endif
