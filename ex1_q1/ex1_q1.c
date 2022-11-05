#include <cstdio>
#include <stdio.h>
void readDataFromFile(char* filleName, FILE* outputFile);
void getAverageForStudent(char* line, FILE* outputFile);

void readDataFromFile(char* filleName, FILE* outputFile) {
    FILE* file = fopen(filleName, "r");
    char line[80];
    while (fgets(line, sizeof(line), file)) {
        getAverageForStudent(line,outputFile);
    }
    fclose(file);
}
void getAverageForStudent(char* line, FILE* outputFile) {
    int sumOfGrades = 0;
    char* token = strtok(line, " ");
    int index = 0;
    char* studentName = line[index];
    int grade = 0;
    while (token != NULL) {
        index++;
        sscanf(token[index], "%d", &grade);
        sumOfGrades += grade;
        token = strtok(NULL, " ");
    }
    double avg = (double)sumOfGrades / (index - 1);
    fprintf(outputFile, "%s", studentName);
    fprintf(outputFile," % .2f", avg);
    fclose(outputFile);
}
int main(int agrc, char* argv[]) {
    FILE* outputFile;
    int amountOfFilles = sizeof(argv);
    char* inputFileName;
    if (strcmp(argv[1], "-t") == 0) {
        outputFile = fopen("all_std.txt", "w");
        resize_file("all_std.txt", 0);
        fseek(outputFile, 0, SEEK_SET);
    }
    else  if (strcmp(argv[1], "-a") == 0) {
        outputFile = fopen("all_std.txt", "a");
    }
    for (int i = 1; i < amountOfFilles; i++) {
        inputFileName = argv[i];
        readDataFromFile(inputFileName, outputFile);
    }
}

