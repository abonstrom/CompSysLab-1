/*
ECE353 - Lab 1 Assignment
Team Members:
    Alex Bonstrom
    Alex Smith
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void swap(char *x, char *y);
char generateKeyByte(char s[]);
void encryptData(FILE *input, FILE *output);

char S[256];
char T[256];
char key[256];

int main(int argc, char *argv[]) {
    
    FILE *keyFile;
    FILE *inputFile;
    FILE *outputFile;
   
    //assertion to make sure that there are enough inputs on the command line
    assert (argc == 3);
    
    keyFile = fopen(argv[1], "r");
    inputFile = fopen(argv[2], "r");
    outputFile = fopen(argv[3], "w");
    
    int kLength = 0;
    int inputChar;
    //checks next char in keyFile and if it is not EOF or over 256 then add 
    //one to length 
    while((inputChar = fgetc(keyFile)) != EOF && kLength<256){
        key[kLength] = inputChar;
        kLength++;
    }   
    
    int i = 0;
    
    while (i < 256){
        S[i] = i;
        T[i] = key[i % kLength];
        i++;
    }

    int j = 0;
    
    for (i = 0; i < 256; i++) {
        j = (j + S[i] + T[i]) % 256;
        swap(&S[i], &S[j]);
    }
    
    encryptData(inputFile, outputFile);
    
    //close all the file streams
    fclose(keyFile);
    fclose(inputFile);
    fclose(outputFile);
}

void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

char generateKeyByte(char s[]) {
    static int i=0;
    static int j=0;
    char keyByte;
    
    i = (i+1) % 256;
    j = (j+S[i]) % 256;
    swap(&S[i], &S[j]);
    int t = (S[i] + S[j]) % 256;
    return keyByte = S[t];
}

//method to encrypt the data using the newly created S[] array
void encryptData(FILE *input, FILE *output){
    char inChar;
    char outChar;
    //variable that will hold the next value in the keyStream, will be ex-ored 
    //with the input character to create the encrypted character
    char keyByte;
    while ((inChar = fgetc(input)) != EOF) {
        //generates the next keyByte from the keyStream
        keyByte = generateKeyByte(S);
        outChar = keyByte ^ inChar;
        //adds the new encrypted char to the output file
        fputc(outChar, output);
    }
}
