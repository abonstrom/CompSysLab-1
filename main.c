/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: alexb
 *
 * Created on September 22, 2016, 4:37 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
 * 
 */
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

