/*
 * TEAParser.h
 *
 *  Created on: 25-02-2013
 *      Author: Rafal Czaja
 */

#ifndef TEAPARSER_H_
#define TEAPARSER_H_
#include <map>
#include <string>
#include "TEAArch.h"
#include "TEALex.h"
class TEAInstruction {
public:
	TEAInstruction(unsigned int iNumber, int iArguments) :
			m_iNumber(iNumber), m_iArguments(iArguments) {
	}
private:
	unsigned int m_iNumber;
	int m_iArguments;
};
class TEAParser {
public:
	TEAParser();
	virtual ~TEAParser();
	void addToken(TEALex::state tokenType, const std::string& strTokenValue);
private:
	unsigned int m_iAddress;
	typedef std::map<std::string, TEAInstruction> InstructionMapType;
	InstructionMapType m_InstructionMap;
	typedef std::map<std::string, std::string> StringSymbolType;
	StringSymbolType m_StringSymbolMap;
	typedef std::map<std::string, unsigned int> SymbolMapType;
	SymbolMapType m_SymbolMap;
};

#endif /* TEAPARSER_H_ */
