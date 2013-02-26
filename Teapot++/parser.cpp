#include "parser.h"
#include <fstream>
#include <iostream>

void parseFile(const std::string& filepath) {
	std::ifstream parsedFile;
	parsedFile.open(filepath.c_str());
	std::string line;
	//system("cls"); In linux standard library there is no such thing like conio.h
	TEALex *pLex = new TEALex;
	TEAParser *pParser = new TEAParser;
	while (parsedFile.good()) {
		std::getline(parsedFile, line);
		pLex->feed(line);
		std::string token;
		TEALex::state tokenType;
		while ((tokenType = pLex->getToken(token)) != TEALex::state::NOOP) {

		}
		//	parseLine(line);
	}

	parsedFile.close();
}

std::vector<std::string> parseLine(const std::string& row) {
	std::vector<std::string> tokens;
	std::string token;
	bool bTokenization = false;
	for (unsigned int i = 0; i < row.length(); i++) {
		if ((row[i] == TOKEN_WHITESPACE) || (row[i] == TOKEN_TAB)) {
			if (bTokenization) {
				bTokenization = false;
				getToken(token);
				tokens.push_back(token);
				token.clear();
			}
			continue;
		} else {
			if (!bTokenization)
				bTokenization = true;
			token += row[i];
			if (i == row.length() - 1)
				tokens.push_back(token);
		}
		if (row[i] == TOKEN_COMMENT) {
			token.pop_back();
			tokens.push_back(token);
			break;
		}
	}
	for (int x = 0; x < tokens.size(); x++)
		std::cout << tokens[x] << std::endl;
	;
	return tokens;
}
;

TOKENS getToken(const std::string& param) {
//	Illegal operation
//	switch(param) {

//	}

}
;
