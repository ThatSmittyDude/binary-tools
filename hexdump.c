#include <stdio.h>
#include <stdlib.h>

void hexDump(const char* inputFileName, const char* outputFileName, int bytesPerLine) {
    if (bytesPerLine <= 0) {
        bytesPerLine = 8; // Set default value if invalid
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
    int byteCount = 0;
    while (fread(&byte, sizeof(byte), 1, inputFile) == 1) {
        fprintf(outputFile, "%02x ", byte);
        byteCount++;

        if (byteCount >= bytesPerLine) {
            fprintf(outputFile, "\n");
            byteCount = 0;
        }
    }

    if (byteCount != 0) {
        fprintf(outputFile, "\n");
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("hexdump complete\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input file name> <output file name>\n", argv[0]);
        return 1;
    }

    hexDump(argv[1], argv[2], 8);

    return 0;
}

