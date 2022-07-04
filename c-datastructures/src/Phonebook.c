/*************************************
BENJAMIN SPROULE - ben.sproule55@gmail.com
C Data structures Phone book
Phonebook.c
This file contains the functions around 
the storage and implementation of the 
phone book struct.
*************************************/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "Trie.h"
#include "Phonebook.h"

const int NUM_ALPHABET_SIZE = 10;
const int LETTER_ALPHABET_SIZE = 27; // includes space
TrieNode *numberTrieHead;
TrieNode *nameTrieHead;


// initialize head to size of node plus size of node * alphabet size
void initializeHeads(){
    numberTrieHead = createTrieNode(false, -2, NUM_ALPHABET_SIZE);
    nameTrieHead = createTrieNode(false, -2, LETTER_ALPHABET_SIZE);
}

// clear and free trie object
void clearHeads(){
    freeTrie(numberTrieHead, NUM_ALPHABET_SIZE);
}

// print trie in pre order
void printHeadsPre(){
    printf("Number TRIE: \n");
    printTriePre(numberTrieHead, NUM_ALPHABET_SIZE);
    printf("Name TRIE: \n");
    printTriePre(nameTrieHead, LETTER_ALPHABET_SIZE);
}

// print trie in post order
void printHeadsPost(){
    printf("Number TRIE: \n");
    printTriePost(numberTrieHead, NUM_ALPHABET_SIZE);
    printf("Name TRIE: \n");
    printTriePost(nameTrieHead, LETTER_ALPHABET_SIZE);
}

// add entry to flat entryList, entryList[length+1] will always = NULL
void addEntry(Entry ***entryList, Entry *tempEntry){
    int k = 0, j = 0;
    char *nameConversion = malloc(strlen(tempEntry->name) * (sizeof(char) + 1));

    // if list is not empty, reallocate memory
    if(*entryList != NULL){
        *entryList = realloc(*entryList, sizeof(*entryList) + sizeof(tempEntry) + sizeof(NULL));
        while((*entryList)[k] != NULL) k++;
        (*entryList)[k] = tempEntry;
        (*entryList)[k+1] = NULL;
    } 
    else{ // list empty
        *entryList = malloc(sizeof(tempEntry) + sizeof(NULL));
        (*entryList)[0] = tempEntry;
        (*entryList)[1] = NULL;
    }

    // insert into trie with k as the entryID
    insertTrieNode(numberTrieHead, tempEntry->phoneNumber, k, NUM_ALPHABET_SIZE);

    // need to convert chars to indexes for trie function, includes lowercase conversion
    while (j < strlen(tempEntry->name)){
        if(tempEntry->name[j] == ' ') nameConversion[j] = (tempEntry->name[j] + 16); // space
        else if(tempEntry->name[j] <= 90) nameConversion[j] = (tempEntry->name[j] - 16); // upper case
        else nameConversion[j] = (tempEntry->name[j] - 48); // lowercase
        j++;
    }
    nameConversion[j] = '\0'; // null char to terminate string

    insertTrieNode(nameTrieHead, nameConversion, k, LETTER_ALPHABET_SIZE);

    free(nameConversion);
}

// check the length of the list, useful for getting most recent element in list
// note: this functionality could be fit into addEntry to save efficiency,
// but that code would not be very readable
int getLength(Entry ***entryList){
    int k = 0;

    // if list is empty, k will return 0
    if(*entryList != NULL){
        while((*entryList)[k] != NULL) k++;
        k++; // need to add one from the last valid index for length
    } 

    return k;
}


// debugging print function
void printEntryList(Entry ***entryList){
    if(*entryList != NULL){
        for(int i = 0; (*entryList)[i] != NULL; i++) printEntry((*entryList)[i]);
    }
}

// remove entry from entryList by entry object *slow*
void removeEntryByEntry(Entry ***entryList, Entry *tempEntry);

// remove entry from entryList by id
void removeEntryByID(Entry ***entryList, int id);

