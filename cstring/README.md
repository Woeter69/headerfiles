# CString - Comprehensive String Manipulation Library for C++

A robust, easy-to-use string manipulation library providing a wide range of string functions for C++ applications without external dependencies.

## Features

- **Basic Operations**: Length, copy, concatenate, compare
- **Search Operations**: Find character, find substring, count occurrences
- **String Manipulation**: Reverse, uppercase, lowercase, trim, remove spaces
- **String Analysis**: Count vowels, consonants, words, digits, check palindrome
- **String Comparison**: Case-insensitive compare, starts with, ends with, contains
- **String Modification**: Replace characters/substrings, insert, delete
- **String Extraction**: Substring, left, right, mid operations
- **String Padding**: Left pad, right pad, center alignment
- **String Validation**: Check alpha, digit, alphanumeric, case validation
- **Character Validation**: Individual character type checking
- **String Conversion**: Integer/float to/from string
- **String Tokenization**: Split and join operations
- **String Transformation**: Remove duplicates, compress spaces, swap case, capitalize
- **String Rotation**: Rotate left/right, shuffle
- **String Encoding**: ROT13, Caesar cipher, reverse words
- **String Metrics**: Hamming distance, Levenshtein distance

## Installation

Simply include the header file in your C++ project:

```cpp
#include "cstring.h"
```

Compile with the implementation file:

```bash
g++ -o myprogram myprogram.cpp cstring.cpp
```

## Quick Start

```cpp
#include <iostream>
#include "cstring.h"

int main() {
    char str1[100] = "Hello World";
    char str2[100];
    char result[200];
    
    // Basic operations
    int len = stringLength(str1);  // 11
    stringCopy(str2, str1);        // Copy string
    
    // String manipulation
    toUpperCase(str1);             // "HELLO WORLD"
    reverseString(str1);           // "DLROW OLLEH"
    
    // String analysis
    char text[] = "Hello World 123";
    int vowels = countVowels(text);      // 3
    int digits = countDigits(text);      // 3
    int words = countWords(text);        // 3
    
    // String search
    int pos = findChar(text, 'W');       // 6
    int found = stringContains(text, "World");  // 1 (true)
    
    return 0;
}
```

## Function Reference

### Basic String Operations

#### `int stringLength(const char str[])`
Returns the length of a string (excluding null terminator).

#### `void stringCopy(char dest[], const char src[])`
Copies source string to destination.

#### `void stringConcat(char dest[], const char src[])`
Appends source string to destination.

#### `int stringCompare(const char str1[], const char str2[])`
Compares two strings lexicographically. Returns -1, 0, or 1.

### String Search Operations

#### `int findChar(const char str[], char ch)`
Finds first occurrence of a character. Returns index or -1.

#### `int findSubstring(const char str[], const char substr[])`
Finds first occurrence of a substring. Returns starting index or -1.

#### `int findLastChar(const char str[], char ch)`
Finds last occurrence of a character.

#### `int countOccurrences(const char str[], char ch)`
Counts how many times a character appears.

#### `int countSubstringOccurrences(const char str[], const char substr[])`
Counts how many times a substring appears.

### String Manipulation

#### `void reverseString(char str[])`
Reverses the string in-place.

#### `void toUpperCase(char str[])`
Converts all letters to uppercase.

#### `void toLowerCase(char str[])`
Converts all letters to lowercase.

#### `void trimString(char str[])`
Removes leading and trailing whitespace.

#### `void removeSpaces(char str[])`
Removes all space characters.

#### `void replaceChar(char str[], char oldChar, char newChar)`
Replaces all occurrences of a character.
```cpp
char text[] = "Hello World";
replaceChar(text, 'o', '0');  // "Hell0 W0rld"
```

#### `void swapCase(char str[])`
Swaps uppercase to lowercase and vice versa.

#### `void capitalizeWords(char str[])`
Capitalizes the first letter of each word.

#### `void capitalizeFirst(char str[])`
Capitalizes only the first character.

### String Analysis

