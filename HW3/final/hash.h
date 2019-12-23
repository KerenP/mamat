#ifndef _HASH_H_
#define _HASH_H_

typedef enum {FAIL = 0, SUCCESS} Result;
typedef enum {SAME = 0, DIFFERENT} CompResult;

typedef struct _Hash *pHash;


typedef void* pElement;
typedef void* pKey;

typedef int (*HashFunc) (pKey key, int size);
typedef Result (*PrintFunc) (pElement element);
typedef CompResult (*CompareFunc) (pKey key1, pKey key2);
typedef pKey (*GetKeyFunc) (pElement element);
typedef void (*DestroyFunc)(pElement element);

/*******************************************************************************************
function name: HashCreate

description:
Create hash table in given size (arr_size) initialized with hash, print, compare, get key
and destroy functions

parameters:
arrSize - size of hash array.
hashFunc - hush function.
printFunc - print function.
compareFunc - compare function.
getKeyFunc - get key function.
destroyFunc - destroy function.

return values:
pHash - pointer to hash table.
*******************************************************************************************/
pHash HashCreate (int arrSize, HashFunc hashFunc, PrintFunc printFunc, CompareFunc compareFunc, GetKeyFunc getKeyFunc,
        DestroyFunc destroyFunc);
/*******************************************************************************************
function name: HashAdd

description:
Add node with given element to the hash table

parameters:
HashTable - pointer to hashtable.
Elem - pointer to element.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
Result HashAdd (pHash HashTable, pElement Elem);
/*******************************************************************************************
function name: HashFind

description:
Use HashFindNode function and return the element matching key

parameters:
HashTable - pointer to hashtable.
key - pointer to key.

return values:
pElement - pointer to element.
*******************************************************************************************/
pElement HashFind (pHash HashTable, pKey key);
/*******************************************************************************************
function name: HashRemove

description:
Find wanted node using hashFunc and delete it.

parameters:
HashTable - pointer to hashtable.
key - pointer to key.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
Result HashRemove (pHash HashTable, pKey key);
/*******************************************************************************************
function name: HashPrint

description:
Print hash table content.

parameters:
HashTable - pointer to hashtable.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
Result HashPrint (pHash HashTable);
/*******************************************************************************************
function name: HashDestroy

description:
Delete hash table.

parameters:
HashTable - pointer to hashtable.

return values:
Result parameter - FAIL/SUCCESS.
*******************************************************************************************/
Result HashDestroy (pHash HashTable);
#endif
