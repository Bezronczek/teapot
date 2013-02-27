/*
 * TEA0x7dd.cpp
 *
 *  Created on: 27-02-2013
 *      Author: Rafal Czaja
 */

#include "TEA0x7dd.h"

TEA0x7dd::TEA0x7dd() {
	//Registers
	m_Register["eax"] = new TRegister(0);
	m_Register["ebx"] = new TRegister(1);
	m_Register["ecx"] = new TRegister(2);
	m_Register["edx"] = new TRegister(3);
	m_Register["ax"] = new TRegister(4);
	m_Register["bx"] = new TRegister(5);
	m_Register["cx"] = new TRegister(6);
	m_Register["dx"] = new TRegister(7);
	//Instructions
	m_Instruction["mov"] = new TInstruction(0);
	m_Instruction["lea"] = new TInstruction(1);
	m_Instruction["jmp"] = new TInstruction(2);
	m_Instruction["call"] = new TInstruction(3);
	m_Instruction["leave"] = new TInstruction(4);
	m_Instruction["loop"] = new TInstruction(5);

	m_Instruction["inc"] = new TInstruction(6);
	m_Instruction["dev"] = new TInstruction(7);

	m_Instruction["add"] = new TInstruction(8);
	m_Instruction["sub"] = new TInstruction(9);

	m_Instruction["push"] = new TInstruction(10);
	m_Instruction["pop"] = new TInstruction(11);

	m_Instruction["cmp"] = new TInstruction(12);
	m_Instruction["je"] = new TInstruction(13);
	m_Instruction["jne"] = new TInstruction(14);
}

TEA0x7dd::~TEA0x7dd() {
}

