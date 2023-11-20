/*
 * utility.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Yu Jie Zhang, Jialiang Wu
 * zhngyj, alfredwu
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * This file contains utility functions used throughout the project
 */

#include "utility.h"
#include <cctype>
#include <string>
#include <iostream>
#include <algorithm>


string toUpperCase(string original) {
    for(int i = 0; i < original.size(); i++){
        original.at(i) = toupper(original.at(i));
    }
    return original;
}

string removeNonAlphas(string original){
    char a;
    int j = 0;
    string newStr;
    for(int i = 0; i < original.size(); i++){
        a = original.at(i);
        if(isalpha(a)){
            newStr += a;
            j++;
        }
    }
    return newStr;
}

string removeDuplicate(string original){
    string newStr = "";
    for(int i = 0; i < original.size(); i++){
        for(int j = i+1; j < original.size(); j++){
            if(original.at(j) == original.at(i)){
                original.at(j) = ' ';
            }
        }
    }
    for (int i = 0; i < original.size(); i++){
        if (!isspace(original.at(i))){
            newStr += original.at(i);
        }
    }
    return newStr;
}

int charToInt(char original) {
    if(original == '0'){
        return 0;
    }
    else if(original == '1'){
        return 1;
    }
    else if(original == '2'){
        return 2;
    }
    else if(original == '3'){
        return 3;
    }
    else if(original == '4'){
        return 4;
    }
    else if(original == '5'){
        return 5;
    }
    else if(original == '6'){
        return 6;
    }
    else if(original == '7'){
        return 7;
    }
    else if(original == '8'){
        return 8;
    }
    else{
        return 9;
    }
}

////////////////////////////////////////////////////////////////////////////////
// Do not touch code below. ////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

void printGrid(const char grid[SIZE][SIZE]) {
    for (int col = 0; col < SIZE; col++) {
        cout << " ---";
    }
    cout << endl;
    for (int row = 0; row < SIZE; row++) {
        cout << "| ";
        for (int col = 0; col < SIZE; col++) {
            cout << string(1, grid[row][col]) + " | ";
        }
        cout << endl;
        for (int col = 0; col < SIZE; col++) {
            cout << " ---";
        }
        cout << endl;
    }
}
