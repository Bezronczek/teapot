/*
 * TEAParser.cpp
 *
 *  Created on: 25-02-2013
 *      Author: Rafal Czaja
 */

#include "TEAParser.h"

TEAParser::TEAParser() :
		m_iAddress(0), m_pArch(new TEA0x7dd), m_pNode(new std::list<TNode*>), m_pCurr(
				0l), m_pSymbolMap(new std::map<std::string, TPointer*>) {
	//Probably there is a need to read list available instruction from external resource
}

TEAParser::~TEAParser() {
}

void TEAParser::addToken(TEALex::state tokenType,
		const std::string & strTokenValue) {
	if (tokenType == TEALex::state::STATEMENT) {
		TByte *pInstruction = m_pArch->getInstruction(strTokenValue);
		if (pInstruction != 0l) {
			std::cout << "Instruction: " << strTokenValue << std::endl;
			m_iAddress++;
			m_pCurr = new TNode(pInstruction);
			m_pNode->push_back(m_pCurr);
		} else {
			pInstruction = m_pArch->getRegister(strTokenValue);
			if (pInstruction != 0l) {
				std::cout << "Register: " << strTokenValue << std::endl;
				m_iAddress++;
				m_pCurr->add(TNode::ArgType::REGISTER);
				m_pNode->push_back(new TNode(pInstruction));
			} else {
				std::cout << "Invalid symbol: " << strTokenValue << std::endl;
				throw 2; // Later will thrown std::exception something
			}
		}
	} else if (tokenType == TEALex::state::POINTER) {
		TPointer *pPointer = getPointer(strTokenValue);
		if (pPointer == 0l)
			pPointer = registerPointer(strTokenValue);
		std::cout << "Pointer: " << strTokenValue << std::endl;
		m_pCurr->add(TNode::ArgType::POINTER);
		m_pNode->push_back(pPointer);
		m_iAddress++;
	} else if (tokenType == TEALex::state::LABEL) {
		registerSymbol(strTokenValue);
	}
}

TPointer *TEAParser::getPointer(const std::string & strSymbol) {
	std::map<std::string, TPointer*>::iterator it = m_pSymbolMap->find(
			strSymbol);
	return it == m_pSymbolMap->end() ? 0l : it->second;
}

TPointer *TEAParser::registerPointer(const std::string & strSymbol) {
	TPointer *pResult = new TPointer();
	m_pSymbolMap->insert(std::pair<std::string, TPointer*>(strSymbol, pResult));
	return pResult;
}

bool TEAParser::registerSymbol(const std::string & strSymbol) {
	std::map<std::string, TPointer*>::iterator it = m_pSymbolMap->find(
			strSymbol);
	if (it != m_pSymbolMap->end()) {
		it->second->setAddress(m_iAddress);
	} else {
		m_pSymbolMap->insert(
				std::pair<std::string, TPointer*>(strSymbol,
						new TPointer(m_iAddress)));
	}
	return true;
}

