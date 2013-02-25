#include <iostream>
//#include <conio.h> Unable to use in linux
#include <string.h> // This library contains strcmp and other function which start from str and mem prefix
#include <string>
#include "parser.h"

#define TZX_MAIN_FILE "main.tzx";


int main(int argc, char** argv)
{
	char* file_path = TZX_MAIN_FILE;
	int c = 1;

	while (c < argc)
	{
		if(strcmp(argv[c], "-tzx") == 0)
		{
			if(++c >= argc)
			{
				std::cout << "No input file given" << std::endl;
				std::cout << "Parsing default file: main.tzx" << std::endl;
				parseFile(file_path);
				break;
			}
			else
			{
				file_path = argv[c];
				std::cout << "Parsing file: " << file_path << std::endl;
				parseFile(file_path);
			}

		}
		else
		{
			std::cout << "Unsupported operation " << argv[c] << std::endl;
			break;
		}

		++c;
	}
	//parseFile(file_path);
	//getch();
	return 0;
}
