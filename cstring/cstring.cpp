// String Operations Library
// Author: Pranjul Gupta

#include "cstring.h"

// ==================== BASIC STRING OPERATIONS ====================

int stringLength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {  // Loop until null terminator
        length++;
    }
    return length;
}

void stringCopy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];  // Copy each character
        i++;
    }
    dest[i] = '\0';  // Add null terminator
}

void stringConcat(char dest[], const char src[]) {
    int destLen = stringLength(dest);  // Find end of dest
    int i = 0;
    while (src[i] != '\0') {
        dest[destLen + i] = src[i];  // Append src to dest
        i++;
    }
    dest[destLen + i] = '\0';  // Add null terminator
}

int stringCompare(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] < str2[i]) return -1;  // str1 is less
        if (str1[i] > str2[i]) return 1;   // str1 is greater
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') return 0;  // Equal
    if (str1[i] == '\0') return -1;  // str1 is shorter
    return 1;  // str2 is shorter
}

// ==================== STRING SEARCH OPERATIONS ====================

int findChar(const char str[], char ch) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

int findSubstring(const char str[], const char substr[]) {
    int strLen = stringLength(str);
    int subLen = stringLength(substr);
    
    if (subLen == 0) return 0;  // Empty substring found at start
    if (subLen > strLen) return -1;  // Substring too long
    
    for (int i = 0; i <= strLen - subLen; i++) {
        int j = 0;
        while (j < subLen && str[i + j] == substr[j]) {  // Match characters
            j++;
        }
        if (j == subLen) {  // Full match found
            return i;
        }
    }
    return -1;  // Not found
}

// ==================== STRING MANIPULATION OPERATIONS ====================

void reverseString(char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {  // Swap from both ends
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {  // Check if lowercase
            str[i] = str[i] - 'a' + 'A';  // Convert to uppercase
        }
    }
}

void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {  // Check if uppercase
            str[i] = str[i] - 'A' + 'a';  // Convert to lowercase
        }
    }
}

// ==================== STRING ANALYSIS OPERATIONS ====================

int countVowels(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z') {  // Convert to lowercase
            ch = ch - 'A' + 'a';
        }
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {  // Check vowels
            count++;
        }
    }
    return count;
}

int countConsonants(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z') {  // Convert to lowercase
            ch = ch - 'A' + 'a';
        }
        if (ch >= 'a' && ch <= 'z' &&  // Check if letter
            ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {  // Not a vowel
            count++;
        }
    }
    return count;
}

int countWords(const char str[]) {
    int count = 0;
    int inWord = 0;  // Track if currently in a word
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n') {  // Non-whitespace
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

int isPalindrome(const char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {  // Compare from both ends
        if (str[i] != str[len - 1 - i]) {
            return 0;  // Not a palindrome
        }
    }
    return 1;  // Is a palindrome
}

// ==================== STRING UTILITY OPERATIONS ====================

void removeSpaces(char str[]) {
    int i = 0, j = 0;  // i reads, j writes
    while (str[i] != '\0') {
        if (str[i] != ' ') {  // Skip spaces
            str[j] = str[i];
            j++;
        }
        i++;
    }
    str[j] = '\0';  // Terminate string
}

void trimString(char str[]) {
    int start = 0;
    int len = stringLength(str);
    
    while (str[start] == ' ' || str[start] == '\t') {  // Skip leading whitespace
        start++;
    }
    
    int end = len - 1;
    while (end >= start && (str[end] == ' ' || str[end] == '\t')) {  // Skip trailing whitespace
        end--;
    }
    
    int i = 0;
    for (int j = start; j <= end; j++) {  // Copy trimmed string
        str[i] = str[j];
        i++;
    }
    str[i] = '\0';  // Terminate string
}

// ==================== ADVANCED STRING SEARCH ====================

int countOccurrences(const char str[], char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {  // Match found
            count++;
        }
    }
    return count;
}

int stringContains(const char str[], const char substr[]) {
    return findSubstring(str, substr) != -1;  // Returns 1 if found, 0 otherwise
}

// ==================== STRING MODIFICATION ====================

void stringNCopy(char dest[], const char src[], int n) {
    int i = 0;
    while (i < n && src[i] != '\0') {  // Copy up to n characters
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';  // Null terminate
}

void stringNConcat(char dest[], const char src[], int n) {
    int destLen = stringLength(dest);  // Find end of dest
    int i = 0;
    while (i < n && src[i] != '\0') {  // Append up to n characters
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';  // Null terminate
}

void replaceChar(char str[], char oldChar, char newChar) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == oldChar) {  // Found character to replace
            str[i] = newChar;
        }
    }
}

