# CString Library - Complete Function List

## Author: Pranjul Gupta

Total Functions: **77** (15 original + 62 new)

---

## Original Functions (15)

### String Length and Basic Operations
1. `int stringLength(const char str[])` - Calculate string length
2. `void stringCopy(char dest[], const char src[])` - Copy string
3. `void stringConcat(char dest[], const char src[])` - Concatenate strings
4. `int stringCompare(const char str1[], const char str2[])` - Compare strings

### String Search and Manipulation
5. `int findChar(const char str[], char ch)` - Find first character occurrence
6. `int findSubstring(const char str[], const char substr[])` - Find substring
7. `void reverseString(char str[])` - Reverse string
8. `void toUpperCase(char str[])` - Convert to uppercase
9. `void toLowerCase(char str[])` - Convert to lowercase

### String Analysis
10. `int countVowels(const char str[])` - Count vowels
11. `int countConsonants(const char str[])` - Count consonants
12. `int countWords(const char str[])` - Count words
13. `int isPalindrome(const char str[])` - Check if palindrome

### String Utilities
14. `void removeSpaces(char str[])` - Remove all spaces
15. `void trimString(char str[])` - Trim leading/trailing whitespace

---

## New Functions (62)

### Advanced String Search (4)
16. `int findLastChar(const char str[], char ch)` - Find last character occurrence
17. `int findLastSubstring(const char str[], const char substr[])` - Find last substring
18. `int countOccurrences(const char str[], char ch)` - Count character occurrences
19. `int countSubstringOccurrences(const char str[], const char substr[])` - Count substring occurrences

### String Comparison (4)
20. `int stringCompareIgnoreCase(const char str1[], const char str2[])` - Case-insensitive compare
21. `int stringStartsWith(const char str[], const char prefix[])` - Check if starts with prefix
22. `int stringEndsWith(const char str[], const char suffix[])` - Check if ends with suffix
23. `int stringContains(const char str[], const char substr[])` - Check if contains substring

### String Modification (6)
24. `void stringNCopy(char dest[], const char src[], int n)` - Copy n characters
25. `void stringNConcat(char dest[], const char src[], int n)` - Concatenate n characters
26. `void replaceChar(char str[], char oldChar, char newChar)` - Replace all character occurrences
27. `void replaceSubstring(char str[], const char oldSub[], const char newSub[], char result[])` - Replace substring
28. `void insertString(char str[], const char insert[], int pos)` - Insert string at position
29. `void deleteChars(char str[], int pos, int count)` - Delete characters

### String Extraction (4)
30. `void substring(const char str[], int start, int length, char result[])` - Extract substring
31. `void leftString(const char str[], int n, char result[])` - Extract leftmost n characters
32. `void rightString(const char str[], int n, char result[])` - Extract rightmost n characters
33. `void midString(const char str[], int start, int end, char result[])` - Extract middle portion

### String Padding and Alignment (3)
34. `void padLeft(char str[], int totalWidth, char padChar)` - Pad left to width
35. `void padRight(char str[], int totalWidth, char padChar)` - Pad right to width
36. `void centerString(char str[], int totalWidth, char padChar)` - Center string

### String Validation (6)
37. `int isAlpha(const char str[])` - Check if all alphabetic
38. `int isDigit(const char str[])` - Check if all digits
39. `int isAlphaNumeric(const char str[])` - Check if all alphanumeric
40. `int isLowerCase(const char str[])` - Check if all lowercase
41. `int isUpperCase(const char str[])` - Check if all uppercase
42. `int isWhitespace(const char str[])` - Check if all whitespace

### Character Type Checking (6)
43. `int isCharAlpha(char ch)` - Check if character is alphabetic
44. `int isCharDigit(char ch)` - Check if character is digit
45. `int isCharAlphaNumeric(char ch)` - Check if character is alphanumeric
46. `int isCharLower(char ch)` - Check if character is lowercase
47. `int isCharUpper(char ch)` - Check if character is uppercase
48. `int isCharWhitespace(char ch)` - Check if character is whitespace

