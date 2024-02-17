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

#include "scanner.h"

// default constructor
Scanner::Scanner() {
    this->fileName = "";
    totalLines = 0;
}

// param constructor
Scanner::Scanner(std::string fileName) {
    this->fileName = fileName;
    totalLines = 0;
}

bool Scanner::openFile() {
    ifs.open(fileName);
    if (!ifs.is_open()) {
        std::cout << "Error: file doesn't exist or couldn't be opened" << std::endl;
        return false;
    }
    return true;
}

std::string Scanner::nextLine() {
    std::string temp;
    std::getline(ifs, temp);
    setCurrentLine(temp);
    totalLines++;
    return getCurrentLine();
}

void Scanner::initAll() {
    initOpTable();
    initKeywordTable();
    initAlphabet();
    initDigits();
}

void Scanner::initOpTable() {
    opTable["lParen"] = '(';
    opTable["rParen"] = ')';
    opTable["lCurly"] = '{';
    opTable["rCurly"] = '}';
    opTable["plusSym"] = '+';
    opTable["minusSym"] = '-';
    opTable["multSym"] = '*';
    opTable["divSym"] = '/';
    opTable["semi"] = ';';
    opTable["comma"] = ',';
}

void Scanner::initKeywordTable() {
    keywordTable["whileSym"] = "while";
    keywordTable["returnSym"] = "return";
    keywordTable["ifSym"] = "if";
    keywordTable["elseSym"] = "else";
    keywordTable["doSym"] = "do";
    keywordTable["intSym"] = "int";
    keywordTable["stringSym"] = "string";
}

void Scanner::initAlphabet() {
    // all lower case letters
    for (int i = 'a'; i < 'z'; i++){
        ALPHABET.insert(i);
    }

    // all uppercase letters
    for (int i = 'A'; i < 'Z'; i++){
        ALPHABET.insert(i);
    }
}

void Scanner::initDigits() {
    // all digits 0-9
    for (int i = 0; i < 10; i++){
        DIGITS.insert(i);
    }
}

std::string Scanner::getFileName() {
    return this->fileName;
}

std::string Scanner::getCurrentLine() {
    return this->currentLine;
}

void Scanner::setFileName(std::string a){
    this->fileName = a;
}

void Scanner::setCurrentLine(std::string a) {
    this->currentLine = a;
}

void Scanner::test() {
    initDigits();

    for (int a : DIGITS){
        std:: cout << a << std::endl;
    }
}

bool Scanner::openFile(std::string fileName) {
    ifs.open(fileName);
    if (!ifs.is_open()) {
        std::cout << "Error: file doesn't exist or couldn't be opened" << std::endl;
        return false;
    }
    return true;
}

