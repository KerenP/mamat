#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node{
    pElement curr_element;
    struct _Node* next_node;
} Node, *pNode;
typedef struct _Hash{
    pNode *hash_arr;
    int arr_size;
    //function pointers:
    HashFunc hash_func;
    PrintFunc print_func;
    CompareFunc compare_func;
    GetKeyFunc get_key_func;
    DestroyFunc destroy_func;
} Hash;
pNode HashFindNode(pHash HashTable, pKey key){
    if(!HashTable || !key){
        return NULL;
    }
    pNode curr_search_list=HashTable->hash_arr[HashTable->hash_func(key,HashTable->arr_size)];
    while(curr_search_list){
        if (HashTable->compare_func(HashTable->get_key_func(curr_search_list->curr_element),key)==SAME){
            return curr_search_list;
        }
        curr_search_list=curr_search_list->next_node;
    }
    return NULL;
}
pHash HashCreate (int arrSize, HashFunc hashFunc, PrintFunc printFunc, CompareFunc compareFunc, GetKeyFunc getKeyFunc,
                  DestroyFunc destroyFunc){
    if(arrSize<0 || !hashFunc || !printFunc || !compareFunc || !getKeyFunc){
        return  NULL;
    }
    pHash new_Hash = (pHash)malloc(sizeof(Hash));//TODO: FREE new_hash
    if(!new_Hash){
        printf("Error Allocating Memory");
        return NULL;
    }
    new_Hash->hash_func = hashFunc;
    new_Hash->print_func = printFunc;
    new_Hash->compare_func = compareFunc;
    new_Hash->get_key_func = getKeyFunc;
    new_Hash->destroy_func = destroyFunc;
    new_Hash->hash_arr = (pNode *)malloc(sizeof(pNode)*arrSize);//TODO: FREE hash_arr
   new_Hash->arr_size = arrSize;
    if(!new_Hash->hash_arr){
        printf("Error Allocating Memory");
        return NULL;
    }
    for (int i=0; i<arrSize; i++){
        new_Hash->hash_arr[i] = NULL;
    }
    return new_Hash;
}
Result HashAdd (pHash HashTable, pElement Elem){ //TODO:if the element already exists return FAIL
    if(!HashTable || !Elem){
        return FAIL;
    }
    int array_index=HashTable->hash_func((HashTable->get_key_func(Elem)), HashTable->arr_size);
    pNode new_node=(pNode)malloc(sizeof(Node)); //TODO: FREE NODES
    new_node->next_node=HashTable->hash_arr[array_index];
    new_node->curr_element=Elem;
    HashTable->hash_arr[array_index]=new_node;
    return  SUCCESS;
}
pElement HashFind (pHash HashTable, pKey key){
    if(!HashTable || !key){
        return NULL;
    }
    pNode found_node = HashFindNode(HashTable, key);
    if (found_node){
        return  found_node->curr_element;
    }
    return NULL;
}
Result HashRemove (pHash HashTable, pKey key){
    if(!HashTable || !key ){
        return FAIL;
    }
    pNode found_node = HashFindNode(HashTable, key);
    if (!found_node){
        return  FAIL;
    }
    pNode *points_to_current = &(found_node);//pointer to the current pointer
    *points_to_current = found_node->next_node;
    HashTable->destroy_func(found_node->curr_element);
    free(found_node);
    return SUCCESS;
}
Result HashPrint (pHash HashTable){
    if(!HashTable){
        return FAIL;
    }
    for (int i=0; i<HashTable->arr_size; i++){

    }
}