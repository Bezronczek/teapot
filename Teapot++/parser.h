#include <string>
#include <vector>
#include "TEALex.h"
void parseFile(const std::string& filepath);
//funkcja obslugujaca linie zaczynajace sie kropka
void special(char* token, char* param);
//funkcja obslugujca linie zaczynajaece sie malym znakiem
void command(char*  command, char* param);
//tokeny
enum TOKENS 
{
	TOKEN_WHITESPACE = ' ',
	TOKEN_TAB = '\t',
	TOKEN_SPECIAL = '.',
	TOKEN_COMMENT = ';',
	TOKEN_NEWLINE = '\n',
	TOKEN_MOVE,
	TOKEN_ADD
};
//parsowanie linijki
std::vector<std::string> parseLine(const std::string& line);

std::string clear_line(const std::string& line);

TOKENS getToken(const std::string& token);
