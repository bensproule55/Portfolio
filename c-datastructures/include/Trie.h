#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Represents a Trie Node 
typedef struct tNode{
    // Signifies completed word. Must not be NULL or empty.
    bool isEnd;

    // ID for lookup in a simple array. This will only contain a num >= 0 if isEnd is true
    // Set as -1 to indicate no entry
    // Set as -2 to indicate head of the TRIE structure
    int entryID;

    // List of children. Size may vary since using different alphabets (a-zA-Z vs. 0-9)
    // Allocate memory based on alphabet size during installation.
    // May be NULL, must not be empty. NULL indicates number not found.
    // Index number in this list will correspond to digits in phone number
    // - ie: children[4] will mean the node corresponds to the digit 4 (depends on implementation)
    // - ie: children[5] will mean the node corresponds to the letter 'e' (depends on implementation)
    struct tNode* children[];
} TrieNode;

/** Function to create a TRIE node object
 *@return trieNode object
 *@param isEnd: isEnd variable to set
 *@param entryID: entryID to set
 *@param alphabetSize: size of alphabet (10 for number, 26 for letters etc)
 *note: children will be initialized as NULL to indicate no children
**/
TrieNode *createTrieNode(bool isEnd, int entryID, int alphabetSize);

/** Function that adds an initialized trie node to children list in parent
 *@param parentNode: parent to accept node
 *@param newNode: node to be added
 *@param index: index to place child in children list
**/
void addChild(TrieNode *parentNode, TrieNode *newNode, int index);

/** Recursive function that adds a new trie node if it reaches the 
 * end of the list or transverses and removes a character
 *@param current: current place to add or check node
 *@param toAdd: string to check and/or add (decrement for recursion)
 *@param entryID: entryID to add if last character  
**/
void insertTrieNode(TrieNode *current, char *toAdd, int entryID, int alphabetSize);

#endif	