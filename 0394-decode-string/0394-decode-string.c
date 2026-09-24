#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* decodeString(char* s) {
    int numStack[1000];
    char* strStack[1000];
    int numTop = -1;
    int strTop = -1;

    char* current = malloc(10000);
    current[0] = '\0';

    int num = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            num = num * 10 + (s[i] - '0');
        } else if (s[i] == '[') {
            numStack[++numTop] = num;
            strStack[++strTop] = current;
            current = malloc(10000);
            current[0] = '\0';
            num = 0;
        } else if (s[i] == ']') {
            int count = numStack[numTop--];
            char* previous = strStack[strTop--];

            char* temp = malloc(10000);
            temp[0] = '\0';

            for (int j = 0; j < count; j++)
                strcat(temp, current);

            strcat(previous, temp);

            free(temp);
            free(current);

            current = previous;
        } else {
            int len = strlen(current);
            current[len] = s[i];
            current[len + 1] = '\0';
        }
    }

    return current;
}