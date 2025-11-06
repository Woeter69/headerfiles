// String Operations Library
// Author: Pranjul Gupta
// A comprehensive collection of string manipulation functions

#include "cstring.h"

// ==================== BASIC STRING OPERATIONS ====================

/**
 * Calculate the length of a string
 * @param str - The input string (null-terminated)
 * @return The number of characters in the string (excluding null terminator)
 */
int stringLength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

/**
 * Copy a string from source to destination
 * @param dest - Destination array (must be large enough to hold the source string)
 * @param src - Source string to copy from
 * Note: Copies all characters including the null terminator
 */
void stringCopy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

/**
 * Concatenate (append) source string to the end of destination string
 * @param dest - Destination string (must have enough space for both strings)
 * @param src - Source string to append
 * Note: Modifies dest by appending src to the end
 */
void stringConcat(char dest[], const char src[]) {
    int destLen = stringLength(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';
}

/**
 * Compare two strings lexicographically
 * @param str1 - First string to compare
 * @param str2 - Second string to compare
 * @return -1 if str1 < str2, 0 if str1 == str2, 1 if str1 > str2
 * Note: Comparison is case-sensitive and based on ASCII values
 */
int stringCompare(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) return -1;
        if (str1[i] > str2[i]) return 1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') return 0;
    if (str1[i] == '\0') return -1;
    return 1;
}

// ==================== STRING SEARCH OPERATIONS ====================

/**
 * Find the first occurrence of a character in a string
 * @param str - The string to search in
 * @param ch - The character to search for
 * @return The index of the first occurrence, or -1 if not found
 */
int findChar(const char str[], char ch) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            return i;
        }
    }
    return -1;
}

/**
 * Find the first occurrence of a substring in a string
 * @param str - The string to search in
 * @param substr - The substring to search for
 * @return The starting index of the first occurrence, or -1 if not found
 * Note: Returns 0 if substr is empty, -1 if substr is longer than str
 */
int findSubstring(const char str[], const char substr[]) {
    int strLen = stringLength(str);
    int subLen = stringLength(substr);
    
    if (subLen == 0) return 0;
    if (subLen > strLen) return -1;
    
    // Search for substring using sliding window approach
    for (int i = 0; i <= strLen - subLen; i++) {
        int j = 0;
        while (j < subLen && str[i + j] == substr[j]) {
            j++;
        }
        if (j == subLen) {
            return i;
        }
    }
    return -1;
}

// ==================== STRING MANIPULATION OPERATIONS ====================

/**
 * Reverse a string in-place
 * @param str - The string to reverse (modified in-place)
 * Note: Swaps characters from both ends moving towards the center
 */
void reverseString(char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

/**
 * Convert all lowercase letters in a string to uppercase
 * @param str - The string to convert (modified in-place)
 * Note: Non-alphabetic characters remain unchanged
 */
void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

/**
 * Convert all uppercase letters in a string to lowercase
 * @param str - The string to convert (modified in-place)
 * Note: Non-alphabetic characters remain unchanged
 */
void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

// ==================== STRING ANALYSIS OPERATIONS ====================

/**
 * Count the number of vowels in a string
 * @param str - The string to analyze
 * @return The count of vowels (a, e, i, o, u) - case insensitive
 * Note: Converts uppercase vowels to lowercase for comparison
 */
int countVowels(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        // Convert to lowercase for comparison
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
        }
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

/**
 * Count the number of consonants in a string
 * @param str - The string to analyze
 * @return The count of consonants (alphabetic characters that are not vowels)
 * Note: Only counts alphabetic characters, ignores numbers and special characters
 */
int countConsonants(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        // Convert to lowercase for comparison
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
        }
        // Check if it's a letter but not a vowel
        if (ch >= 'a' && ch <= 'z' && 
            ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            count++;
        }
    }
    return count;
}

/**
 * Count the number of words in a string
 * @param str - The string to analyze
 * @return The count of words (sequences of non-whitespace characters)
 * Note: Words are separated by spaces, tabs, or newlines
 */
int countWords(const char str[]) {
    int count = 0;
    int inWord = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        // Check if current character is not whitespace
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {
            if (!inWord) {
                count++;  // Start of a new word
                inWord = 1;
            }
        } else {
            inWord = 0;  // End of word
        }
    }
    return count;
}

