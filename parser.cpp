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
    // for every token in the vector
    for (long unsigned int i = 0; i < tokens.size(); i++) {
        // if token ends with underscore...
        if (tokens.at(i).lexeme.back() == '_') {
            std::cout << "Error: Identifier ends with underscore on " << "Line: " << tokens.at(i).lineNumber << "\tIdentifier: " << tokens.at(i).lexeme << std::endl;
            return false;
        }

        // if token has two under-scores next to each other in it's name
        for (int j = 0; j < tokens.at(i).lexeme.length(); j++) {
            if (tokens.at(i).lexeme[j] == '_' && tokens.at(i).lexeme[j+1] == '_') {
                std::cout << "Error: Identifier has two consecutive underscores " << "Line: " << tokens.at(i).lineNumber << "\tIdentifier: " << tokens.at(i).lexeme << std::endl;
                return false;
            }
        }
    }

    return true;
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
