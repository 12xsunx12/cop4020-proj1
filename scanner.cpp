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
    initAll();
}

// param constructor
Scanner::Scanner(std::string fileName) {
    this->fileName = fileName;
    totalLines = 0;
    initAll();
}

bool Scanner::openFile() {
    ifs.open(fileName);
    if (!ifs.is_open()) {
        std::cout << "Error: file doesn't exist or couldn't be opened" << std::endl;
        return false;
    }
    return true;
}

void Scanner::nextLine() {
    std::string temp;
    std::getline(ifs, temp);
    setCurrentLine(temp);
    totalLines++;
}

std::string Scanner::clean(const std::string& input) {
    std::string result = input;

    // Remove whitespaces
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());

    // Remove newline characters
    result.erase(std::remove(result.begin(), result.end(), '\n'), result.end());

    return result;
}

bool Scanner::scanBegin(long unsigned int& currentLocation) {
    std::string tempStr;

    // Check if there are at least 5 characters remaining in currentLine
    if (currentLocation + 4 >= currentLine.length()) {
        return false;
    }

    // Check if the character at the current position is 'b'
    if (currentLine[currentLocation] != 'b') {
        return false;
    }

    // Create a substring with the next 5 characters
    tempStr = currentLine.substr(currentLocation, 5);

    // Check if this substring exists in the keywordTable
    if (keywordTable.count(tempStr) > 0) {
        // Create a token
        Token temp;
        temp.tokenType = keywordTable.find(tempStr)->second;
        temp.lexeme = tempStr;
        temp.lineNumber = -1; // figure out how to set line number later
        tokens.push_back(temp);
        return true;
    } else {
        return false;
    }
}

bool Scanner::scanEnd(long unsigned int& currentLocation) {
    std::string tempStr;

    // Check if there are at least 4 characters remaining in currentLine
    if (currentLocation + 3 >= currentLine.length()) {
        return false;
    }

    // Check if the characters at the current position form 'end.'
    if (currentLine[currentLocation] != 'e' || currentLine[currentLocation + 1] != 'n' || currentLine[currentLocation + 2] != 'd' || currentLine[currentLocation + 3] != '.') {
        return false;
    }

    // Create a substring with the next 4 characters
    tempStr = currentLine.substr(currentLocation, 4);

    // Check if this substring exists in the keywordTable
    if (keywordTable.count(tempStr) > 0) {
        // Create a token
        Token temp;
        temp.tokenType = keywordTable[tempStr];
        temp.lexeme = tempStr;
        temp.lineNumber = -1;   // figure out how to set line number later
        tokens.push_back(temp);
        return true;
    } else {
        return false;
    }
}

void Scanner::initAll() {
    initOpTable();
    initKeywordTable();
    initAlphabet();
    initDigits();
}

void Scanner::initOpTable() {
    opTable["lParen"]   = '(';
    opTable["rParen"]   = ')';
    opTable["lCurly"]   = '{';
    opTable["rCurly"]   = '}';
    opTable["plusSym"]  = '+';
    opTable["minusSym"] = '-';
    opTable["multSym"]  = '*';
    opTable["divSym"]   = '/';
    opTable["semi"]     = ';';
    opTable["comma"]    = ',';
}

void Scanner::initKeywordTable() {
    keywordTable["while"]    = "whileSym";
    keywordTable["return"]   = "returnSym";
    keywordTable["if"]       = "ifSym";
    keywordTable["else"]     = "elseSym";
    keywordTable["do"]       = "doSym";
    keywordTable["int"]      = "intSym";
    keywordTable["string"]   = "stringSym";
    keywordTable["begin"]    = "beginSym";
    keywordTable["end."]     = "endSym";
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

void Scanner::scan() {
    // open the file
    openFile(fileName);
    // iterate through every line in the file
    while (std::getline(ifs, currentLine)) {
        // remove all whitespaces and newlines from the string
        currentLine = clean(currentLine);

        std::cout << currentLine << std::endl;

        // begin iterating over every character in the string and feeding it into subsequent, more logical, scanner functions, that check for edge-cases
        for (long unsigned int i = 0; i < currentLine.length(); i++) {
            scanBegin(i);
            scanEnd(i);
        }
    }
}

void Scanner::test() {
    scan();
    printTokens();
}

bool Scanner::openFile(std::string fileName) {
    ifs.open(fileName);
    if (!ifs.is_open()) {
        std::cout << "Error: file doesn't exist or couldn't be opened" << std::endl;
        return false;
    }
    return true;
}

void Scanner::printTokens() {
    std::cout << "Size of Vector: " << tokens.size() << std::endl;
    for (long unsigned int i = 0; i < tokens.size(); i++) {
        std::cout << tokens.at(i).tokenType << std::endl;
    }
}
