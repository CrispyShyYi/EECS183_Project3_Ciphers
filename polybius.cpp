/*
 * polybius.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Yu Jie Zhang, Jialiang Wu
 * zhngyj, alfredwu
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * This file contains all the functions required for polybius encryption
 */


#include "polybius.h"
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;


string mixKey(string key){
    key = key + ALNUM;
    string newStr = removeDuplicate(key);
    return newStr;
}

void fillGrid(char grid[SIZE][SIZE], string content){
    int count = 0;
    for(int row = 0; row < SIZE; row++){
        for(int col = 0; col < SIZE; col++){
            grid[row][col] = content.at(count);
            count++;
        }
    }
    return;
}

string findInGrid(char c, char grid[SIZE][SIZE]){
    string coord;
    for(int row = 0; row < SIZE; row++){
        for(int col = 0; col < SIZE; col++){
            if(grid[row][col] == c){
                coord += to_string(row);
                coord += to_string(col);
            }
        }
    }
    return coord;
}

string polybiusSquare(char grid[SIZE][SIZE], string key,
                      string original, bool encrypt){
    string newStr = "";
    int i;
    string encryptedNum = "";
    string decryptedWord = "";
    newStr = mixKey(key);
    fillGrid(grid, newStr);
    
    // encrypt
    if (encrypt){
            for(i = 0; i < original.size(); i++){
                if (isspace(original.at(i))){
                    encryptedNum += " ";
                }
                else {
                    encryptedNum += findInGrid(original.at(i), grid);
                }
            }
    return encryptedNum;
        }
        
    // decrypt;
    else{
        int row = 0;
        int col = 0;
        for (int i = 0; i < original.size() - 1;){
            if (isspace(original.at(i))){
                decryptedWord += " ";
                i++;
            }
            else{
                row = charToInt(original.at(i));
                col = charToInt(original.at(i + 1));
                decryptedWord = decryptedWord + grid[row][col];
                i += 2;
            }
        }
    return decryptedWord;
    }
    return "";
}
