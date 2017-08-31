/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include "dictionary.h"
#include <ctype.h>

#define ALPHABET_SIZE 26


int dicSize = 0;
// Trie node
typedef struct TrieNode{
     struct TrieNode *children[ ALPHABET_SIZE + 1 ];
     // isLeaf is true if the node represents end of a word
     bool word;
}node;

struct TrieNode *root = NULL;//the root


node *createNode(void){
    return (node *) malloc(sizeof(node));
}

void freeNode(node *nextNode){
    for(int i = 0; i < ALPHABET_SIZE + 1; i++ ){
        if(nextNode->children[i] != NULL){
            freeNode(nextNode->children[i]);
        }
    }
    free(nextNode);
}
/**********************************************************************************
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    //make sure all char convert to lower
    int length = strlen(word);
    char check[length + 1];
    strcpy(check, word);

    for(int i = 0; i < length; i++){
        if(check[i] >= 65 && check[i] <= 90){
            check[i] = check[i] + 32;
        }
    }

    //*******************************************************
    node *currentNode = root;
    int current = 0;
    int i = 0;

    for(i = 0; i < length; i++){
        current = check[i];
        if(current == '\'')
            current = ALPHABET_SIZE + 97;
        current = current - 97;

        if(currentNode->children[current] == NULL){
            return false;
        }else{
            currentNode = currentNode->children[current];
        }
    }

    if(currentNode->word){
        return true;
    }else{
        return false;
    }

}



/*************************************************************************
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    //open the dic
    FILE *dic = fopen(dictionary, "r");
    //check if can open the dic
    if(dic == NULL){
        printf("Can not open dictionary.\n");
        return false;
    }
//****************************************
    //set the root
    root = createNode();
    //check whether successful
    if (root == NULL){
        printf("error in load(): root pointer contains NULL");
        return false;
    }
    //initialize
    for (int i = 0; i < 27; i++){
        root->children[i] = NULL;
    }
//*************************************************************************
    int current = 0;
    node *currentNode = root;

    while(feof(dic) == 0){
        char word[LENGTH + 1] = {};
        fscanf(dic, "%s", word);

        currentNode = root;
        dicSize = dicSize + 1;

        for(int i = 0; i < strlen(word);i++){
            current = word[i];
            if(current == '\''){
                current = ALPHABET_SIZE + 97;
            }//the last element of the children array
            current = current - 97;

            if(currentNode->children[current] == NULL){
                currentNode->children[current] = createNode();
                //check wether there is enough memory

                //initialize
                currentNode->children[current]->word = false;
                for (int i = 0; i < 27; i++){
                    currentNode->children[current]->children[i] = NULL;
                }

                currentNode = currentNode->children[current];

                }
                else{
                currentNode = currentNode->children[current];
                }

        }

        currentNode->word = true;

    }

    fclose(dic);
    return true;
}
    // while(current != EOF){
    //     current = fgetc(dic);//start to read the dic

    //     if((current != '\n') && (current != EOF)){

    //         if(current == '\''){
    //             current = ALPHABET_SIZE + 97;
    //         }//the last element of the children array
    //         current = current - 97;


    //         if(currentNode->children[current] == NULL){

    //             currentNode->children[current] = createNode();
    //             //check wether there is enough memory
    //             if (currentNode->children[current] == NULL){
    //                 printf("error in load(): create new node unsuccessful");
    //                 return false;
    //             }
    //             //initialize
    //             for (int i = 0; i < 27; i++){
    //                 currentNode->children[current]->children[i] = NULL;
    //             }

    //             currentNode = currentNode->children[current];
    //         }else{
    //             currentNode = currentNode->children[current];
    //         }
    //     }

    //     //if the word end and start a new line
    //     if(current == '\n'){
    //         currentNode->word = true;
    //         //back to the beginning
    //         currentNode = root;
    //         dicSize += 1;
    //     }
    // }


/******************************************************************************
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    dicSize = dicSize - 1;
    return dicSize;//if the loaded size is 0 it will return 0
}

/*****************************************************************************
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    freeNode(root);
    return true;
}




    // while(current != '\0'){
    //     current = check[i];

    //     if( (current == '\'') || (current >= 97 && current <= 122) ){
    //         if(current == '\''){
    //             current = ALPHABET_SIZE + 97;
    //         }

    //         current = current - 97;
    //         if(currentNode->children[current] == NULL){
    //             return false;
    //         }else{
    //             currentNode = currentNode->children[current];
    //         }
    //     }
    //     i = i + 1;
    // }

    // return currentNode->word;