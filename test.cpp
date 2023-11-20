//
//  test.cpp
//  Project 3
//
//  Created by Yu Jie Zhang on 10/5/23.
//
// Yu Jie Zhang, Jialiang Wu
// zhngyj, alfredwu
//
// This file contains the test functions


#include "utility.h"
#include "caesar.h"
#include "vigenere.h"
#include "polybius.h"
#include <string>
#include <iostream>

using namespace std;

void testShiftAlphaCharacter();
void testToUpperCase();
void testRemoveNonAlphas();
void testRemoveDuplicate();
void testCharToInt();
void testCaesarcipher();
void testVigenereCipher();
void testFillGrid();
void testMixKey();
void testFindInGrid();
void testPolybiusSquare();

void startTests() {
    testShiftAlphaCharacter();
    testToUpperCase();
    testRemoveNonAlphas();
    testRemoveDuplicate();
    testCharToInt();
    testCaesarcipher();
    testVigenereCipher();
    testFillGrid();
    testMixKey();
    testFindInGrid();
    testPolybiusSquare();
    return;
}

void testShiftAlphaCharacter() {
    cout << "Now testing function ShiftAlphaCharacter()" << endl;
    cout << "Expected: 'a', Actual: " << shiftAlphaCharacter('a', 0) << endl;
    cout << "Expected: 'C', Actual: " << shiftAlphaCharacter('X', 5) << endl;
    cout << "Expected: 'd', Actual: " << shiftAlphaCharacter('b', 2) << endl;
    cout << "Expected: 'V', Actual: " << shiftAlphaCharacter('X', 50) << endl;
    cout << "Expectd: 'z', Actual: " << shiftAlphaCharacter('u', 5) 
    << endl << endl;

    cout << "Expected: 'u', Actual: " << shiftAlphaCharacter('z', -5) << endl;
    cout << "Expected: 'Q', Actual: " << shiftAlphaCharacter('A', -10) << endl;
    cout << "Expected: 'Q', Actual: " << shiftAlphaCharacter('D', -13) << endl;
    cout << "Expected: 'P', Actual: " << shiftAlphaCharacter('D', -12) << endl;
    cout << "Expected: 'S', Actual: " << shiftAlphaCharacter('D', -11) << endl;
    cout << "Expected: 'a', Actual: " << shiftAlphaCharacter('q', -42) << endl;
    cout << "Expected: 'a', Actual: " << shiftAlphaCharacter('f', -5) << endl;
    return;
}

void testToUpperCase(){
    cout << "Now testing function ToUpperCase()" << endl;
    cout << "Expected: 'WASSUP', Actual: " <<  toUpperCase("wassup") << endl;
    cout << "Expected: 'APPLE', Actual: " << toUpperCase("ApPlE") << endl;
    cout << "Expected: 'LET ME GO?', Actual: " << toUpperCase("lEt mE go?")
    << endl;
    return;
}

void testRemoveNonAlphas(){
    cout << "Now testing function RemoveNonAlphas()" << endl;
    cout << "Expected: 'EECS', Actual: " << removeNonAlphas("EECS 183!")
    << endl;
    cout << "Expected: 'Appletree', Actual: "
    << removeNonAlphas("Apple ?234   tree") << endl;
    cout << "Expected: 'Lemonseeds', Actual: " 
    << removeNonAlphas("Lemon seeds") << endl;
    return;
}

void testRemoveDuplicate(){
    cout << "Now testing function RemoveDuplicate()" << endl;
    cout << "Expected: ABCD, Actual: " << removeDuplicate("AAAABBCCD")
    << endl;
    cout << "Expected: HELOWRD, Actual: " << removeDuplicate("HELLOWORLD")
    << endl;
    cout << "Expected: ACBD, Actual: " << removeDuplicate("ACBD")
    << endl;
    return;
}

void testCharToInt(){
    cout << "Now testing function CharToInt()" << endl;
    cout << "Expected: '1', Actual: " << charToInt('1') << endl;
    cout << "Expected: '8', Actual: " << charToInt('8') << endl;
    return;
}

