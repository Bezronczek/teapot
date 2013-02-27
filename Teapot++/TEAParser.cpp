/*
 * TEAParser.cpp
 *
 *  Created on: 25-02-2013
 *      Author: Rafal Czaja
 */

#include "TEAParser.h"

TEAParser::TEAParser() :
		m_iAddress(0) {
	//Probably there is a need to read list available instruction from external resource
	TEAArch archTest("./arch.json");
}

TEAParser::~TEAParser() {
}

void TEAParser::addToken(TEALex::state tokenType,
		const std::string & strTokenValue) {
}