#### `int countVowels(const char str[])`
Counts vowels (a, e, i, o, u) - case insensitive.

#### `int countConsonants(const char str[])`
Counts consonant letters.

#### `int countWords(const char str[])`
Counts words (separated by whitespace).

#### `int countDigits(const char str[])`
Counts digit characters (0-9).

#### `int countAlpha(const char str[])`
Counts alphabetic characters.

#### `int countSpaces(const char str[])`
Counts space characters.

#### `int isPalindrome(const char str[])`
Checks if string reads the same forwards and backwards. Returns 1 or 0.

### String Comparison

#### `int stringCompareIgnoreCase(const char str1[], const char str2[])`
Case-insensitive string comparison.

#### `int stringStartsWith(const char str[], const char prefix[])`
Checks if string starts with prefix. Returns 1 or 0.

#### `int stringEndsWith(const char str[], const char suffix[])`
Checks if string ends with suffix. Returns 1 or 0.

#### `int stringContains(const char str[], const char substr[])`
Checks if string contains substring. Returns 1 or 0.

#### `int stringEquals(const char str1[], const char str2[])`
Checks exact equality. Returns 1 or 0.

#### `int stringEqualsIgnoreCase(const char str1[], const char str2[])`
Checks equality ignoring case. Returns 1 or 0.

### String Extraction

#### `void substring(const char str[], int start, int length, char result[])`
Extracts a substring.
```cpp
char text[] = "Hello World";
char sub[50];
substring(text, 6, 5, sub);  // "World"
```

#### `void leftString(const char str[], int n, char result[])`
Extracts leftmost n characters.

#### `void rightString(const char str[], int n, char result[])`
Extracts rightmost n characters.

#### `void midString(const char str[], int start, int end, char result[])`
Extracts characters from start to end index (inclusive).

### String Padding

#### `void padLeft(char str[], int totalWidth, char padChar)`
Pads string on the left to reach total width.
```cpp
char num[20] = "42";
padLeft(num, 5, '0');  // "00042"
```

#### `void padRight(char str[], int totalWidth, char padChar)`
Pads string on the right.

#### `void centerString(char str[], int totalWidth, char padChar)`
Centers string within total width.

### String Validation

#### `int isAlpha(const char str[])`
Checks if all characters are alphabetic. Returns 1 or 0.

#### `int isDigit(const char str[])`
Checks if all characters are digits. Returns 1 or 0.

#### `int isAlphaNumeric(const char str[])`
Checks if all characters are alphanumeric. Returns 1 or 0.

#### `int isLowerCase(const char str[])`
Checks if all letters are lowercase. Returns 1 or 0.

#### `int isUpperCase(const char str[])`
Checks if all letters are uppercase. Returns 1 or 0.

### Character Validation

#### `int isCharAlpha(char ch)`
Checks if character is alphabetic.

#### `int isCharDigit(char ch)`
Checks if character is a digit.

#### `int isCharAlphaNumeric(char ch)`
Checks if character is alphanumeric.

#### `int isCharLower(char ch)`
Checks if character is lowercase.

#### `int isCharUpper(char ch)`
Checks if character is uppercase.

#### `int isCharWhitespace(char ch)`
Checks if character is whitespace.

### String Conversion

#### `void intToString(int num, char str[])`
Converts integer to string representation.
```cpp
char buffer[20];
intToString(42, buffer);  // "42"
intToString(-123, buffer);  // "-123"
```

#### `int stringToInt(const char str[])`
Converts string to integer.
```cpp
int num = stringToInt("42");  // 42
```

#### `void floatToString(float num, char str[], int precision)`
Converts float to string with specified decimal places.

#### `float stringToFloat(const char str[])`
Converts string to float.

### String Tokenization

#### `int splitString(const char str[], char delimiter, char tokens[][100], int maxTokens)`
Splits string by delimiter. Returns number of tokens found.
```cpp
char text[] = "apple,banana,cherry";
char tokens[10][100];
int count = splitString(text, ',', tokens, 10);  // count = 3
```

