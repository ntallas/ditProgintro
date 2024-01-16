#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DNA_LENGTH 100000

void filterInvalidCharacters(char *sequence,int length);
void sequenceFinder(char *dnaOne, char *dnaTwo, int lengthOne, int lengthTwo);

int main(int argc, char**argv){

    if(argc != 3 ){
        fprintf(stderr, "Give me two files");
        exit(1);
    }

    char *dnaOneName = argv[1];
    char *dnaTwoName = argv[2];


    FILE *dnaOneFile = fopen(dnaOneName,"r");
    FILE *dnaTwoFile = fopen(dnaTwoName,"r");

    char * dnaOne = malloc(MAX_DNA_LENGTH);
    char * dnaTwo = malloc(MAX_DNA_LENGTH);

//     int read1 = fscanf(dnaOneFile,"%s", dnaOne);
//     int read2 = fscanf(dnaTwoFile,"%s", dnaTwo);

    int readOne = 0;
    while(1){
        char character = fgetc(dnaOneFile);
        if(character == EOF){
            break;
        }
        dnaOne[readOne] = character;
        readOne++;
    }

    int readTwo = 0;
    while(1){
        char character = fgetc(dnaTwoFile);
        if(character == EOF){
            break;
        }
        dnaTwo[readTwo] = character;
        readTwo++;
    }

    // fprintf(stderr,"%s \n",dnaOne);
    // fprintf(stderr,"%s \n",dnaTwo);

    int dnaOneLength = strlen(dnaOne);
    int dnaTwoLength = strlen(dnaTwo);

    fprintf(stderr,"dnaOne length = %d\n", dnaOneLength); 
    fprintf(stderr,"dnaTwo length = %d\n", dnaTwoLength); 

    filterInvalidCharacters(dnaOne, dnaOneLength);
    filterInvalidCharacters(dnaTwo, dnaTwoLength);


    // fprintf(stderr,"%s \n",dnaOne);
    // fprintf(stderr,"%s \n",dnaTwo);

    int dnaOneLengthFiltered = strlen(dnaOne);
    int dnaTwoLengthFiltered = strlen(dnaTwo);


    sequenceFinder(dnaOne,dnaTwo,dnaOneLengthFiltered,dnaTwoLengthFiltered);
}

void filterInvalidCharacters(char *sequence,int length) {

    int index = 0;
    for (int i = 0; i < length; i++) {
        if (sequence[i] == 'A' || sequence[i] == 'G' || sequence[i] == 'T' || sequence[i] == 'C') {
            sequence[index++] = sequence[i];
        }
    }

    sequence[index] = '\0';  // Null-terminate the filtered string.
}

void sequenceFinder(char *dnaOne, char *dnaTwo, int lengthOne, int lengthTwo) {
    int maxLength = 0; // To store the length of the longest common dna sequence
    int index = 0; // To store the ending index of the longest common dna sequence

    //int Array[lengthOne + 1][lengthTwo + 1];

    //A 2D array to store the length of common dna sequences
    int** Array = (int**)malloc((lengthOne + 1) * sizeof(int*));
    if (Array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); 
    }
    for (int i = 0; i <= lengthOne; ++i) {
        Array[i] = (int*)malloc((lengthTwo + 1) * sizeof(int));
        if (Array[i] == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(1);
        }
    }

    // Build the Array[][] table
    for (int i = 0; i <= lengthOne; i++) {
        for (int j = 0; j <= lengthTwo; j++) {
            if (i == 0 || j == 0)
                Array[i][j] = 0; // If either string is empty, there is no common dna sequence
            else if (dnaOne[i - 1] == dnaTwo[j - 1]) {
                Array[i][j] = Array[i - 1][j - 1] + 1;
                if (maxLength < Array[i][j]) {
                    maxLength = Array[i][j]; // Update maximumLength if the current length is greater
                    index = i - 1; // Update the ending index of the longest DNA sequence
                }
            } else {
                Array[i][j] = 0; // If characters do not match, reset the length to 0
            }
        }
    }

    // Print the longest common dnaSequence
    FILE *dnaOutputFile = fopen("output.dna","w");

    if (maxLength > 0) {
        for (int i = index - maxLength + 1; i <= index; i++) {
            fprintf(dnaOutputFile,"%c", dnaOne[i]);
        }
        fprintf(dnaOutputFile,"\n");

    } else {
        fprintf(dnaOutputFile,"\n");
        fprintf(stderr,"No Common dna sequence\n");
    }
}
