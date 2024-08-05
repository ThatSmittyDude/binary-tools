#include <stdio.h>
#include <stdlib.h>

void byteToBinary(unsigned char byte, char* binStr) {
    for (int i = 7; i >= 0; i--) {
        binStr[7 - i] = (byte & (1 << i)) ? '1' : '0';
    }
    binStr[8] = '\0';
}

void binDump(const char* inputFileName, const char* outputFileName, int wordsPerLine) {
    if (wordsPerLine <= 0) {
        wordsPerLine = 8; // Set default value if invalid
    }

    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        fprintf(stderr, "Error opening input file: %s\n", inputFileName);
        return;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (!outputFile) {
        fprintf(stderr, "Error opening output file: %s\n", outputFileName);
        fclose(inputFile);
        return;
    }

    unsigned char byte;
    int wordCount = 0;
    char binStr[9];
    while (fread(&byte, sizeof(byte), 1, inputFile) == 1) {
        byteToBinary(byte, binStr);
        fprintf(outputFile, "%s ", binStr);
        wordCount++;

        if (wordCount >= wordsPerLine) {
            fprintf(outputFile, "\n");
            wordCount = 0;
        }
    }

    if (wordCount != 0) {
        fprintf(outputFile, "\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("bindump complete\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file name> <output file name>\n", argv[0]);
        return 1;
    }

    binDump(argv[1], argv[2], 8);

    return 0;
}

