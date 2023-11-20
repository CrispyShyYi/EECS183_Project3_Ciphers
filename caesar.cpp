/*
 * caesar.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Yu Jie Zhang, Jialiang Wu
 * zhngyj, alfredwu
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * This file contains the functions for caesar cipher
 */

#include "caesar.h"
#include <iostream>
#include "utility.h"
#include <cctype>
#include <string>
#include <algorithm>


char shiftAlphaCharacter(char c, int n){
    int val;
    int sub;
    if(isupper(c)){
        sub = 'A';
    }
    else{
        sub = 'a';
    }
    val = c - sub;
    if((val + n) < 0){
        val = (val + n) % 26;
        if(val == 0){
            return val + sub;
        }
        val += 26;
        val = val + sub;
        return val;
    }
    else{
        val = (val + n) % 26;
        val = val + sub;
        return val;
    }
}

string caesarCipher(string original, int key, bool encrypt){
    string newStr = "";
    if(encrypt){
        for (int i = 0; i < original.size(); i++) {
            if(isalpha(original.at(i))){
                original.at(i) = shiftAlphaCharacter(original.at(i), key);
            }
        }
    }
    else
        for (int i = 0; i < original.size(); i++) {
            if(isalpha(original.at(i))){
                original.at(i) = shiftAlphaCharacter(original.at(i), -1 * key);
            }
        }
    return original;
}
