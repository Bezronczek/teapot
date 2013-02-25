/*
 * TEALex.h
 *
 *  Created on: 25-02-2013
 *      Author: Rafal Czaja
 */

#ifndef TEALEX_H_
#define TEALEX_H_
#include <string>
#include <iostream>

class TEALex {
public:
	TEALex();
	virtual ~TEALex();
	enum state {
		NOOP, STATEMENT, STRING, LABEL, POINTER, NUMBER
	};
	void feed(const std::string& strString) {
		m_enumState = NOOP;
		m_bEscapeChar = false;
		m_strLine = strString;
		m_itCurrPos = m_strLine.begin();
	}

	state getToken(std::string &strToken);
private:
	std::string m_strLine;
	std::string::iterator m_itCurrPos;
	state m_enumState;
	bool m_bEscapeChar;
};

#endif /* TEALEX_H_ */
