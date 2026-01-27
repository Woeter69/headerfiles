#include <iostream>
#include "cstring.h"

using namespace std;

void testBasicOperations() {
    cout << "\n========== BASIC STRING OPERATIONS ==========\n";
    
    // stringLength
    char str1[] = "Hello World";
    cout << "String: \"" << str1 << "\"\n";
    cout << "Length: " << stringLength(str1) << "\n\n";
    
    // stringCopy
    char str2[50];
    stringCopy(str2, str1);
    cout << "Copied string: \"" << str2 << "\"\n\n";
    
    // stringConcat
    char str3[100] = "Hello";
    stringConcat(str3, " World");
    cout << "Concatenated: \"" << str3 << "\"\n\n";
    
    // stringCompare
    char s1[] = "apple";
    char s2[] = "banana";
    cout << "Compare \"" << s1 << "\" and \"" << s2 << "\": " << stringCompare(s1, s2) << "\n";
}

void testSearchOperations() {
    cout << "\n========== STRING SEARCH OPERATIONS ==========\n";
    
    char text[] = "Hello World Programming";
    
    // findChar
    cout << "Text: \"" << text << "\"\n";
    cout << "Find 'W': Index " << findChar(text, 'W') << "\n\n";
    
    // findSubstring
    cout << "Find \"World\": Index " << findSubstring(text, "World") << "\n\n";
    
    // countOccurrences
    cout << "Count 'o': " << countOccurrences(text, 'o') << " times\n\n";
    
    // stringContains
    cout << "Contains \"Program\": " << (stringContains(text, "Program") ? "Yes" : "No") << "\n";
}

void testManipulation() {
    cout << "\n========== STRING MANIPULATION ==========\n";
    
    // reverseString
    char str1[] = "Hello";
    cout << "Original: \"" << str1 << "\"\n";
    reverseString(str1);
    cout << "Reversed: \"" << str1 << "\"\n\n";
    
    // toUpperCase
    char str2[] = "hello world";
    cout << "Original: \"" << str2 << "\"\n";
    toUpperCase(str2);
    cout << "Uppercase: \"" << str2 << "\"\n\n";
    
    // toLowerCase
    char str3[] = "HELLO WORLD";
    cout << "Original: \"" << str3 << "\"\n";
    toLowerCase(str3);
    cout << "Lowercase: \"" << str3 << "\"\n\n";
    
    // trimString
    char str4[] = "   Hello World   ";
    cout << "Original: \"" << str4 << "\"\n";
    trimString(str4);
    cout << "Trimmed: \"" << str4 << "\"\n\n";
    
    // removeSpaces
    char str5[] = "H e l l o";
    cout << "Original: \"" << str5 << "\"\n";
    removeSpaces(str5);
    cout << "No spaces: \"" << str5 << "\"\n\n";
    
    // replaceChar
    char str6[] = "Hello World";
    cout << "Original: \"" << str6 << "\"\n";
    replaceChar(str6, 'o', '0');
    cout << "Replace 'o' with '0': \"" << str6 << "\"\n\n";
    
    // capitalizeWords
    char str7[] = "hello world programming";
    cout << "Original: \"" << str7 << "\"\n";
    capitalizeWords(str7);
    cout << "Capitalized: \"" << str7 << "\"\n\n";
    
    // capitalizeFirst
    char str8[] = "hello";
    cout << "Original: \"" << str8 << "\"\n";
    capitalizeFirst(str8);
    cout << "First capitalized: \"" << str8 << "\"\n";
}

void testAnalysis() {
    cout << "\n========== STRING ANALYSIS ==========\n";
    
    char text[] = "Hello World 2024";
    cout << "Text: \"" << text << "\"\n\n";
    
    cout << "Vowels: " << countVowels(text) << "\n";
    cout << "Consonants: " << countConsonants(text) << "\n";
    cout << "Words: " << countWords(text) << "\n\n";
    
    // isPalindrome
    char pal1[] = "racecar";
    char pal2[] = "hello";
    cout << "\"" << pal1 << "\" is palindrome: " << (isPalindrome(pal1) ? "Yes" : "No") << "\n";
    cout << "\"" << pal2 << "\" is palindrome: " << (isPalindrome(pal2) ? "Yes" : "No") << "\n";
}

