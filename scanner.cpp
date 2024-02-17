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
}

// param constructor
Scanner::Scanner(std::string fileName) {
    this->fileName = fileName;
}

bool Scanner::openFile() {
    ifs.open(fileName);
    if (!ifs.is_open()) {
        std::cout << "Error: file doesn't exist or couldn't be opened" << std::endl;
        return false;
    }
    return true;
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

