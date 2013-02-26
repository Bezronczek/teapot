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
#include <fstream>
#include <iostream>
#include "json/json.h"
#include "TEALex.h"
class TEASerialize {
public:
	TEASerialize() {
	}

	virtual int serialize() = 0;
};

class TEARegister: public TEASerialize {
public:
	enum RegSize {
		B64 = 0, B32 = 1, B16 = 2, B8 = 3
	};
	TEARegister(unsigned int id, int size) :
			m_iId(id), m_iRegSize(size) {
	}
	virtual ~TEARegister() {
	}
	int serialize() {

		return 0;
	}
private:
	unsigned int m_iId;
	int m_iRegSize;
};
template<class T>
class TEAHelper {
public:
	TEAHelper(std::map<std::string, T> *pMap) :
			m_pMap(pMap) {
	}
	bool generateMap(int arg, Json::Value &json) {
		bool bRet = true;
		for (int x = 0; x < json.size(); x++) {
			std::string name = (json[x]).getMemberNames()[0];
			unsigned int id = (json[x]).get(name, -1).asUInt();
			m_pMap->insert(std::pair<std::string, T>(name, T(id, arg)));
		}
		return bRet;
	}
private:
	std::map<std::string, T> *m_pMap;
};
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
	std::map<std::string, TEARegister> m_RegisterMap;
	typedef std::map<std::string, TEAInstruction> InstructionMapType;
	InstructionMapType m_InstructionMap;
	typedef std::map<std::string, std::string> StringSymbolType;
	StringSymbolType m_StringSymbolMap;
	typedef std::map<std::string, unsigned int> SymbolMapType;
	SymbolMapType m_SymbolMap;
};

#endif /* TEAPARSER_H_ */
