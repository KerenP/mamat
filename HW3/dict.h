#ifndef _DICT_H_
#define _DICT_H_

#include "hash.h"
typedef struct _DictElement *pDictElement;
int HashWord(char* word, int hashTableSize);
Result PrintEntry (pDictElement dictElement);
CompResult CompareWords (char* word1, char* word2);
char* GetEntryKey (pDictElement dictElement);
void  DestroyEntry (pDictElement element);
pHash CreateDictionary();
Result AddTranslation(pHash dict , pDictElement dictElement);
Result Translate (pHash dict);//TODO: change to void?
Result DeleteTranslation (pHash dict, char* word);
Result PrintDictionary(pHash dict);
#endif