void insertString(char str[], const char insert[], int pos) {
    int strLen = stringLength(str);
    int insertLen = stringLength(insert);
    
    if (pos < 0 || pos > strLen) return;  // Validate position
    
    for (int i = strLen; i >= pos; i--) {  // Shift characters right
        str[i + insertLen] = str[i];
    }
    
    for (int i = 0; i < insertLen; i++) {  // Insert new string
        str[pos + i] = insert[i];
    }
}

// ==================== STRING EXTRACTION ====================

void substring(const char str[], int start, int length, char result[]) {
    int strLen = stringLength(str);
    
    if (start < 0 || start >= strLen || length <= 0) {  // Validate parameters
        result[0] = '\0';
        return;
    }
    
    int i = 0;
    while (i < length && str[start + i] != '\0') {  // Extract substring
        result[i] = str[start + i];
        i++;
    }
    result[i] = '\0';  // Null terminate
}

// ==================== STRING VALIDATION ====================

int isAlpha(const char str[]) {
    if (str[0] == '\0') return 0;  // Empty string
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {  // Not a letter
            return 0;
        }
    }
    return 1;  // All alphabetic
}

int isDigit(const char str[]) {
    if (str[0] == '\0') return 0;  // Empty string
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9')) {  // Not a digit
            return 0;
        }
    }
    return 1;  // All digits
}

int isAlphaNumeric(const char str[]) {
    if (str[0] == '\0') return 0;  // Empty string
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') ||  // Not letter or digit
              (str[i] >= 'A' && str[i] <= 'Z') || 
              (str[i] >= '0' && str[i] <= '9'))) {
            return 0;
        }
    }
    return 1;  // All alphanumeric
}

// ==================== CHARACTER TYPE CHECKING ====================

int isCharAlpha(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');  // Check if letter
}

int isCharDigit(char ch) {
    return ch >= '0' && ch <= '9';  // Check if digit
}

int isCharWhitespace(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';  // Check if whitespace
}

// ==================== STRING CONVERSION ====================

void intToString(int num, char str[]) {
    int i = 0;
    int isNegative = 0;
    
    if (num == 0) {  // Handle zero case
        str[0] = '0';
        str[1] = '\0';
        return;
    }
    
    if (num < 0) {  // Handle negative numbers
        isNegative = 1;
        num = -num;
    }
    
    while (num > 0) {  // Extract digits in reverse
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    
    if (isNegative) {  // Add minus sign
        str[i++] = '-';
    }
    
    str[i] = '\0';
    
    reverseString(str);  // Reverse to get correct order
}

int stringToInt(const char str[]) {
    int result = 0;
    int sign = 1;
    int i = 0;
    
    while (str[i] == ' ' || str[i] == '\t') {  // Skip whitespace
        i++;
    }
    
    if (str[i] == '-') {  // Handle sign
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    
    while (str[i] >= '0' && str[i] <= '9') {  // Convert digits
        result = result * 10 + (str[i] - '0');
        i++;
    }
    
    return result * sign;  // Apply sign
}

// ==================== STRING TOKENIZATION ====================

int splitString(const char str[], char delimiter, char tokens[][100], int maxTokens) {
    int tokenCount = 0;
    int tokenIndex = 0;
    
    for (int i = 0; str[i] != '\0' && tokenCount < maxTokens; i++) {
        if (str[i] == delimiter) {  // Found delimiter
            if (tokenIndex > 0) {  // Save current token
                tokens[tokenCount][tokenIndex] = '\0';
                tokenCount++;
                tokenIndex = 0;
            }
        } else {
            tokens[tokenCount][tokenIndex++] = str[i];  // Add to current token
        }
    }
    
    if (tokenIndex > 0 && tokenCount < maxTokens) {  // Save last token
        tokens[tokenCount][tokenIndex] = '\0';
        tokenCount++;
    }
    
    return tokenCount;
}

// ==================== STRING MANIPULATION ====================

void removeChar(char str[], char ch) {
    int i = 0, j = 0;  // i reads, j writes
    while (str[i] != '\0') {
        if (str[i] != ch) {  // Keep character if not matching
            str[j++] = str[i];
        }
        i++;
    }
    str[j] = '\0';  // Terminate string
}

void capitalizeWords(char str[]) {
    int capitalizeNext = 1;  // Flag for next character
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') {  // Whitespace found
            capitalizeNext = 1;
        } else if (capitalizeNext && str[i] >= 'a' && str[i] <= 'z') {  // Capitalize letter
            str[i] = str[i] - 'a' + 'A';
            capitalizeNext = 0;
        } else {
            capitalizeNext = 0;
        }
    }
}

void capitalizeFirst(char str[]) {
    if (str[0] >= 'a' && str[0] <= 'z') {  // Check if lowercase
        str[0] = str[0] - 'a' + 'A';  // Convert to uppercase
    }
}
