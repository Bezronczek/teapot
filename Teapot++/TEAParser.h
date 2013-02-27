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
#include "TEASerialize.h"

class TPointer: public TNode {
public:
	TPointer() :
			m_bInitialized(false), m_pAddress(0) {
	}
	TPointer(int pAddress) :
			m_bInitialized(true), m_pAddress(pAddress) {
	}
	void setAddress(int iAddress) {
		m_bInitialized = true;
		m_pAddress = iAddress;
	}
	virtual unsigned int get() const {
		return m_pAddress;
	}
private:
	bool m_bInitialized;
	int m_pAddress;
};

class TEAParser: public TEASerialize {
public:
	TEAParser();
	virtual ~TEAParser();
	void addToken(TEALex::state tokenType, const std::string& strTokenValue);

	virtual const_node_iterator getNodeBegin() const {
		return m_pNode->begin();
	}
	virtual const_node_iterator getNodeEnd() const {
		return m_pNode->end();
	}
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
