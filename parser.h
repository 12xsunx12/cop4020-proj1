/*      @Author:            Regan O'Donnell
 *      @Professor:         Dr. Bernd Owsnicki-Klewe
 *      @Course Title:      Programming Languages
 *      @Course Number:     COP4020 202401 */

/*      ~ Code Formatting ~
 *      1. #include
 *      2. class declaration
 *      3. private:
 *      4. public:
 *      5. #endif */

#ifndef PARSER_H
#define PARSER_H

#include <iostream>         // input and output
#include <fstream>          // file input and output
#include <unordered_map>    // similar to dictionaries in python; hashmaps
#include <unordered_set>    // O(1) lookup; slap the entire english alphabet and all 1-9 digits into a set
#include <algorithm>
#include <vector>

struct Token {
    std::string lexeme;
    std::string tokenType;
    int lineNumber;
};

class Parser {
    private:
        std::vector<Token> tokens;

    public:
};

#endif
