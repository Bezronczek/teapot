/*
 * TEAParser.h
 *
 *  Created on: 25-02-2013
 *      Author: Rafal Czaja
 */

#ifndef TEAPARSER_H_
#define TEAPARSER_H_
#include <map>
#include <list>
#include <vector>
#include <string>
#include <iostream>
#include "TEALex.h"
#include "TEAArch.h"
#include "TEA0x7dd.h"
class TNode {
public:
	enum ArgType {
		REGISTER, NUMBER, POINTER
	};
	TNode() {
	}
	TNode(TByte *ptr) :
			m_pPtr(ptr), m_pArgs(new std::vector<ArgType>) {
	}
	bool add(ArgType iType) {
		m_pArgs->push_back(iType);
		return true;
	}
private:
	TByte *m_pPtr;
	std::vector<ArgType> *m_pArgs;
};

class TPointer: public TNode {
public:
	TPointer() :
			m_bInitialized(false) {
	}
	TPointer(int pAddress) :
			m_bInitialized(true), m_pAddress(pAddress) {
	}
	void setAddress(int iAddress) {
		m_bInitialized = true;
		m_pAddress = iAddress;
	}
private:
	bool m_bInitialized;
	int m_pAddress;
};

class TEAParser {
public:
	TEAParser();
	virtual ~TEAParser();
	void addToken(TEALex::state tokenType, const std::string& strTokenValue);
private:
	TPointer *getPointer(const std::string &strSymbol);
	TPointer *registerPointer(const std::string &strSymbol);

	bool registerSymbol(const std::string &strSymbol);

	int m_iAddress;
	TEAArch *m_pArch;
	TNode *m_pCurr;
	std::map<std::string, TPointer*> *m_pSymbolMap;
	std::list<TNode*> *m_pNode;
};

#endif /* TEAPARSER_H_ */