/**
 * Check if a string is a palindrome
 * @param str - The string to check
 * @return 1 if the string is a palindrome, 0 otherwise
 * Note: A palindrome reads the same forwards and backwards (case-sensitive)
 */
int isPalindrome(const char str[]) {
    int len = stringLength(str);
    // Compare characters from both ends moving towards center
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;  // Not a palindrome
        }
    }
    return 1;  // Is a palindrome
}

// ==================== STRING UTILITY OPERATIONS ====================

/**
 * Remove all spaces from a string
 * @param str - The string to modify (modified in-place)
 * Note: Only removes space characters, not tabs or newlines
 */
void removeSpaces(char str[]) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';
}

/**
 * Trim leading and trailing whitespace from a string
 * @param str - The string to trim (modified in-place)
 * Note: Removes spaces and tabs from both ends, but preserves internal whitespace
 */
void trimString(char str[]) {
    int start = 0;
    int len = stringLength(str);
    
    // Find first non-whitespace character
    while (str[start] == ' ' || str[start] == '\t') {
        start++;
    }
    
    // Find last non-whitespace character
    int end = len - 1;
    while (end >= start && (str[end] == ' ' || str[end] == '\t')) {
        end--;
    }
    
    // Shift string to remove leading whitespace
    int i = 0;
    for (int j = start; j <= end; j++) {
        str[i] = str[j];
        i++;
    }
    str[i] = '\0';
}

// ==================== ADVANCED STRING SEARCH ====================

// Find the last occurrence of a character in a string
/**
 * Returns the index of the last occurrence, or -1 if not found
 */
int findLastChar(const char str[], char ch) {
    int lastIndex = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            lastIndex = i;
        }
    }
    return lastIndex;
}

// Find the last occurrence of a substring in a string
/**
 * Returns the starting index of the last occurrence, or -1 if not found
 */
int findLastSubstring(const char str[], const char substr[]) {
    int strLen = stringLength(str);
    int subLen = stringLength(substr);
    int lastIndex = -1;
    
    if (subLen == 0) return strLen;
    if (subLen > strLen) return -1;
    
    for (int i = 0; i <= strLen - subLen; i++) {
        int j = 0;
        while (j < subLen && str[i + j] == substr[j]) {
            j++;
        }
        if (j == subLen) {
            lastIndex = i;
        }
    }
    return lastIndex;
}

/**
 * Count the number of occurrences of a character in a string
 */
