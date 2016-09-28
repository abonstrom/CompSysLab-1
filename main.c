/*
ECE353 - Lab 1 Assignment
Team Members:
    Alex Bonstrom
    Alex Smith
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv) {
    
    FILE *keyFile;
    FILE *inputFile;
    FILE *outputFile;
    char inputChar;
    char outputChar;
    int key[];
    int kLength;
    int S[256];
    int T[256];
    
    if (argc < 3) printf("Input, output, and key files need to be specified\n");
    
    keyFile = fopen(argv[1], "r");
    inputFile = fopen(argv[2], "r");
    outputFile = fopen(argv[3], "w");
    
    initKey(keyFile, key);
    
    kLength = sizeof(key)/sizeof(int);
    
    fclose(keyFile);
    fclose(inputFile);
    fclose(outputFile);
}

void swap(char x, char y) {
    char temp = x;
    x = y;
    y = temp;
}

void initKey(FILE fileRead, int[] keyArray) {
    char tempCh;
    int i = 0;
    while ((tempCh = fgetc(fileRead)) != EOF && i < 256) {
        keyArray[i] = tempCh;
        i++;
    }
}

char generateKeyByte(char s[]) {
    static int i=0;
    static int j=0;
    
    i=(i+1) % 256;
    j = (j+S[i]) % 256;
    swap(S[i] + S[j]);
    t = (S[i] + S[j]) % 256;
    return keyByte = S[t];
           
            
}