void testCaesarcipher(){
    cout << endl <<"Now testing function Caesarcipher()" << endl;
    cout << "Expected: Cuuj cu qj jxu Tyqw qj 11 f.c., Actual: " 
    << caesarCipher("Meet me at the Diag at 11 p.m.", 42, true) << endl;
    cout << endl << "------------" << endl;
    cout << "Olaf the Snowman: That's okay. I do."
    "Love is putting someone else's needs before yours.\n"
    << caesarCipher("Tqfk ymj Xstbrfs: Ymfy'x tpfd. N it."
    "Qtaj nx uzyynsl xtrjtsj jqxj'x sjjix gjktwj dtzwx.", 5, false) << endl;
    cout << "Tqfk ymj Xstbrfs: Ymfy'x tpfd. N it."
    "Qtaj nx uzyynsl xtrjtsj jqxj'x sjjix gjktwj dtzwx.\n"
    << caesarCipher("Olaf the Snowman: That's okay. I do. Love is"
    "putting someone else's needs before yours.", 5, true) << endl << endl;
    cout << "Expected: Meet me at the Diag at 11 p.m." << endl;
    cout << "Actual  : " << caesarCipher("Cuuj cu qj jxu Tyqw qj 11 f.c.",
                                         42, false)
    << endl << endl;
    return;
}

void testVigenereCipher(){
    cout << "Now testing function VigenereCipher()" << endl;
    cout << "Expected: Euyb dv ee lxy Lzrk ll 11 f.g., Actual: " 
    << vigenereCipher("Meet me at the Diag at 11 p.m.", "Squirrel!", true)
    << endl;
    cout << "Expected: u, Actual: " << vigenereCipher("e", "quirrel!", true)
    << endl;
    cout << "Expected: Meet me at the Diag at 11 p.m., Actual: "
    << vigenereCipher("Euyb dv ee lxy Lzrk ll 11 f.g.", "Squirrel!", false)
    << endl;
    return;
}

void testFillGrid(){
    char grid[6][6];
    cout << "Now testing function FillGrid()" << endl;
    cout << "Expected:       0   1   2   3   4   5 \n "
                       "   --- --- --- --- --- --- \n"
                       "0 | P | O | L | Y | B | I |\n"
                       "   --- --- --- --- --- --- \n"
                       "1 | U | S | A | C | D | E |\n"
                       "   --- --- --- --- --- --- \n"
                       "2 | F | G | H | J | K | M |\n"
                       "   --- --- --- --- --- --- \n"
                       "3 | N | Q | R | T | V | W |\n"
                       "   --- --- --- --- --- --- \n"
                       "4 | X | Z | 0 | 1 | 2 | 3 |\n"
                       "   --- --- --- --- --- --- \n"
                       "5 | 4 | 5 | 6 | 7 | 8 | 9 |\n"
                       "   --- --- --- --- --- --- \n"
    ", Actual: ";
    fillGrid(grid, ALNUM);
    printGrid(grid);
    cout << "0   1   2   3   4   5 \n "
    "   --- --- --- --- --- --- \n"
    "0 | P | O | L | Y | B | I |\n"
    "   --- --- --- --- --- --- \n"
    "1 | U | S | A | C | D | E |\n"
    "   --- --- --- --- --- --- \n"
    "2 | F | G | H | J | K | M |\n"
    "   --- --- --- --- --- --- \n"
    "3 | N | Q | R | T | V | W |\n"
    "   --- --- --- --- --- --- \n"
    "4 | X | Z | 0 | 1 | 2 | 3 |\n"
    "   --- --- --- --- --- --- \n"
    "5 | 4 | 5 | 6 | 7 | 8 | 9 |\n"
    "   --- --- --- --- --- --- \n";
    return;
}

void testMixKey(){
    cout << "Now testing function MixKey()" << endl;
    cout << "Expected: POLYBIUSACDEFGHJKMNQRTVWXZ0123456789" << endl;
    cout << "Actual  : "<< mixKey("POLYBIUS") << endl;
    return;
}

void testFindInGrid(){
    char grid[6][6];
    fillGrid(grid, ALNUM);
    cout << "Now testing function FindInGrid()" << endl;
    cout << "Expected: '21', Actual: " << findInGrid('G', grid) << endl;
    cout << endl << endl << "--------" << endl;
    return;
}

void testPolybiusSquare(){
    char grid[6][6];
    fillGrid(grid, ALNUM);
    cout << "Now testing function PolybiusSquare()" << endl;
    cout << "Expected: 15151311 435445 0511 332215 04151133" << endl;
    cout << "Actual  : " << polybiusSquare(grid, "POLYBIUS",
                                       "EECS 183 IS THE BEST", true) << endl;
    cout << "Expected: EECS 183 IS THE BEST" << endl;
    cout << "Actual  : " << polybiusSquare(grid, "183",
                       "11110533 000102 1533 341411 04113334", false) << endl;
    return;
}


