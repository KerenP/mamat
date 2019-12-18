#ifndef _DICT_H_
#define _DICT_H_
#include "hash.h"
#define WORD_LENGTH 26
typedef struct _DictElement *pDictElement;
int HashWord(pKey word, int hashTableSize);
Result PrintEntry (pElement dictElement);
CompResult CompareWords (pKey word1, pKey word2);
pKey GetEntryKey (pElement dictElement);
void  DestroyEntry (pElement dictElement);
pHash CreateDictionary();
Result AddTranslation(pHash dict , char* word, char* translation);
Result Translate (pHash dict, char* word);//TODO: change to void?
Result DeleteTranslation (pHash dict, char* word);
Result PrintDictionary(pHash dict);
#endif
