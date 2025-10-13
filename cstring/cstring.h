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

#endif