int countOccurrences(const char str[], char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

/**
 * Count the number of occurrences of a substring in a string
 */
int countSubstringOccurrences(const char str[], const char substr[]) {
    int count = 0;
    int strLen = stringLength(str);
    int subLen = stringLength(substr);
    
    if (subLen == 0 || subLen > strLen) return 0;
    
    for (int i = 0; i <= strLen - subLen; i++) {
        int j = 0;
        while (j < subLen && str[i + j] == substr[j]) {
            j++;
        }
        if (j == subLen) {
            count++;
            i += subLen - 1;
        }
    }
    return count;
}
// ==================== STRING COMPARISON ====================

/**
 * Compare two strings ignoring case differences
 * @param str1 - First string to compare
 * @param str2 - Second string to compare
 * @return 0 if equal, -1 if str1 < str2, 1 if str1 > str2
 * Note: Performs case-insensitive lexicographic comparison
 */
int stringCompareIgnoreCase(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        char c1 = str1[i];
        char c2 = str2[i];
        
        // Convert to lowercase for comparison
        if (c1 >= 'A' && c1 <= 'Z') c1 = c1 - 'A' + 'a';
        if (c2 >= 'A' && c2 <= 'Z') c2 = c2 - 'A' + 'a';
        
        if (c1 < c2) return -1;
        if (c1 > c2) return 1;
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') return 0;
    if (str1[i] == '\0') return -1;
    return 1;
}

/**
 * Check if a string starts with a given prefix
 * @param str - The string to check
 * @param prefix - The prefix to look for
 * @return 1 if str starts with prefix, 0 otherwise
 */
int stringStartsWith(const char str[], const char prefix[]) {
    int i = 0;
    while (prefix[i] != '\0') {
        if (str[i] == '\0' || str[i] != prefix[i]) {
            return 0;
        }
        i++;
    }
    return 1;
}

/**
 * Check if a string ends with a given suffix
 * @param str - The string to check
 * @param suffix - The suffix to look for
 * @return 1 if str ends with suffix, 0 otherwise
 */
int stringEndsWith(const char str[], const char suffix[]) {
    int strLen = stringLength(str);
    int suffixLen = stringLength(suffix);
    
    if (suffixLen > strLen) return 0;
    
    // Compare suffix starting from the appropriate position
    int strStart = strLen - suffixLen;
    for (int i = 0; i < suffixLen; i++) {
        if (str[strStart + i] != suffix[i]) {
            return 0;
        }
    }
    return 1;
}

/**
 * Check if a string contains a substring
 * @param str - The string to search in
 * @param substr - The substring to search for
 * @return 1 if found, 0 if not found
 */
int stringContains(const char str[], const char substr[]) {
    return findSubstring(str, substr) != -1;
}

// ==================== STRING MODIFICATION ====================

/**
 * Copy at most n characters from src to dest
 */
void stringNCopy(char dest[], const char src[], int n) {
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

/**
 * Concatenate at most n characters from src to dest
 */
void stringNConcat(char dest[], const char src[], int n) {
    int destLen = stringLength(dest);
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';
}

/**
 * Replace all occurrences of oldChar with newChar in a string
 */
void replaceChar(char str[], char oldChar, char newChar) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

// Replace the first occurrence of oldSub with newSub
/**
 * Result is stored in the result array
 */
void replaceSubstring(char str[], const char oldSub[], const char newSub[], char result[]) {
    int pos = findSubstring(str, oldSub);
    
    if (pos == -1) {
        stringCopy(result, str);
        return;
    }
    
    int oldLen = stringLength(oldSub);
    int newLen = stringLength(newSub);
    int i = 0, j = 0;
    
    // Copy characters before the substring
    while (i < pos) {
        result[j++] = str[i++];
    }
    
    // Copy the new substring
    for (int k = 0; k < newLen; k++) {
        result[j++] = newSub[k];
    }
    
    // Skip the old substring and copy the rest
    i += oldLen;
    while (str[i] != '\0') {
        result[j++] = str[i++];
    }
    result[j] = '\0';
}

/**
 * Insert a string at a specific position
 */
void insertString(char str[], const char insert[], int pos) {
    int strLen = stringLength(str);
    int insertLen = stringLength(insert);
    
    if (pos < 0 || pos > strLen) return;
    
    // Shift characters to make room
    for (int i = strLen; i >= pos; i--) {
        str[i + insertLen] = str[i];
    }
    
    // Insert the new string
    for (int i = 0; i < insertLen; i++) {
        str[pos + i] = insert[i];
    }
}

/**
 * Delete count characters starting from position pos
 */
void deleteChars(char str[], int pos, int count) {
    int len = stringLength(str);
    
    if (pos < 0 || pos >= len || count <= 0) return;
    
    int i = pos;
    int j = pos + count;
    
    while (j <= len) {
        str[i++] = str[j++];
    }
}

// ==================== STRING EXTRACTION ====================

/**
 * Extract a substring starting at start with given length
 */
void substring(const char str[], int start, int length, char result[]) {
    int strLen = stringLength(str);
    
    if (start < 0 || start >= strLen || length <= 0) {
        result[0] = '\0';
        return;
    }
    
    int i = 0;
    while (i < length && str[start + i] != '\0') {
        result[i] = str[start + i];
        i++;
    }
    result[i] = '\0';
}

/**
 * Extract the leftmost n characters
 */
void leftString(const char str[], int n, char result[]) {
    substring(str, 0, n, result);
}

/**
 * Extract the rightmost n characters
 */
void rightString(const char str[], int n, char result[]) {
    int len = stringLength(str);
    if (n > len) n = len;
    substring(str, len - n, n, result);
}

/**
 * Extract characters from start to end (inclusive)
 */
void midString(const char str[], int start, int end, char result[]) {
    if (start < 0 || end < start) {
        result[0] = '\0';
        return;
    }
    substring(str, start, end - start + 1, result);
}

// ==================== STRING PADDING AND ALIGNMENT ====================

/**
 * Pad string on the left to reach totalWidth
 */
void padLeft(char str[], int totalWidth, char padChar) {
    int len = stringLength(str);
    if (len >= totalWidth) return;
    
    int padCount = totalWidth - len;
    
    // Shift string to the right
    for (int i = len; i >= 0; i--) {
        str[i + padCount] = str[i];
    }
    
    // Add padding
    for (int i = 0; i < padCount; i++) {
        str[i] = padChar;
    }
}

/**
 * Pad string on the right to reach totalWidth
 */
void padRight(char str[], int totalWidth, char padChar) {
    int len = stringLength(str);
    if (len >= totalWidth) return;
    
    for (int i = len; i < totalWidth; i++) {
        str[i] = padChar;
    }
    str[totalWidth] = '\0';
}

/**
 * Center string within totalWidth by padding both sides
 */
void centerString(char str[], int totalWidth, char padChar) {
    int len = stringLength(str);
    if (len >= totalWidth) return;
    
    int totalPad = totalWidth - len;
    int leftPad = totalPad / 2;
    int rightPad = totalPad - leftPad;
    
    // Shift string to the right
    for (int i = len; i >= 0; i--) {
        str[i + leftPad] = str[i];
    }
    
    // Add left padding
    for (int i = 0; i < leftPad; i++) {
        str[i] = padChar;
    }
    
    // Add right padding
    for (int i = 0; i < rightPad; i++) {
        str[len + leftPad + i] = padChar;
    }
    str[totalWidth] = '\0';
}

// ==================== STRING VALIDATION ====================

/**
 * Check if all characters are alphabetic
 */
int isAlpha(const char str[]) {
    if (str[0] == '\0') return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            return 0;
        }
    }
    return 1;
}

