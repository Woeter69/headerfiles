// String Operations Library
// Author: Pranjul Gupta

#ifndef CSTRING_H
#define CSTRING_H

// String length and basic operations
int stringLength(const char str[]);
void stringCopy(char dest[], const char src[]);
void stringConcat(char dest[], const char src[]);
int stringCompare(const char str1[], const char str2[]);

// String search and manipulation
int findChar(const char str[], char ch);
int findSubstring(const char str[], const char substr[]);
void reverseString(char str[]);
void toUpperCase(char str[]);
void toLowerCase(char str[]);

// String analysis
int countVowels(const char str[]);
int countConsonants(const char str[]);
int countWords(const char str[]);
int isPalindrome(const char str[]);

// String utilities
void removeSpaces(char str[]);
void trimString(char str[]);

// Advanced string search
int countOccurrences(const char str[], char ch);
int stringContains(const char str[], const char substr[]);

// String modification
void stringNCopy(char dest[], const char src[], int n);
void stringNConcat(char dest[], const char src[], int n);
void replaceChar(char str[], char oldChar, char newChar);
void insertString(char str[], const char insert[], int pos);

// String extraction
void substring(const char str[], int start, int length, char result[]);

// String validation
int isAlpha(const char str[]);
int isDigit(const char str[]);
int isAlphaNumeric(const char str[]);

// Character type checking
int isCharAlpha(char ch);
int isCharDigit(char ch);
int isCharWhitespace(char ch);

// String conversion
void intToString(int num, char str[]);
int stringToInt(const char str[]);

// String tokenization
int splitString(const char str[], char delimiter, char tokens[][100], int maxTokens);

// String manipulation
void removeChar(char str[], char ch);
void capitalizeWords(char str[]);
void capitalizeFirst(char str[]);

#endif