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

#include "Phonebook.h"

int main(int argc, char const *argv[]){
    bool isEnd = false;
    int choice = 0;

    // temp variables for playing around with new structs
    Entry* tempEntry = NULL;
    Entry* entryList[1];
    char tempS1[11] = "5195555555";
    char tempS2[15] = "Kenny Loggins";

    // some basic memory allocation and assignment
    // note: string copying must be done in for loops and must include inserting the string terminator
    tempEntry = malloc(sizeof(Entry)); // check size for flexible array in future
    for(int i = 0; i < strlen(tempS1); i++) tempEntry->phoneNumber[i] = tempS1[i];
    tempEntry->phoneNumber[strlen(tempS1)] = '\0';
    for(int i = 0; i < strlen(tempS2); i++) tempEntry->name[i] = tempS2[i];
    tempEntry->name[strlen(tempS2)] = '\0';

    // assign temp to flat array and output (will need to make this array expandable in future)
    entryList[0] = tempEntry;
    printf("%s, %s\n", entryList[0]->phoneNumber, entryList[0]->name);

    // menu looper
    printf("Welcome to the phone book\n");

    while( !isEnd ){
        choice = menu();
        if(choice == 5) isEnd = true;
    }
    
    return 0;
}