/**
 * Check if all characters are digits
 */
int isDigit(const char str[]) {
    if (str[0] == '\0') return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            return 0;
        }
    }
    return 1;
}

/**
 * Check if all characters are alphanumeric
 */
int isAlphaNumeric(const char str[]) {
    if (str[0] == '\0') return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || 
              (str[i] >= 'A' && str[i] <= 'Z') || 
              (str[i] >= '0' && str[i] <= '9'))) {
            return 0;
        }
    }
    return 1;
}

/**
 * Check if all alphabetic characters are lowercase
 */
int isLowerCase(const char str[]) {
    if (str[0] == '\0') return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            return 0;
        }
    }
    return 1;
}

/**
 * Check if all alphabetic characters are uppercase
 */
int isUpperCase(const char str[]) {
    if (str[0] == '\0') return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            return 0;
        }
    }
    return 1;
}

/**
 * Check if all characters are whitespace
 */
int isWhitespace(const char str[]) {
    if (str[0] == '\0') return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r') {
            return 0;
        }
    }
    return 1;
}

// ==================== CHARACTER TYPE CHECKING ====================

/**
 * Check if a character is alphabetic
 */
int isCharAlpha(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

/**
 * Check if a character is a digit
 */
int isCharDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

/**
 * Check if a character is alphanumeric
 */
int isCharAlphaNumeric(char ch) {
    return isCharAlpha(ch) || isCharDigit(ch);
}

/**
 * Check if a character is lowercase
 */
int isCharLower(char ch) {
    return ch >= 'a' && ch <= 'z';
}

/**
 * Check if a character is uppercase
 */
int isCharUpper(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

/**
 * Check if a character is whitespace
 */
int isCharWhitespace(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

// ==================== STRING CONVERSION ====================

/**
 * Convert an integer to a string
 */
void intToString(int num, char str[]) {
    int i = 0;
    int isNegative = 0;
    
    if (num == 0) {
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }
    
    // Extract digits in reverse order
    while (num > 0) {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    
    if (isNegative) {
        str[i++] = '-';
    }
    
    str[i] = '\0';
    
    // Reverse the string
    reverseString(str);
}

/**
 * Convert a string to an integer
 */
int stringToInt(const char str[]) {
    int result = 0;
    int sign = 1;
    int i = 0;
    
    // Handle leading whitespace
    while (str[i] == ' ' || str[i] == '\t') {
        i++;
    }
    
    // Handle sign
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    
    // Convert digits
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    
    return result * sign;
}

/**
 * Convert a float to a string with specified precision
 */
void floatToString(float num, char str[], int precision) {
    int intPart = (int)num;
    float fracPart = num - intPart;
    
    if (fracPart < 0) fracPart = -fracPart;
    
    // Convert integer part
    intToString(intPart, str);
    
    int len = stringLength(str);
    str[len++] = '.';
    
    // Convert fractional part
    for (int i = 0; i < precision; i++) {
        fracPart *= 10;
        int digit = (int)fracPart;
        str[len++] = digit + '0';
        fracPart -= digit;
    }
    
    str[len] = '\0';
}

/**
 * Convert a string to a float
 */
float stringToFloat(const char str[]) {
    float result = 0.0f;
    float sign = 1.0f;
    int i = 0;
    
    // Handle sign
    if (str[i] == '-') {
        sign = -1.0f;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    
    // Convert integer part
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10.0f + (str[i] - '0');
        i++;
    }
    
    // Convert fractional part
    if (str[i] == '.') {
        i++;
        float fraction = 0.1f;
        while (str[i] >= '0' && str[i] <= '9') {
            result += (str[i] - '0') * fraction;
            fraction *= 0.1f;
            i++;
        }
    }
    
    return result * sign;
}

// ==================== STRING TOKENIZATION ====================

// Split a string by delimiter into tokens
/**
 * Returns the number of tokens found
 */
int splitString(const char str[], char delimiter, char tokens[][100], int maxTokens) {
    int tokenCount = 0;
    int tokenIndex = 0;
    
    for (int i = 0; str[i] != '\0' && tokenCount < maxTokens; i++) {
        if (str[i] == delimiter) {
            if (tokenIndex > 0) {
                tokens[tokenCount][tokenIndex] = '\0';
                tokenCount++;
                tokenIndex = 0;
            }
        } else {
            tokens[tokenCount][tokenIndex++] = str[i];
        }
    }
    
    // Add the last token
    if (tokenIndex > 0 && tokenCount < maxTokens) {
        tokens[tokenCount][tokenIndex] = '\0';
        tokenCount++;
    }
    
    return tokenCount;
}

/**
 * Join multiple strings with a delimiter
 */
void joinStrings(char result[], const char strings[][100], int count, const char delimiter[]) {
    result[0] = '\0';
    
    for (int i = 0; i < count; i++) {
        stringConcat(result, strings[i]);
        if (i < count - 1) {
            stringConcat(result, delimiter);
        }
    }
}

// ==================== STRING ANALYSIS ====================

/**
 * Count the number of digits in a string
 */
int countDigits(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            count++;
        }
    }
    return count;
}

/**
 * Count the number of alphabetic characters in a string
 */
int countAlpha(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            count++;
        }
    }
    return count;
}

