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

#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>         // input and output
#include <fstream>          // file input and output
#include <unordered_map>    // similar to dictionaries in python; hashmaps
#include <unordered_set>    // O(1) lookup; slap the entire english alphabet and all 1-9 digits into a set

class Scanner {
    private:
        std::unordered_map<std::string, char> opTable;           // map & keys to all acceptable operators; (, ), {, }, +, -, *, /
        std::unordered_map<std::string, std::string> keywordTable;      // map & keys to all acceptable keywords; if, else, while, return...
        std::unordered_set<char> ALPHABET;      // the entire english alphabet, a-z and A-Z
        std::unordered_set<int> DIGITS;         // 1-9 numbers
        std::string fileName;                   // name of the source code file
        std::ifstream ifs;                      // input file stream; read input file
        std::string currentLine;                // std::getline(ifs, currentLine) ; the `current` line in our source code file
        int totalLines;                         // count how many lines are in the `source code` file; incremented in `nextLine()`

        bool openFile();            // using `fileName`, attempts to open given `source code` file
        std::string nextLine();     // grabs the `next line` in the file and sets it equal to currentLine

        void initAll();             // run all `init` functions
        void initOpTable();         // init. the opTable hashmap
        void initKeywordTable();    // init. the keywordTable hashmap
        void initAlphabet();        // init. the ALPHABET set
        void initDigits();          // init. the DIGITS set

        std::string getFileName();
        std::string getCurrentLine();
        void setFileName(std::string a);
        void setCurrentLine(std::string a);

    public:
        Scanner();                              // default
        Scanner(std::string fileName);          // param
        void test();                            // used for testing priv. functions in main
        bool openFile(std::string fileName);    // open a `source code` file given a string; sets fileName to input as well
};

#endif
