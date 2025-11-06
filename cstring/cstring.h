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
int findLastChar(const char str[], char ch);
int findLastSubstring(const char str[], const char substr[]);
int countOccurrences(const char str[], char ch);
int countSubstringOccurrences(const char str[], const char substr[]);

// String comparison
int stringCompareIgnoreCase(const char str1[], const char str2[]);
int stringStartsWith(const char str[], const char prefix[]);
int stringEndsWith(const char str[], const char suffix[]);
int stringContains(const char str[], const char substr[]);

// String modification
void stringNCopy(char dest[], const char src[], int n);
void stringNConcat(char dest[], const char src[], int n);
void replaceChar(char str[], char oldChar, char newChar);
void replaceSubstring(char str[], const char oldSub[], const char newSub[], char result[]);
void insertString(char str[], const char insert[], int pos);
void deleteChars(char str[], int pos, int count);

// String extraction
void substring(const char str[], int start, int length, char result[]);
void leftString(const char str[], int n, char result[]);
void rightString(const char str[], int n, char result[]);
void midString(const char str[], int start, int end, char result[]);

// String padding and alignment
void padLeft(char str[], int totalWidth, char padChar);
void padRight(char str[], int totalWidth, char padChar);
void centerString(char str[], int totalWidth, char padChar);

// String validation
int isAlpha(const char str[]);
int isDigit(const char str[]);
int isAlphaNumeric(const char str[]);
int isLowerCase(const char str[]);
int isUpperCase(const char str[]);
int isWhitespace(const char str[]);

// Character type checking
int isCharAlpha(char ch);
int isCharDigit(char ch);
int isCharAlphaNumeric(char ch);
int isCharLower(char ch);
int isCharUpper(char ch);
int isCharWhitespace(char ch);

// String conversion
void intToString(int num, char str[]);
int stringToInt(const char str[]);
void floatToString(float num, char str[], int precision);
float stringToFloat(const char str[]);

// String tokenization
int splitString(const char str[], char delimiter, char tokens[][100], int maxTokens);
void joinStrings(char result[], const char strings[][100], int count, const char delimiter[]);

// String analysis
int countDigits(const char str[]);
int countAlpha(const char str[]);
int countSpaces(const char str[]);
int countLines(const char str[]);

// String manipulation
void removeChar(char str[], char ch);
void removeSubstring(char str[], const char substr[]);
void removeDuplicates(char str[]);
void compressSpaces(char str[]);
void swapCase(char str[]);
void capitalizeWords(char str[]);
void capitalizeFirst(char str[]);

// String rotation and shifting
void rotateLeft(char str[], int positions);
void rotateRight(char str[], int positions);
void shuffleString(char str[]);

// String encoding
void encodeROT13(char str[]);
void encodeCaesar(char str[], int shift);
void reverseWords(char str[]);

// String comparison utilities
int stringEquals(const char str1[], const char str2[]);
int stringEqualsIgnoreCase(const char str1[], const char str2[]);
int longestCommonPrefix(const char str1[], const char str2[], char result[]);
int longestCommonSuffix(const char str1[], const char str2[], char result[]);

// String metrics
int hammingDistance(const char str1[], const char str2[]);
int levenshteinDistance(const char str1[], const char str2[]);

#endif
