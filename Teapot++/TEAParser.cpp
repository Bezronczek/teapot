/*
 * TEAParser.cpp
 *
 *  Created on: 25-02-2013
 *      Author: Rafal Czaja
 */

#include "TEAParser.h"

TEAParser::TEAParser() :
		m_iAddress(0), m_pArch(new TEA0x7dd), m_pNode(new std::list<TNode*>), m_pCurr(
				0l) {
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
			m_pCurr = new TNode(pInstruction);
			m_pNode->push_back(m_pCurr);
		} else {
			pInstruction = m_pArch->getRegister(strTokenValue);
			if (pInstruction != 0l) {
				std::cout << "Register: " << strTokenValue << std::endl;
				m_pCurr->add(TNode::ArgType::REGISTER);
				m_pNode->push_back(new TNode(pInstruction));
			} else {
				std::cout << "Symbol: " << strTokenValue << std::endl;
			}
		}
	}

}

