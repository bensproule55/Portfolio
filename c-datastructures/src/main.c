/*************************************
BENJAMIN SPROULE - ben.sproule55@gmail.com
C Data structures Phone book
main.c
Main function for phone book program.
*************************************/

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// main does not need access to the TRIE structure
#include "Phonebook.h"

int main(int argc, char const *argv[]){
    bool isEnd = false;
    int choice = 5; // default exit

    // temp variables for playing around with new structs
    Entry* tempEntry = NULL;
    Entry** entryList = NULL;
    char *tempS1, *tempS2;

    initializeHeads();

    // hardcoded strings for initialization / testing
    tempS1 = malloc(sizeof(char) * 11);
    strcpy(tempS1, "5195555555");
    tempS2 = malloc(sizeof(char) * 15);
    strcpy(tempS2, "Kenny Loggins");
    tempEntry = createEntry(tempS1, tempS2);
    free(tempS1);
    free(tempS2);

    // add to list
    addEntry(&entryList, tempEntry);

    // same as above
    tempS1 = malloc(sizeof(char) * 11);
    strcpy(tempS1, "5195558899");
    tempS2 = malloc(sizeof(char) * 15);
    strcpy(tempS2, "Stevie Wonder");
    tempEntry = createEntry(tempS1, tempS2);
    free(tempS1);
    free(tempS2);

    addEntry(&entryList, tempEntry);

    // menu looper
    printf("Welcome to the phone book\n");

    while( !isEnd ){
        choice = mainMenu();
        if(choice == 1){ // add new
            
        }
        else if(choice == 2){ // lookup

        }
        else if(choice == 3){ // update
            
        }
        else if(choice == 4){ // view all
            
        }
        else isEnd = true;
        //tempS1 = acceptNumber();
        //printf("%s", tempS1);
    }

    printEntryList(&entryList);
    printHeadsPre();

    clearEntryList(&entryList);
    clearHeads();
    
    return 0;
}