// clears and frees all entries
void clearEntryList(Entry ***entryList){
    if(*entryList != NULL){
        for(int i = 0; (*entryList)[i] != NULL; i++){
            freeEntry((*entryList)[i]);
        }
        free(*entryList);
    }
}

// function to create a new entry struct
Entry *createEntry(char *number, char *name){
    Entry * retEntry = malloc(sizeof(char) * (NUM_ALPHABET_SIZE+1) + sizeof(strlen(name)) * (sizeof(char) + 1));

    // make sure to add null char
    for(int i=0; i<NUM_ALPHABET_SIZE+1; i++) retEntry->phoneNumber[i] = number[i];
    retEntry->phoneNumber[NUM_ALPHABET_SIZE+1] = '\0';

    // adaptive adding based on size of name
    for(int i=0; i<strlen(name); i++){
        retEntry->name[i] = name[i];
        if(i == strlen(name)-1) retEntry->name[i+1] = '\0';
    }

    return retEntry;
}

// free entry object
void freeEntry(Entry *tempEntry){
    // note: do not need to free strings inside because they are
    // static arrs that are initialized in the Entry malloc
    free(tempEntry);
}

// print entry for debugging
void printEntry(Entry *entryToPrint){
    printf("%s, %s\n", entryToPrint->name, entryToPrint->phoneNumber);
}

// check if string contains non-num chars
bool containsNonNum(char *number){
    // loop through all string chars
    for(int i = 0; i < strlen(number)-1; i++){
        // character comparison, not mathematical
        if(number[i] < '0' || number[i] > '9') return true;
    }
    return false; // false if did not return during for loop
}

// check string for valid formats
// acceptable: xxx-xxx-xxxx, xxxxxxxxxx, xxx xxx xxxx
bool isValidNumber(char *number){
    // initialize and trim new number
    char * numTrimmed = trimNumber(number);

    // check if length is bad or contains non-num chars
    if (strlen(numTrimmed) != NUM_ALPHABET_SIZE+1) return false;
    else if(containsNonNum(numTrimmed)) return false;
    else return true;
}

// remove spaces and dashes from telephone number
char *trimNumber(char *number){
    int k = 0;
    char * numTrimmed = malloc(sizeof(char) * strlen(number) + 1);

    // loop through normal string, keep track of place in updated with k
    for(int i = 0; i<strlen(number); i++){
        if(number[i] != ' ' && number[i] != '-'){
            numTrimmed[k] = number[i];
            k++;
        }
    }

    // string terminator to change length of new string
    numTrimmed[k] = '\0';
    return numTrimmed;
}

// prompt and accept valid phone number
// uses error checking function isValidNumber
char *acceptNumber(){
    bool isValid = false; 
    // using max len 150
    char * number = malloc(sizeof(char) * 150);

    while (!isValid){
        printf("Please enter a phone number: ");
        fgets (number, 150, stdin);
        isValid = isValidNumber(number);
    }

    return number;
}

// prompt and accept any name from user
char *acceptName(){
    // using max len 150
    char * name = malloc(sizeof(char) * 150);

    // get name, fgets allow getting spaces
    printf("Please enter a name: ");
    fgets (name, 150, stdin);

    return name;
}

// simple menu to select what the user wants to do
int mainMenu(){
    // default choice of exit if bad input
    int choice = 5; 

    // options, make these into enum?
    printf("1. Add new entry\n"); // single or from csv
    printf("2. Lookup entry\n"); // look by name or number
    printf("3. Update contact\n"); // search by name or number
    printf("4. View all entries\n"); // get in alphabetical?
    printf("5. Exit program\n");
    printf("Enter your choice: ");

    // ask for choice and then loop until it is valid
    scanf("%d", &choice);
    while(choice > 5 || choice < 0){
        printf("Please enter a number between 1-5: ");
        scanf("%d", &choice);
    }

    // ensure buffer is clear for more input because of scanf dropping chars
    while ((getchar()) != '\n');

    return choice;
}