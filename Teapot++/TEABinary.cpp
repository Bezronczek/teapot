/*
 * TEABinary.cpp
 *
 *  Created on: 27-02-2013
 *      Author: Rafal Czaja
 */

#include "TEABinary.h"

TEABinary::TEABinary(const std::string &strOutput) :
		m_pStream(new std::fstream()) {
	m_pStream->open(strOutput.c_str(), std::ios::out | std::ios::binary);
}

TEABinary::~TEABinary() {
	m_pStream->close();
	delete m_pStream;
}

