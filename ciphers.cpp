/*
 * ciphers.cpp
 * Project UID e98fd45ccce9d7195e89e6171a5451f2
 *
 * Yu Jie Zhang, Jialiang Wu
 * zhngyj, alfredwu
 *
 * EECS 183: Project 3
 * Fall 2023
 *
 * Calling this file allows the user to use either Caesar or Vigenere or Polybius to cipher a message.
 */

#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <iostream>
#include <string>
#include <cctype>

using namespace std;
void ciphers() {
    string cipherCode;
    string encOrDec;
    string original;
    string key;
    int caesarKey;
    char grid[6][6];
    
    cout << "Choose a cipher (Caesar, Vigenere, or Polybius): " << endl;
    getline(cin, cipherCode);
    cipherCode = toUpperCase(cipherCode);

    // Decide whether cipher is valid
    if(cipherCode != "CAESAR" && cipherCode != "C" && cipherCode != "VIGENERE"
       && cipherCode != "V" && cipherCode != "POLYBIUS" && cipherCode != "P"){
        cout << "Invalid cipher!";
    }
    // Decide which encryption and print out the encrypted message
    else{
        cout << "Encrypt or decrypt: " << endl;
        getline(cin, encOrDec);
        encOrDec = toUpperCase(encOrDec);
        if(encOrDec != "ENCRYPT" && encOrDec != "DECRYPT"
           && encOrDec != "E" && encOrDec != "D"){
                cout << "Invalid mode!";
            }
        else{
            cout << "Enter a message: " << endl;
            getline(cin, original);
            if(cipherCode == "CAESAR" || cipherCode == "C"){
                cout << "What is your key: " << endl;
                cin >> caesarKey;
                if(encOrDec == "ENCRYPT" || encOrDec == "E"){
                    cout << "The encrypted message is: ";
                    cout << caesarCipher(original, caesarKey, 1);
                }
                else{
                    cout << "The decrypted message is: ";
                    cout << caesarCipher(original, caesarKey, 0);
                }
            }
            else if(cipherCode == "VIGENERE" || cipherCode == "V"){
                cout << "What is your key: " << endl;
                getline(cin, key);
                bool isNumber = true;
                int i = 0;
                while(i < key.size() && isNumber == true){
                    if(!isdigit(key.at(i))){
                        isNumber = true;
                    }
                    else{
                        isNumber = false;
                    }
                    i++;
                }
                if(isNumber){
                    if(encOrDec == "ENCRYPT" || encOrDec == "E"){
                        cout << "The encrypted message is: ";
                        cout << vigenereCipher(original, key, 1) << endl;
                    }
                    else{
                        cout << "The decrypted message is: ";
                        cout << vigenereCipher(original, key, 0) << endl;
                    }
                }
                else{
                    cout << "Invalid key!" << endl;
                }

            }
            else if(cipherCode == "POLYBIUS" || cipherCode == "P"){
                bool isStr = true;
                int i = 0;
                while(i < original.size() && isStr == true){
                    if((original.at(i) == 32) 
                       || (original.at(i) >= 48 && original.at(i) <= 57)
                       ||(original.at(i) >= 65 && original.at(i) <= 90)
                       || (original.at(i) >= 97 && original.at(i) <= 122)){
                        isStr = true;
                    }
                    else{
                        isStr = false;
                    }
                    i++;
                }
                for(int k = 0; k < original.size(); k++){
                    original.at(k) = toupper(original[k]);
                }
                if(isStr){
                    cout << "What is your key: " << endl;
                    getline(cin, key);
                    key = toUpperCase(key);
                    
                    if(encOrDec == "ENCRYPT" || encOrDec == "E"){
                        cout << "The encrypted message is: ";
                        cout << polybiusSquare(grid, key, original, 1) << endl;
                    }
                    else{
                        cout << "The decrypted message is: ";
                        cout << polybiusSquare(grid, key, original, 0) << endl;
                    }
                }
                else{
                    cout << "Invalid message!" << endl;
                }
            }
            else{
                cout << "Invalid cipher!!";
            }
        }
    }
}
