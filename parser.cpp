/*      @Author:            Regan O'Donnell
 *      @Professor:         Dr. Bernd Owsnicki-Klewe
 *      @Course Title:      Programming Languages
 *      @Course Number:     COP4020 202401 */

/*      ~ Code Formatting ~
 *      1. #include
 *      2. public default constructor
 *      3. public param constructor
 *      4. private functions
 *      5. (private) getters & setters
 *      6. public functions */

#include "parser.h"

Parser::Parser(std::vector<Token> tokens) {
    this->tokens = tokens;
}

void Parser::parseParen() {
    int lParen = 0, rParen = 0;

    // count all parens
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens.at(i).tokenType == "lParen") lParen += 1;
        if (tokens.at(i).tokenType == "rParen") rParen += 1;
    }

    // check to see if they're the same number
    if (lParen != rParen) {
        std::cout << "Error: paren" << std::endl;
    }
}

bool Parser::parseIdentifier() {
    // determine return value
    bool torf = true;

    // for every token in the vector
    for (long unsigned int i = 0; i < tokens.size(); i++) {

        // if token ends with underscore...
        std::cout << tokens.at(i).lexeme << std::endl;
        if (tokens.at(i).lexeme[tokens.at(i).lexeme.length()] == '_') {
            std::cout << "Error: ends with underscore\t" << "Line: " << tokens.at(i).lineNumber;
            torf = false;
        }
    }

    return torf;
}

void Parser::parse() {
    parseParen();
    parseIdentifier();
}

void Parser::printTokens() {
    std::cout << "Size of Vector: " << tokens.size() << std::endl;
    for (long unsigned int i = 0; i < tokens.size(); i++) {
        std::cout << "Token: \t" << tokens.at(i).tokenType << "    \tLexeme: \t" << tokens.at(i).lexeme << "\tLine Number:\t" << tokens.at(i).lineNumber << std::endl;
    }
}