/**
 * Count the number of spaces in a string
 */
int countSpaces(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count;
}

/**
 * Count the number of lines in a string (newline characters + 1)
 */
int countLines(const char str[]) {
    int count = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            count++;
        }
    }
    return count;
}

// ==================== STRING MANIPULATION ====================

/**
 * Remove all occurrences of a character from a string
 */
void removeChar(char str[], char ch) {
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != ch) {
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';
}

/**
 * Remove the first occurrence of a substring from a string
 */
void removeSubstring(char str[], const char substr[]) {
    int pos = findSubstring(str, substr);
    if (pos == -1) return;
    
    int subLen = stringLength(substr);
    deleteChars(str, pos, subLen);
}

/**
 * Remove duplicate characters from a string
 */
void removeDuplicates(char str[]) {
    int len = stringLength(str);
    if (len < 2) return;
    
    int writeIndex = 1;
    
    for (int i = 1; i < len; i++) {
        int isDuplicate = 0;
        for (int j = 0; j < writeIndex; j++) {
            if (str[i] == str[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (!isDuplicate) {
            str[writeIndex++] = str[i];
        }
    }
    str[writeIndex] = '\0';
}

/**
 * Compress multiple consecutive spaces into single spaces
 */
void compressSpaces(char str[]) {
    int i = 0, j = 0;
    int lastWasSpace = 0;
    
    while (str[i] != '\0') {
        if (str[i] == ' ') {
            if (!lastWasSpace) {
                str[j++] = str[i];
                lastWasSpace = 1;
            }
        } else {
            str[j++] = str[i];
            lastWasSpace = 0;
        }
        i++;
    }
    str[j] = '\0';
}

/**
 * Swap the case of all alphabetic characters
 */
void swapCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

/**
 * Capitalize the first letter of each word
 */
void capitalizeWords(char str[]) {
    int capitalizeNext = 1;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {
            capitalizeNext = 1;
        } else if (capitalizeNext && str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
            capitalizeNext = 0;
        } else {
            capitalizeNext = 0;
        }
    }
}

/**
 * Capitalize only the first character of the string
 */
void capitalizeFirst(char str[]) {
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 'a' + 'A';
    }
}

// ==================== STRING ROTATION AND SHIFTING ====================

/**
 * Rotate string left by specified positions
 */
void rotateLeft(char str[], int positions) {
    int len = stringLength(str);
    if (len == 0) return;
    
    positions = positions % len;
    if (positions == 0) return;
    
    // Reverse first part
    for (int i = 0; i < positions / 2; i++) {
        char temp = str[i];
        str[i] = str[positions - 1 - i];
        str[positions - 1 - i] = temp;
    }
    
    // Reverse second part
    for (int i = 0; i < (len - positions) / 2; i++) {
        char temp = str[positions + i];
        str[positions + i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    
    // Reverse entire string
    reverseString(str);
}

/**
 * Rotate string right by specified positions
 */
void rotateRight(char str[], int positions) {
    int len = stringLength(str);
    if (len == 0) return;
    
    positions = positions % len;
    rotateLeft(str, len - positions);
}

/**
 * Shuffle string characters (simple pseudo-random shuffle)
 */
void shuffleString(char str[]) {
    int len = stringLength(str);
    
    // Simple shuffle using position-based swapping
    for (int i = 0; i < len; i++) {
        int j = (i * 7 + 13) % len;
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// ==================== STRING ENCODING ====================

/**
 * Encode string using ROT13 cipher
 */
void encodeROT13(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + (str[i] - 'a' + 13) % 26;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + (str[i] - 'A' + 13) % 26;
        }
    }
}

/**
 * Encode string using Caesar cipher with specified shift
 */
void encodeCaesar(char str[], int shift) {
    shift = shift % 26;
    if (shift < 0) shift += 26;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + (str[i] - 'a' + shift) % 26;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + (str[i] - 'A' + shift) % 26;
        }
    }
}

/**
 * Reverse the order of words in a string
 */
void reverseWords(char str[]) {
    // First reverse the entire string
    reverseString(str);
    
    // Then reverse each word individually
    int start = 0;
    int len = stringLength(str);
    
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
            // Reverse the word from start to i-1
            int end = i - 1;
            while (start < end) {
                char temp = str[start];
                str[start] = str[end];
                str[end] = temp;
                start++;
                end--;
            }
            start = i + 1;
        }
    }
}