### String Conversion (4)
49. `void intToString(int num, char str[])` - Convert integer to string
50. `int stringToInt(const char str[])` - Convert string to integer
51. `void floatToString(float num, char str[], int precision)` - Convert float to string
52. `float stringToFloat(const char str[])` - Convert string to float

### String Tokenization (2)
53. `int splitString(const char str[], char delimiter, char tokens[][100], int maxTokens)` - Split by delimiter
54. `void joinStrings(char result[], const char strings[][100], int count, const char delimiter[])` - Join with delimiter

### String Analysis (4)
55. `int countDigits(const char str[])` - Count digits
56. `int countAlpha(const char str[])` - Count alphabetic characters
57. `int countSpaces(const char str[])` - Count spaces
58. `int countLines(const char str[])` - Count lines

### String Manipulation (7)
59. `void removeChar(char str[], char ch)` - Remove all character occurrences
60. `void removeSubstring(char str[], const char substr[])` - Remove first substring occurrence
61. `void removeDuplicates(char str[])` - Remove duplicate characters
62. `void compressSpaces(char str[])` - Compress multiple spaces to single
63. `void swapCase(char str[])` - Swap case of all characters
64. `void capitalizeWords(char str[])` - Capitalize first letter of each word
65. `void capitalizeFirst(char str[])` - Capitalize first character only

### String Rotation and Shifting (3)
66. `void rotateLeft(char str[], int positions)` - Rotate string left
67. `void rotateRight(char str[], int positions)` - Rotate string right
68. `void shuffleString(char str[])` - Shuffle string characters

### String Encoding (3)
69. `void encodeROT13(char str[])` - Encode with ROT13 cipher
70. `void encodeCaesar(char str[], int shift)` - Encode with Caesar cipher
71. `void reverseWords(char str[])` - Reverse word order

### String Comparison Utilities (4)
72. `int stringEquals(const char str1[], const char str2[])` - Check exact equality
73. `int stringEqualsIgnoreCase(const char str1[], const char str2[])` - Check equality ignoring case
74. `int longestCommonPrefix(const char str1[], const char str2[], char result[])` - Find longest common prefix
75. `int longestCommonSuffix(const char str1[], const char str2[], char result[])` - Find longest common suffix

### String Metrics (2)
76. `int hammingDistance(const char str1[], const char str2[])` - Calculate Hamming distance
77. `int levenshteinDistance(const char str1[], const char str2[])` - Calculate Levenshtein distance

---

## Function Categories Summary

| Category | Count |
|----------|-------|
| Basic Operations | 4 |
| Search Operations | 6 |
| Comparison | 8 |
| Modification | 13 |
| Extraction | 4 |
| Validation | 12 |
| Conversion | 4 |
| Tokenization | 2 |
| Analysis | 8 |
| Manipulation | 7 |
| Rotation/Encoding | 6 |
| Metrics | 2 |
| **TOTAL** | **77** |

---

## Features

✅ **Comprehensive Coverage** - 77 string manipulation functions
✅ **Well Commented** - Every function has descriptive comments
✅ **Organized** - Functions grouped by category with clear headers
✅ **No Dependencies** - Pure C implementation, no external libraries
✅ **Educational** - Great for learning string algorithms
✅ **Production Ready** - Robust implementations with edge case handling

---

## Usage Example

```cpp
#include "cstring.h"
#include <iostream>

int main() {
    char str1[100] = "Hello World";
    char str2[100];
    
    // Basic operations
    int len = stringLength(str1);  // 11
    
    // Case conversion
    toUpperCase(str1);  // "HELLO WORLD"
    
    // Search
    int pos = findChar(str1, 'W');  // 6
    
    // Extraction
    substring(str1, 0, 5, str2);  // "HELLO"
    
    // Validation
    char num[] = "12345";
    if (isDigit(num)) {
        int value = stringToInt(num);  // 12345
    }
    
    // Encoding
    char secret[] = "secret";
    encodeROT13(secret);  // "frperg"
    
    return 0;
}
```

---

**Last Updated:** November 6, 2024
