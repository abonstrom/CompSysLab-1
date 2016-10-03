/*
ECE353 - Lab 1 Assignment
Team Members:
    Alex Bonstrom
    Alex Smith
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Initialize Functions
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
    assert (argc == 4);
    
    keyFile = fopen(argv[1], "r");
    inputFile = fopen(argv[2], "r");
    outputFile = fopen(argv[3], "w");
    
    int kLength = 0;
    int inputChar;
    //checks next char in keyFile and if it is not EOF or over 256 then add 
    //one to length and insert char into key[] 
    while((inputChar = fgetc(keyFile)) != EOF && kLength<256){
        key[kLength] = inputChar;
        kLength++;
    }   
    //Loop through and fill T[] fully with key[] even if key[] is not completely
    //full
    int i = 0;
    while (i < 256){
        S[i] = i; //adds placeholder for elements in S[]
        T[i] = key[i % kLength];
        i++;
    }
    
    int j = 0;
    for (i = 0; i < 256; i++) {  
        j = (j + S[i] + T[i]) % 256;//Scrambles value of full key T[] and inputs
        swap(&S[i], &S[j]); //adds extra layer of complexity
    }
    
    encryptData(inputFile, outputFile);
    
    //close all the file streams
    fclose(keyFile);
    fclose(inputFile);
    fclose(outputFile);
}

void swap(char *x, char *y) { //swaps values at end of pointers IE. array values
    char temp = *x;
    *x = *y;
    *y = temp;
}

char generateKeyByte(char s[]) {//Generates byte to be xor with output char
    static int i=0;//static int i,j hold value even after initial return.
    static int j=0;
    char keyByte;
    
    i = (i+1) % 256;
    j = (j+S[i]) % 256; //uses S[] which is mixed T[] which is mixed key[]
    swap(&S[i], &S[j]);//swap pointer to S[i] and S[j]
    int t = (S[i] + S[j]) % 256;
    return keyByte = S[t];
}

//method to encrypt the data using the newly created S[] array
void encryptData(FILE *input, FILE *output){
    char inChar;
    char outChar;
    //variable that will hold the next value in the keyStream, will be xored 
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