#### `void joinStrings(char result[], const char strings[][100], int count, const char delimiter[])`
Joins multiple strings with delimiter.

### String Transformation

#### `void removeChar(char str[], char ch)`
Removes all occurrences of a character.

#### `void removeSubstring(char str[], const char substr[])`
Removes first occurrence of substring.

#### `void removeDuplicates(char str[])`
Removes duplicate characters, keeping first occurrence.

#### `void compressSpaces(char str[])`
Compresses multiple consecutive spaces into single spaces.

### String Rotation & Encoding

#### `void rotateLeft(char str[], int positions)`
Rotates string left by specified positions.
```cpp
char text[] = "ABCDE";
rotateLeft(text, 2);  // "CDEAB"
```

#### `void rotateRight(char str[], int positions)`
Rotates string right by specified positions.

#### `void encodeROT13(char str[])`
Encodes string using ROT13 cipher.

#### `void encodeCaesar(char str[], int shift)`
Encodes string using Caesar cipher with specified shift.

#### `void reverseWords(char str[])`
Reverses the order of words in a string.
```cpp
char text[] = "Hello World";
reverseWords(text);  // "World Hello"
```

### String Metrics

#### `int hammingDistance(const char str1[], const char str2[])`
Calculates Hamming distance (number of differing positions). Returns -1 if lengths differ.

#### `int levenshteinDistance(const char str1[], const char str2[])`
Calculates Levenshtein distance (minimum edit distance).
```cpp
int dist = levenshteinDistance("kitten", "sitting");  // 3
```

#### `int longestCommonPrefix(const char str1[], const char str2[], char result[])`
Finds longest common prefix. Returns length.

#### `int longestCommonSuffix(const char str1[], const char str2[], char result[])`
Finds longest common suffix. Returns length.

## Complete Example

```cpp
#include <iostream>
#include "cstring.h"

int main() {
    // String analysis
    char text[] = "The Quick Brown Fox Jumps Over The Lazy Dog";
    
    std::cout << "Length: " << stringLength(text) << std::endl;
    std::cout << "Vowels: " << countVowels(text) << std::endl;
    std::cout << "Words: " << countWords(text) << std::endl;
    std::cout << "Palindrome: " << (isPalindrome("racecar") ? "Yes" : "No") << std::endl;
    
    // String manipulation
    char str[100] = "hello world";
    capitalizeWords(str);
    std::cout << "Capitalized: " << str << std::endl;  // "Hello World"
    
    // String search and replace
    char sentence[100] = "I love cats and cats love me";
    if (stringContains(sentence, "cats")) {
        std::cout << "Found 'cats' " << countSubstringOccurrences(sentence, "cats") 
                  << " times" << std::endl;
    }
    
    // String conversion
    char numStr[20];
    intToString(12345, numStr);
    std::cout << "Number as string: " << numStr << std::endl;
    
    int num = stringToInt("42");
    std::cout << "String as number: " << num << std::endl;
    
    // String tokenization
    char csv[] = "apple,banana,cherry,date";
    char tokens[10][100];
    int count = splitString(csv, ',', tokens, 10);
    std::cout << "Tokens: ";
    for (int i = 0; i < count; i++) {
        std::cout << tokens[i] << " ";
    }
    std::cout << std::endl;
    
    // String encoding
    char secret[] = "hello";
    encodeROT13(secret);
    std::cout << "ROT13: " << secret << std::endl;  // "uryyb"
    
    // String metrics
    int dist = levenshteinDistance("kitten", "sitting");
    std::cout << "Edit distance: " << dist << std::endl;  // 3
    
    return 0;
}
```

## Notes

- All string modification functions that work in-place require the destination array to have sufficient space
- String comparison is case-sensitive unless using the `IgnoreCase` variants
- Array bounds are not checked - ensure sufficient buffer sizes
- Functions use null-terminated C-style strings

## Author

Pranjul Gupta

## Total Functions

**77 functions** covering all aspects of string manipulation and analysis.
