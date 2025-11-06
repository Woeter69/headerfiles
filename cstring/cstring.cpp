// String Operations Library
// Author: Pranjul Gupta

#include "cstring.h"

// ==================== BASIC STRING OPERATIONS ====================

int stringLength(const char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

void stringCopy(char dest[], const char src[]) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void stringConcat(char dest[], const char src[]) {
    int destLen = stringLength(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';
}

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

int findChar(const char str[], char ch) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            return i;
        }
    }
    return -1;
}

int findSubstring(const char str[], const char substr[]) {
    int strLen = stringLength(str);
    int subLen = stringLength(substr);
    
    if (subLen == 0) return 0;
    if (subLen > strLen) return -1;
    
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

void reverseString(char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        }
    }
}

void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

// ==================== STRING ANALYSIS OPERATIONS ====================

int countVowels(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
        }
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    return count;
}

int countConsonants(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch >= 'A' && ch <= 'Z') {
            ch = ch - 'A' + 'a';
        }
        if (ch >= 'a' && ch <= 'z' && 
            ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            count++;
        }
    }
    return count;
}

int countWords(const char str[]) {
    int count = 0;
    int inWord = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
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

int isPalindrome(const char str[]) {
    int len = stringLength(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;  // Not a palindrome
        }
    }
    return 1;  // Is a palindrome
}

// ==================== STRING UTILITY OPERATIONS ====================

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

void trimString(char str[]) {
    int start = 0;
    int len = stringLength(str);
    
    while (str[start] == ' ' || str[start] == '\t') {
        start++;
    }
    
    int end = len - 1;
    while (end >= start && (str[end] == ' ' || str[end] == '\t')) {
        end--;
    }
    
    int i = 0;
    for (int j = start; j <= end; j++) {
        str[i] = str[j];
        i++;
    }
    str[i] = '\0';
}

// ==================== ADVANCED STRING SEARCH ====================

int findLastChar(const char str[], char ch) {
    int lastIndex = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            lastIndex = i;
        }
    }
    return lastIndex;
}

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

int countOccurrences(const char str[], char ch) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch) {
            count++;
        }
    }
    return count;
}

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

int stringCompareIgnoreCase(const char str1[], const char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        char c1 = str1[i];
        char c2 = str2[i];
        
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

int stringEndsWith(const char str[], const char suffix[]) {
    int strLen = stringLength(str);
    int suffixLen = stringLength(suffix);
    
    if (suffixLen > strLen) return 0;
    
    int strStart = strLen - suffixLen;
    for (int i = 0; i < suffixLen; i++) {
        if (str[strStart + i] != suffix[i]) {
            return 0;
        }
    }
    return 1;
}

int stringContains(const char str[], const char substr[]) {
    return findSubstring(str, substr) != -1;
}

// ==================== STRING MODIFICATION ====================

void stringNCopy(char dest[], const char src[], int n) {
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void stringNConcat(char dest[], const char src[], int n) {
    int destLen = stringLength(dest);
    int i = 0;
    while (i < n && src[i] != '\0') {
        dest[destLen + i] = src[i];
        i++;
    }
    dest[destLen + i] = '\0';
}

void replaceChar(char str[], char oldChar, char newChar) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == oldChar) {
            str[i] = newChar;
        }
    }
}

void replaceSubstring(char str[], const char oldSub[], const char newSub[], char result[]) {
    int pos = findSubstring(str, oldSub);
    
    if (pos == -1) {
        stringCopy(result, str);
        return;
    }
    
    int oldLen = stringLength(oldSub);
    int newLen = stringLength(newSub);
    int i = 0, j = 0;
    
    while (i < pos) {
        result[j++] = str[i++];
    }
    
    for (int k = 0; k < newLen; k++) {
        result[j++] = newSub[k];
    }
    
    i += oldLen;
    while (str[i] != '\0') {
        result[j++] = str[i++];
    }
    result[j] = '\0';
}

void insertString(char str[], const char insert[], int pos) {
    int strLen = stringLength(str);
    int insertLen = stringLength(insert);
    
    if (pos < 0 || pos > strLen) return;
    
    for (int i = strLen; i >= pos; i--) {
        str[i + insertLen] = str[i];
    }
    
    for (int i = 0; i < insertLen; i++) {
        str[pos + i] = insert[i];
    }
}

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

void leftString(const char str[], int n, char result[]) {
    substring(str, 0, n, result);
}

void rightString(const char str[], int n, char result[]) {
    int len = stringLength(str);
    if (n > len) n = len;
    substring(str, len - n, n, result);
}

void midString(const char str[], int start, int end, char result[]) {
    if (start < 0 || end < start) {
        result[0] = '\0';
        return;
    }
    substring(str, start, end - start + 1, result);
}

// ==================== STRING PADDING AND ALIGNMENT ====================

void padLeft(char str[], int totalWidth, char padChar) {
    int len = stringLength(str);
    if (len >= totalWidth) return;
    
    int padCount = totalWidth - len;
    
    for (int i = len; i >= 0; i--) {
        str[i + padCount] = str[i];
    }
    
    for (int i = 0; i < padCount; i++) {
        str[i] = padChar;
    }
}

void padRight(char str[], int totalWidth, char padChar) {
    int len = stringLength(str);
    if (len >= totalWidth) return;
    
    for (int i = len; i < totalWidth; i++) {
        str[i] = padChar;
    }
    str[totalWidth] = '\0';
}

void centerString(char str[], int totalWidth, char padChar) {
    int len = stringLength(str);
    if (len >= totalWidth) return;
    
    int totalPad = totalWidth - len;
    int leftPad = totalPad / 2;
    int rightPad = totalPad - leftPad;
    
    for (int i = len; i >= 0; i--) {
        str[i + leftPad] = str[i];
    }
    
    for (int i = 0; i < leftPad; i++) {
        str[i] = padChar;
    }
    
    for (int i = 0; i < rightPad; i++) {
        str[len + leftPad + i] = padChar;
    }
    str[totalWidth] = '\0';
}

