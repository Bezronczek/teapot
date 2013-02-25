#include <iostream>
//#include <conio.h> Unable to use in linux
#include <string.h> // This library contains strcmp and other function which start from str and mem prefix
#include <string>
#include <boost/program_options.hpp>
#include "parser.h"

#define TZX_MAIN_FILE "main.tzx";

int main(int argc, char** argv) {
	boost::program_options::options_description allowed("Allowed options");
	allowed.add_options()("help,h", "produce help message")("input-file,i",
			boost::program_options::value<std::string>(), "input file")(
			"output-file,o", boost::program_options::value<std::string>(),
			"output file");
	boost::program_options::positional_options_description p;
	p.add("input-file", -1);

	boost::program_options::variables_map vm;
	boost::program_options::store(
			boost::program_options::command_line_parser(argc, argv).options(
					allowed).positional(p).run(), vm);
	boost::program_options::notify(vm);

	if (vm.count("help")) {
		std::cout << "Teapot-asm compiler" << std::endl;
		std::cout << allowed << std::endl;
		return 0;
	}

	std::string strInputFile;
	std::string strOutputFile = "a.out";

	if (vm.count("input-file"))
		strInputFile = vm["input-file"].as<std::string>();
	if (vm.count("output-file"))
		strOutputFile = vm["output-file"].as<std::string>();

	parseFile(strInputFile);
	return 0;
}
