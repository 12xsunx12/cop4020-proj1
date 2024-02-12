#include "scanner.h"

// constructor, takes in fileName containing source code
Scanner::Scanner(const std::string& fileName) {
    inputFile.open(fileName);
    if (!inputFile.is_open()) std::cout << "Error: couldn't open file" << std::endl;
}

// get the next char from the file
char Scanner::getNextChar() {
    return inputFile.get();
}

// after getting the next char in the file, scan this character and determine...
// if the look-ahead is going to be a comment, number, keyword, identifier, ...
// end-of-file, operator, or undefined token
Token Scanner::getNextToken() {
    char nextChar = getNextChar();

    while (isspace(nextChar)) {
        if (nextChar == '\n') lineNumber++;
        nextChar = getNextChar();
    }

    if (nextChar == '~') return scanComment(nextChar);

    if (isdigit(nextChar)) return scanNumber(nextChar);

    if (isalpha(nextChar) || nextChar == '_') return scanIdentifierOrKeyword(nextChar);

    if (operators.find(nextChar) != operators.end()) return scanOperator(nextChar);

    if (nextChar == EOF) return {TOKEN_END_OF_FILE, "", lineNumber};

    return {TOKEN_UNKNOWN, std::string(1, nextChar), lineNumber};
}

// detect if the scanner is at the beginning or end of the file
// @param char firstChar
// @return Token (either beginning of file or identifier)
Token Scanner::scanIdentifierOrKeyword(char firstChar) {
    std::string lexeme(1, firstChar);
    char nextChar = getNextChar();
    while (isalnum(nextChar) || nextChar == '_') {
        lexeme += nextChar;
        nextChar = getNextChar();
    }
    inputFile.putback(nextChar);

    if (keywords.find(lexeme) != keywords.end()) {
        return {TOKEN_BEGIN, lexeme, lineNumber};
    } else {
        return {TOKEN_IDENTIFIER, lexeme, lineNumber};
    }
}

// determine if the look-ahead is a digit and return constructed token of this digit
// @param char firstChar - first character in the look-ahead
// @return Token (is a constructed lexeme; digit)
Token Scanner::scanNumber(char firstChar) {
    std::string lexeme(1, firstChar); // initialize string with first char
    char nextChar = getNextChar(); // get nextChar in the sequence
    while (isdigit(nextChar)) { // determine if this char is a digit
        lexeme += nextChar; // append digit to lexeme
        nextChar = getNextChar(); // get nextChar in the sequence and repeat
    }
    inputFile.putback(nextChar); // return the ifstream to the original place we started
    return {TOKEN_NUMBER, lexeme, lineNumber}; // return token that is a digit
}

// deteremine if the look-ahead is an operation
// @param char firstChar - first character in the look-ahead
// @return Token (is a constructed lexeme; operation)
Token Scanner::scanOperator(char firstChar) {
    std::string lexeme(1, firstChar);
    return {TOKEN_OPERATOR, lexeme, lineNumber};
}

// determine if the look-ahead is a comment, if so, ignore it
// @param char firstChar - first character in the look-ahead
// @return Token (is a constructed lexeme; comment code)
Token Scanner::scanComment(char firstChar) {
    std::string lexeme(1, firstChar);
    char nextChar = getNextChar();
    while (nextChar != '\n' && nextChar != EOF) {
        lexeme += nextChar;
        nextChar = getNextChar();
    }
    lineNumber++;
    return {TOKEN_COMMENT, lexeme, lineNumber};
}

// return a vector containing all tokens constructed from the source-code file
// @return tokens, a vector containing ALL tokens
std::vector<Token> Scanner::getAllTokens() {
    std::vector<Token> tokens;
    Token token = getNextToken();
    while (token.type != TOKEN_END_OF_FILE) {
        tokens.push_back(token);
        token = getNextToken();
    }
    return tokens;
}