// ==================== STRING VALIDATION ====================

int isAlpha(const char str[]) {
    if (str[0] == '\0') return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) {
            return 0;
        }
    }
    return 1;
}

int isDigit(const char str[]) {
    if (str[0] == '\0') return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            return 0;
        }
    }
    return 1;
}

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

int isLowerCase(const char str[]) {
    if (str[0] == '\0') return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            return 0;
        }
    }
    return 1;
}

int isUpperCase(const char str[]) {
    if (str[0] == '\0') return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            return 0;
        }
    }
    return 1;
}

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

int isCharAlpha(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int isCharDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

int isCharAlphaNumeric(char ch) {
    return isCharAlpha(ch) || isCharDigit(ch);
}

int isCharLower(char ch) {
    return ch >= 'a' && ch <= 'z';
}

int isCharUpper(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

int isCharWhitespace(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == '\r';
}

// ==================== STRING CONVERSION ====================

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
    
    while (num > 0) {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    
    if (isNegative) {
        str[i++] = '-';
    }
    
    str[i] = '\0';
    
    reverseString(str);
}

int stringToInt(const char str[]) {
    int result = 0;
    int sign = 1;
    int i = 0;
    
    while (str[i] == ' ' || str[i] == '\t') {
        i++;
    }
    
    if (str[i] == '-') {
        sign = -1;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    
    return result * sign;
}

void floatToString(float num, char str[], int precision) {
    int intPart = (int)num;
    float fracPart = num - intPart;
    
    if (fracPart < 0) fracPart = -fracPart;
    
    intToString(intPart, str);
    
    int len = stringLength(str);
    str[len++] = '.';
    
    for (int i = 0; i < precision; i++) {
        fracPart *= 10;
        int digit = (int)fracPart;
        str[len++] = digit + '0';
        fracPart -= digit;
    }
    
    str[len] = '\0';
}

float stringToFloat(const char str[]) {
    float result = 0.0f;
    float sign = 1.0f;
    int i = 0;
    
    if (str[i] == '-') {
        sign = -1.0f;
        i++;
    } else if (str[i] == '+') {
        i++;
    }
    
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10.0f + (str[i] - '0');
        i++;
    }
    
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
    
    if (tokenIndex > 0 && tokenCount < maxTokens) {
        tokens[tokenCount][tokenIndex] = '\0';
        tokenCount++;
    }
    
    return tokenCount;
}

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

int countDigits(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            count++;
        }
    }
    return count;
}

int countAlpha(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            count++;
        }
    }
    return count;
}

int countSpaces(const char str[]) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            count++;
        }
    }
    return count;
}

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

void removeSubstring(char str[], const char substr[]) {
    int pos = findSubstring(str, substr);
    if (pos == -1) return;
    
    int subLen = stringLength(substr);
    deleteChars(str, pos, subLen);
}

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

void swapCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 'a' + 'A';
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

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

void capitalizeFirst(char str[]) {
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 'a' + 'A';
    }
}

// ==================== STRING ROTATION AND SHIFTING ====================

void rotateLeft(char str[], int positions) {
    int len = stringLength(str);
    if (len == 0) return;
    
    positions = positions % len;
    if (positions == 0) return;
    
    for (int i = 0; i < positions / 2; i++) {
        char temp = str[i];
        str[i] = str[positions - 1 - i];
        str[positions - 1 - i] = temp;
    }
    
    for (int i = 0; i < (len - positions) / 2; i++) {
        char temp = str[positions + i];
        str[positions + i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
    
    reverseString(str);
}

void rotateRight(char str[], int positions) {
    int len = stringLength(str);
    if (len == 0) return;
    
    positions = positions % len;
    rotateLeft(str, len - positions);
}

void shuffleString(char str[]) {
    int len = stringLength(str);
    
    for (int i = 0; i < len; i++) {
        int j = (i * 7 + 13) % len;
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// ==================== STRING ENCODING ====================

void encodeROT13(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = 'a' + (str[i] - 'a' + 13) % 26;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = 'A' + (str[i] - 'A' + 13) % 26;
        }
    }
}

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

void reverseWords(char str[]) {
    reverseString(str);
    
    int start = 0;
    int len = stringLength(str);
    
    for (int i = 0; i <= len; i++) {
        if (str[i] == ' ' || str[i] == '\0') {
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

int stringEquals(const char str1[], const char str2[]) {
    return stringCompare(str1, str2) == 0;
}

int stringEqualsIgnoreCase(const char str1[], const char str2[]) {
    return stringCompareIgnoreCase(str1, str2) == 0;
}

int longestCommonPrefix(const char str1[], const char str2[], char result[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        result[i] = str1[i];
        i++;
    }
    result[i] = '\0';
    return i;
}

int longestCommonSuffix(const char str1[], const char str2[], char result[]) {
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);
    int i = 0;
    
    while (i < len1 && i < len2 && str1[len1 - 1 - i] == str2[len2 - 1 - i]) {
        i++;
    }
    
    for (int j = 0; j < i; j++) {
        result[j] = str1[len1 - i + j];
    }
    result[i] = '\0';
    
    return i;
}

// ==================== STRING METRICS ====================

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

int levenshteinDistance(const char str1[], const char str2[]) {
    int len1 = stringLength(str1);
    int len2 = stringLength(str2);
    
    int dp[100][100];  // Assuming max string length of 100
    
    for (int i = 0; i <= len1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= len2; j++) {
        dp[0][j] = j;
    }
    
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
