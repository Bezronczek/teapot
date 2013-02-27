/*
 * TEAArch.h
 *
 *  Created on: 26-02-2013
 *      Author: Rafal Czaja
 */

#ifndef TEAARCH_H_
#define TEAARCH_H_
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include "TEASerialize.h"
//class TEASerialize {
//public:
//	TEASerialize() {
//	}
//
//	virtual int serialize() = 0;
//};
//
//class TEARegister: public TEASerialize {
//public:
//	enum RegSize {
//		B64 = 0, B32 = 1, B16 = 2, B8 = 3
//	};
//	TEARegister(unsigned int id, int size) :
//			m_iId(id), m_iRegSize(size) {
//	}
//	virtual ~TEARegister() {
//	}
//	int serialize() {
//
//		return 0;
//	}
//private:
//	unsigned int m_iId;
//	int m_iRegSize;
//};
//template<class T>
//class TEAHelper {
//public:
//	TEAHelper(std::map<std::string, TEASerialize*> *pMap) :
//			m_pMap(pMap) {
//	}
//	bool generateMap(int arg, Json::Value &json) {
//		bool bRet = true;
//		for (int x = 0; x < json.size(); x++) {
//			std::string name = (json[x]).getMemberNames()[0];
//			unsigned int id = (json[x]).get(name, -1).asUInt();
//			m_pMap->insert(std::pair<std::string, TEASerialize*>(name, new T(id, arg)));
//		}
//		return bRet;
//	}
//private:
//	std::map<std::string, TEASerialize*> *m_pMap;
//};

class TRegister: public TByte {
public:
	TRegister(unsigned int iId) :
			m_iId(iId) {
	}
	virtual ~TRegister() {
	}
	virtual unsigned int get() {
		return m_iId;
	}
private:
	unsigned int m_iId;
};
class TInstruction: public TByte {
public:
	TInstruction(unsigned int iId) :
			m_iId(iId) {
	}
	virtual ~TInstruction() {
	}
	virtual unsigned int get() {
		return m_iId;
	}
private:
	unsigned int m_iId;
};

class TEAArch {
public:
	TEAArch() {
	}
	virtual ~TEAArch() {
	}
	virtual TInstruction *getInstruction(const std::string& symbol) = 0;
	virtual TRegister *getRegister(const std::string& symbol) = 0;
};

#endif /* TEAARCH_H_ */
