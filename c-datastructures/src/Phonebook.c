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
    if (strlen(numTrimmed) != 11) return false;
    else if(containsNonNum(numTrimmed)) return false;
    else return true;
}

// remove spaces and dashes from telephone number
char * trimNumber(char *number){
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
char * acceptNumber(){
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
char * acceptName(){
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
    int choice = 4; 

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
        printf("Please enter a number between 1-4: ");
        scanf("%d", &choice);
    }

    // ensure buffer is clear for more input because of scanf dropping chars
    while ((getchar()) != '\n');

    return choice;
}