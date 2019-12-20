#include "hash.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct _Node *pNode;
typedef struct _Node{
    pElement curr_element;
    pNode next_node;
} Node;
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
    pHash new_Hash = (pHash)malloc(sizeof(Hash));
    if(!new_Hash){
        printf("Error Allocating Memory");
        return NULL;
    }
    new_Hash->hash_func = hashFunc;
    new_Hash->print_func = printFunc;
    new_Hash->compare_func = compareFunc;
    new_Hash->get_key_func = getKeyFunc;
    new_Hash->destroy_func = destroyFunc;
    new_Hash->hash_arr = (pNode *)malloc(sizeof(pNode)*arrSize);
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
Result HashAdd (pHash HashTable, pElement Elem){
    if(!HashTable || !Elem){
        return FAIL;
    }
    if(HashFind(HashTable,HashTable->get_key_func(Elem))){
        return FAIL;
    }
    int array_index=HashTable->hash_func((HashTable->get_key_func(Elem)), HashTable->arr_size);
    pNode new_node=(pNode)malloc(sizeof(Node));
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
    /*pNode found_node = HashFindNode(HashTable, key);
    if (!found_node){
        return  FAIL;
    }
    pNode current=found_node;
    pNode *points_to_current = &(current);//pointer to the current pointer
    *points_to_current = current->next_node;
    HashTable->destroy_func(found_node->curr_element);
    free(found_node);
    return SUCCESS;*/
    pNode current = HashTable->hash_arr[HashTable->hash_func(key,HashTable->arr_size)];
    pNode *points_to_current = &(HashTable->hash_arr[HashTable->hash_func(key,HashTable->arr_size)]);//pointer to the current pointer (the address of curr)
    while (current != NULL) {
        if (HashTable->compare_func(HashTable->get_key_func(current->curr_element),key)==SAME) {
            *points_to_current = current->next_node;
            HashTable->destroy_func(current->curr_element);
            free(current);
            return SUCCESS;
        }
        points_to_current=&(current->next_node);
        current = current->next_node;
    }
    return FAIL;
}
Result HashPrint (pHash HashTable){
    if(!HashTable){
        return FAIL;
    }
    pNode curr_list;
    for (int i=0; i<HashTable->arr_size; i++){
        curr_list=HashTable->hash_arr[i];
        while(curr_list){
            HashTable->print_func(curr_list->curr_element);
            curr_list=curr_list->next_node;
        }
    }
    return SUCCESS;
}
Result HashDestroy (pHash HashTable){
    if(!HashTable){
        return FAIL;
    }
    pNode curr_list;
    pNode next_list_node;
    for (int i=0; i<HashTable->arr_size; i++){
        curr_list=HashTable->hash_arr[i];
        while(curr_list){
            next_list_node=curr_list->next_node;
            if(!HashRemove(HashTable,HashTable->get_key_func(curr_list->curr_element))){
                return FAIL;
            }
            curr_list=next_list_node;
        }
    }
    free(HashTable->hash_arr);
    free(HashTable);

    return SUCCESS;
}