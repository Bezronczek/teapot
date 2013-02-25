/*
 * TEALex.cpp
 *
 *  Created on: 25-02-2013
 *      Author: r
 */

#include "TEALex.h"

TEALex::TEALex() :
		m_enumState(NOOP), m_bEscapeChar(false) {
}

TEALex::~TEALex() {
}

TEALex::state TEALex::getToken(std::string & strToken) {
	std::string strResult;
	TEALex::state enumResult = NOOP;
	for (; m_itCurrPos != m_strLine.end(); ++m_itCurrPos) {
		char byte = (*m_itCurrPos);
		if (byte == '.') {
			if (m_enumState == NOOP) {
				m_enumState = LABEL;
				continue;
			}
		} else if ((byte == ';') && (m_enumState != STRING)) {
			enumResult = m_enumState;
			m_itCurrPos = m_strLine.end();
			break;
		} else if (byte == '"') {
			if (m_enumState == NOOP) {
				m_enumState = STRING;
				continue;
			} else if ((m_enumState == STRING) && (!m_bEscapeChar)) {
				enumResult = STRING;
				m_enumState = NOOP;
				++m_itCurrPos;
				break;
			}
		} else if ((byte == '\\') && (m_enumState == STRING)) {
			if (m_bEscapeChar) {
				m_bEscapeChar = false;
				strResult += byte;
				continue;
			}
			m_bEscapeChar = true;
		} else if ((byte >= '0') && (byte <= '9') && (m_enumState == NOOP)) {
			m_enumState = NUMBER;
		} else if ((m_enumState == NOOP)
				&& (((byte >= 'a') && (byte <= 'z'))
						|| ((byte >= 'A') && (byte <= 'Z')))) {
			m_enumState = STATEMENT;
		} else if ((m_enumState == NOOP) && (byte == '@')) {
			m_enumState = POINTER;
		}
		if ((byte == '\t') || (byte == ' ') || (byte == ',')) {
			if ((m_enumState == LABEL) || (m_enumState == STATEMENT)
					|| (m_enumState == POINTER)) {
				enumResult = m_enumState;
				m_enumState = NOOP;
				break;
			}
		}
		if ((m_enumState == STRING) || (m_enumState == LABEL)
				|| (m_enumState == STATEMENT) || (m_enumState == POINTER)) {
			enumResult = m_enumState;
			strResult += byte;
		}
	}
	strToken = strResult;
	return enumResult;
}