void testModification() {
    cout << "\n========== STRING MODIFICATION ==========\n";
    
    // stringNCopy
    char dest1[50];
    stringNCopy(dest1, "Hello World", 5);
    cout << "Copy first 5 chars: \"" << dest1 << "\"\n\n";
    
    // stringNConcat
    char dest2[50] = "Hello";
    stringNConcat(dest2, " World!", 6);
    cout << "Concat first 6 chars: \"" << dest2 << "\"\n\n";
    
    // insertString
    char dest3[100] = "Hello World";
    cout << "Original: \"" << dest3 << "\"\n";
    insertString(dest3, "Beautiful ", 6);
    cout << "After insert: \"" << dest3 << "\"\n\n";
    
    // removeChar
    char str[] = "Hello World";
    cout << "Original: \"" << str << "\"\n";
    removeChar(str, 'l');
    cout << "Remove 'l': \"" << str << "\"\n";
}

void testExtraction() {
    cout << "\n========== STRING EXTRACTION ==========\n";
    
    char text[] = "Hello World Programming";
    char result[50];
    
    cout << "Text: \"" << text << "\"\n\n";
    
    substring(text, 6, 5, result);
    cout << "Substring(6, 5): \"" << result << "\"\n";
}

void testValidation() {
    cout << "\n========== STRING VALIDATION ==========\n";
    
    char str1[] = "Hello";
    char str2[] = "12345";
    char str3[] = "Hello123";
    
    cout << "\"" << str1 << "\" is alpha: " << (isAlpha(str1) ? "Yes" : "No") << "\n";
    cout << "\"" << str2 << "\" is digit: " << (isDigit(str2) ? "Yes" : "No") << "\n";
    cout << "\"" << str3 << "\" is alphanumeric: " << (isAlphaNumeric(str3) ? "Yes" : "No") << "\n\n";
    
    // Character validation
    cout << "Character 'A' is alpha: " << (isCharAlpha('A') ? "Yes" : "No") << "\n";
    cout << "Character '5' is digit: " << (isCharDigit('5') ? "Yes" : "No") << "\n";
    cout << "Character ' ' is whitespace: " << (isCharWhitespace(' ') ? "Yes" : "No") << "\n";
}

void testConversion() {
    cout << "\n========== STRING CONVERSION ==========\n";
    
    // intToString
    char buffer[20];
    intToString(12345, buffer);
    cout << "Integer 12345 to string: \"" << buffer << "\"\n";
    
    intToString(-678, buffer);
    cout << "Integer -678 to string: \"" << buffer << "\"\n\n";
    
    // stringToInt
    int num1 = stringToInt("42");
    int num2 = stringToInt("-123");
    cout << "String \"42\" to int: " << num1 << "\n";
    cout << "String \"-123\" to int: " << num2 << "\n";
}

void testTokenization() {
    cout << "\n========== STRING TOKENIZATION ==========\n";
    
    char text[] = "apple,banana,cherry,date,elderberry";
    char tokens[10][100];
    
    cout << "Text: \"" << text << "\"\n";
    cout << "Split by ',': \n";
    
    int count = splitString(text, ',', tokens, 10);
    cout << "Found " << count << " tokens:\n";
    for (int i = 0; i < count; i++) {
        cout << "  " << (i+1) << ". \"" << tokens[i] << "\"\n";
    }
}

int main() {
    cout << "===============================================\n";
    cout << "    CSTRING LIBRARY DEMONSTRATION\n";
    cout << "    Author: Pranjul Gupta\n";
    cout << "===============================================\n";
    
    testBasicOperations();
    testSearchOperations();
    testManipulation();
    testAnalysis();
    testModification();
    testExtraction();
    testValidation();
    testConversion();
    testTokenization();
    
    cout << "\n===============================================\n";
    cout << "    ALL TESTS COMPLETED SUCCESSFULLY!\n";
    cout << "===============================================\n";
    
    return 0;
}
