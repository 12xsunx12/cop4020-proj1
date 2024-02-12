#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_set>

enum TokenType {
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_ASSIGNMENT,
    TOKEN_BEGIN,
    TOKEN_END,
    TOKEN_COMMENT,
    TOKEN_UNKNOWN, // token was not recognized when scanned
    TOKEN_END_OF_FILE
};

struct Token {
    TokenType type;
    std::string lexeme;
    int line;
};

class Scanner {
private:
    std::ifstream inputFile; // source code file that we are scanning and turning into tokens
    int lineNumber; // what line we are on in the inputFile
    std::unordered_set<char> operators = {'+', '-', '*', '/', '=', '(', ')', ';'}; // very similar to dictionaries in python, set of all operations
    std::unordered_set<std::string> keywords = {"begin", "end"}; // very similar to dictionaries in python, detect if the file is at the top or bottom
    bool isComment = false; // is token a comment? = completely ignore it

    char getNextChar(); // retreive next lexeme in sequence of characters
    Token scanIdentifierOrKeyword(char firstChar); // is this 'begin' or 'end' or something else
    Token scanNumber(char firstChar); // is this a number?
    Token scanOperator(char firstChar); // is this an operator?
    Token scanComment(char firstChar); // is this a comment?

public:
    Scanner(const std::string& fileName); // constructor that takes in input file address
    Token getNextToken(); // return the next token in order
    std::vector<Token> getAllTokens(); // return all tokens, mostly for testing
};

#endif
