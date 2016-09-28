/*
ECE353 - Lab 1 Assignment
Team Members:
    Alex Bonstrom
    Alex Smith
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char** argv) {
    
    FILE *ifp;
    FILE *ofp;
    char inputChar;
    char outputChar;
    char prevChar;
    int i;

    if (argc < 3) printf("Input and output files need to be specified\n");
    ifp = fopen(argv[1], "r");
    ofp = fopen(argv[2], "w");

    assert(ifp != NULL);
    assert(ofp != NULL);


     while ((inputChar = fgetc(ifp))!=EOF) {
       fputc(inputChar, ofp);
     }
    fclose(ifp);
    fclose(ofp);

}

