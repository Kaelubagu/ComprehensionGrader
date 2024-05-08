#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

float sentenceCalc(string t) {
    float sentences = 0.00;
    for (int i = 0, length = strlen(t); i < length; i++) {
        if (t[i] == '.' || t[i] == '?' || t[i] == '!') {
            sentences++;
        }
    }
    return sentences;
}

float letterCalc(string t) {
    float letters = 0.00;
    for (int i = 0, length = strlen(t); i < length; i++) {
        if (isalpha(t[i])) {
            letters++;
        }
    }
    return letters;
}

// may not need this
float wordCalc(string a) {
    // Amount of words
    float words = 0.00;
    int inWord = 0;

    for (int i = 0, length = strlen(a); i < length; i++) {
        if (a[i] != ' ' && inWord == 0) {
            // Starting a new word
            inWord = 1;
            words++;
        }
        else if (a[i] == ' ') {
            // Exiting a word
            inWord = 0;
        }
    }
    return words;
}

int readAlgo(string text) {
    float L = (letterCalc(text) / wordCalc(text)) * 100.0;
    float S = (sentenceCalc(text) / wordCalc(text)) * 100.0;
    float index = (0.0588 * L - 0.296 * S - 15.8) + 0.5;
    printf("WOWWWWWWWWWWWWWWWWWWWWWW %f", index);
    return (int) index;
}

int main(void) {

    // push prompt
    string prompt1 = get_string("Text: ");

    // run readAlgo on the text given by user
    int answer = readAlgo(prompt1);

    // Printing out Answer
    if (answer > 16) {
        printf("Grade 16+\n");
    } else if (answer < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade %i\n", answer);
    }
}
