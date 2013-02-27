/*
 * TEA0x7dd.h
 *
 *  Created on: 27-02-2013
 *      Author: Rafal Czaja
 */

#ifndef TEA0X7DD_H_
#define TEA0X7DD_H_
#include <map>
#include "TEAArch.h"

class TEA0x7dd: public TEAArch {
public:
	TEA0x7dd();
	virtual ~TEA0x7dd();

	TInstruction *getInstruction(const std::string& symbol) {
		std::map<std::string, TInstruction*>::iterator it = m_Instruction.find(
				symbol);
		return it == m_Instruction.end() ? 0l : it->second;
	}
	TRegister *getRegister(const std::string& symbol) {
		std::map<std::string, TRegister*>::iterator it = m_Register.find(
				symbol);
		return it == m_Register.end() ? 0l : it->second;
	}

private:
	std::map<std::string, TInstruction*> m_Instruction;
	std::map<std::string, TRegister*> m_Register;
};

#endif /* TEA0X7DD_H_ */
