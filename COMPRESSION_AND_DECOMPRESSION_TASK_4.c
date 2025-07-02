#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateFile(const char *fileName) {
    FILE *filePtr = fopen(fileName, "w");
    if (!filePtr) {
        printf("Error: Unable to generate file.\n");
        return;
    }

    char userInput[1000];
    printf("Enter the content to be saved in the file:\n");
    fgets(userInput, sizeof(userInput), stdin);

    size_t length = strlen(userInput);
    if (userInput[length - 1] == '\n')
        userInput[length - 1] = '\0';

    fputs(userInput, filePtr);
    fclose(filePtr);
    printf("File successfully created and content saved.\n");
}

void runLengthCompress(const char *sourceFile, const char *targetFile) {
    FILE *readPtr = fopen(sourceFile, "r");
    FILE *writePtr = fopen(targetFile, "w");

    if (!readPtr || !writePtr) {
        printf("Compression Error: Could not access file(s).\n");
        return;
    }

    char currentChar, previousChar;
    int repetition = 1;

    previousChar = fgetc(readPtr);
    if (previousChar == EOF) {
        printf("Warning: The source file is empty.\n");
        fclose(readPtr);
        fclose(writePtr);
        return;
    }

    while ((currentChar = fgetc(readPtr)) != EOF) {
        if (currentChar == previousChar) {
            repetition++;
        } else {
            fprintf(writePtr, "%c%d", previousChar, repetition);
            previousChar = currentChar;
            repetition = 1;
        }
    }

    fprintf(writePtr, "%c%d", previousChar, repetition);
    fclose(readPtr);
    fclose(writePtr);
    printf("Compression successful. Result saved in: '%s'\n", targetFile);
}

int main() {
    char inputFileName[] = "sample_input.txt";
    char compressedFileName[] = "sample_compressed.txt";

    fflush(stdin); 
    generateFile(inputFileName);
    runLengthCompress(inputFileName, compressedFileName);

    return 0;
}