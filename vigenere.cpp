/*
 * vigenere.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Jialiang Wu, Yu Jie Zhang
 * alfredwu, zhngyj
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * This file contains vigenereCipher that ciphers using the vigenere technique
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include <iostream>
#include <cctype>
#include <cmath>

string vigenereCipher(string original, string keyword, bool encrypt){
    string result = "";
    int keyLength = keyword.length();
    keyword = toUpperCase(keyword);
    int t = 0;
    for (int i = 0; i < original.size(); i++) {
        if (isalpha(original.at(i))) {
            while(!isalpha(keyword[t % keyLength])){
                t++;
            }
            int shift = keyword[t % keyLength] - 'A';
                if (isupper(original.at(i))){
                    // Encrypt;
                    if (encrypt) {
                        original.at(i) = (original.at(i) - 'A' + shift)
                        % 26 + 'A';
                    }
                    // Crack a code;
                    else {
                        original.at(i) = (original.at(i) - 'A' - shift + 26)
                        % 26 + 'A';
                    }
                }
                else if (islower(original.at(i))){
                    //Encrypt;
                    if (encrypt) {
                        original.at(i) = (original.at(i) - 'a' + shift)
                        % 26 + 'a';
                    }
                    // Crack a code;
                    else {
                        original.at(i) = (original.at(i) - 'a' - shift + 26)
                        % 26 + 'a';
                    }
                }
            t++;
        }
        result += original.at(i);
    }
return result;
    
}
