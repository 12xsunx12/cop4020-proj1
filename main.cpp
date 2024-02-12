#include "scanner.h"

int main() {
    Scanner s("example-source-code-inputs/a1");

    std::vector<Token> allTokens = s.getAllTokens();

    for (long unsigned int i = 0; i < allTokens.size(); i++) {
        const Token& token = allTokens[i];
        std::cout << "Type: " << token.type << ", Lexeme: " << token.lexeme << ", Line: " << token.lineNumber << std::endl;
    }

    return 0;
}
