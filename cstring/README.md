# CString - String Manipulation Library for C++

A robust, easy-to-use string manipulation library providing essential string functions for C++ applications without external dependencies.

## Features

- **Basic Operations**: Length, copy, concatenate, compare
- **Search Operations**: Find character, find substring, count occurrences, contains
- **String Manipulation**: Reverse, uppercase, lowercase, trim, remove spaces
- **String Analysis**: Count vowels, consonants, words, check palindrome
- **String Modification**: Replace characters, insert strings, n-copy, n-concat
- **String Extraction**: Substring operations
- **String Validation**: Check alpha, digit, alphanumeric
- **Character Validation**: Check alpha, digit, whitespace
- **String Conversion**: Integer to/from string
- **String Tokenization**: Split operations
- **String Transformation**: Remove characters, capitalize words/first letter

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
    
    // Basic operations
    int len = stringLength(str1);  // 11
    stringCopy(str2, str1);        // Copy string
    
    // String manipulation
    toUpperCase(str1);             // "HELLO WORLD"
    reverseString(str1);           // "DLROW OLLEH"
    
    // String analysis
    char text[] = "Hello World";
    int vowels = countVowels(text);      // 3
    int words = countWords(text);        // 2
    
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

#### `int countOccurrences(const char str[], char ch)`
Counts how many times a character appears.

#### `int stringContains(const char str[], const char substr[])`
Checks if string contains substring. Returns 1 or 0.

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

#### `void insertString(char str[], const char insert[], int pos)`
Inserts a string at specified position.

#### `void stringNCopy(char dest[], const char src[], int n)`
Copies up to n characters from source to destination.

#### `void stringNConcat(char dest[], const char src[], int n)`
Appends up to n characters from source to destination.

#### `void capitalizeWords(char str[])`
Capitalizes the first letter of each word.

#### `void capitalizeFirst(char str[])`
Capitalizes only the first character.

#### `void removeChar(char str[], char ch)`
Removes all occurrences of a character.

### String Analysis

#### `int countVowels(const char str[])`
Counts vowels (a, e, i, o, u) - case insensitive.

#### `int countConsonants(const char str[])`
Counts consonant letters.

#### `int countWords(const char str[])`
Counts words (separated by whitespace).

#### `int isPalindrome(const char str[])`
Checks if string reads the same forwards and backwards. Returns 1 or 0.

### String Extraction

#### `void substring(const char str[], int start, int length, char result[])`
Extracts a substring.
```cpp
char text[] = "Hello World";
char sub[50];
substring(text, 6, 5, sub);  // "World"
```

### String Validation

#### `int isAlpha(const char str[])`
Checks if all characters are alphabetic. Returns 1 or 0.

#### `int isDigit(const char str[])`
Checks if all characters are digits. Returns 1 or 0.

#### `int isAlphaNumeric(const char str[])`
Checks if all characters are alphanumeric. Returns 1 or 0.

### Character Validation

#### `int isCharAlpha(char ch)`
Checks if character is alphabetic.

#### `int isCharDigit(char ch)`
Checks if character is a digit.

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

### String Tokenization

#### `int splitString(const char str[], char delimiter, char tokens[][100], int maxTokens)`
Splits string by delimiter. Returns number of tokens found.
```cpp
char text[] = "apple,banana,cherry";
char tokens[10][100];
int count = splitString(text, ',', tokens, 10);  // count = 3
```

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
        std::cout << "Found 'cats' " << countOccurrences(sentence, 'c') 
                  << " 'c' characters" << std::endl;
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
    
    // Character validation
    char ch = 'A';
    std::cout << "Is '" << ch << "' alpha? " 
              << (isCharAlpha(ch) ? "Yes" : "No") << std::endl;
    
    return 0;
}
```

## Notes

- All string modification functions that work in-place require the destination array to have sufficient space
- String comparison is case-sensitive by default
- Array bounds are not checked - ensure sufficient buffer sizes
- Functions use null-terminated C-style strings
- All functions include inline comments for better code readability

## Author

Pranjul Gupta

## Total Functions

**35 functions** covering essential string manipulation and analysis operations.