// ==================== STRING COMPARISON UTILITIES ====================

/**
 * Check if two strings are exactly equal
 */
int stringEquals(const char str1[], const char str2[]) {
    return stringCompare(str1, str2) == 0;
}

/**
 * Check if two strings are equal ignoring case
 */
int stringEqualsIgnoreCase(const char str1[], const char str2[]) {
    return stringCompareIgnoreCase(str1, str2) == 0;
}

// Find the longest common prefix of two strings
/**
 * Returns the length of the common prefix
 */
int longestCommonPrefix(const char str1[], const char str2[], char result[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        result[i] = str1[i];
        i++;
    }
    result[i] = '\0';
    return i;
}

// Find the longest common suffix of two strings
/**
 * Returns the length of the common suffix
 */
int longestCommonSuffix(const char str1[], const char str2[], char result[]) {
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);
    int i = 0;
    
    while (i < len1 && i < len2 && str1[len1 - 1 - i] == str2[len2 - 1 - i]) {
        i++;
    }
    
    // Copy suffix to result
    for (int j = 0; j < i; j++) {
        result[j] = str1[len1 - i + j];
    }
    result[i] = '\0';
    
    return i;
}

// ==================== STRING METRICS ====================

// Calculate Hamming distance between two strings of equal length
/**
 * Returns -1 if strings have different lengths
 */
int hammingDistance(const char str1[], const char str2[]) {
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);
    
    if (len1 != len2) return -1;
    
    int distance = 0;
    for (int i = 0; i < len1; i++) {
        if (str1[i] != str2[i]) {
            distance++;
        }
    }
    return distance;
}

// Calculate Levenshtein distance (edit distance) between two strings
/**
 * Returns the minimum number of single-character edits required
 */
int levenshteinDistance(const char str1[], const char str2[]) {
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);
    
    // Create a 2D array for dynamic programming
    int dp[100][100];  // Assuming max string length of 100
    
    // Initialize base cases
    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }
    
    // Fill the dp table
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
            } else {
                int min = dp[i-1][j];  // deletion
                if (dp[i][j-1] < min) min = dp[i][j-1];  // insertion
                if (dp[i-1][j-1] < min) min = dp[i-1][j-1];  // substitution
                dp[i][j] = min + 1;
            }
        }
    }
    
    return dp[len1][len2];
}
