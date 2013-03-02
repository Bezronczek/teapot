/*
 * TEASerialize.h
 *
 *  Created on: 27-02-2013
 *      Author: Rafal Czaja
 */

#ifndef TEASERIALIZE_H_
#define TEASERIALIZE_H_
#include <list>
#include <vector>
class TByte {
public:
	TByte() {
	}
	virtual unsigned int get() const = 0;
};

class TEABitmask {
public:
	static unsigned int getInstructionId(unsigned int bitmask) {
		return (bitmask & m_uiRightBitmask);
	}
	static unsigned int getInstructionParams(unsigned int bitmask) {
		return ((bitmask & m_uiLeftBitmask) >> 8);
	}

	static void setInstructionCout(unsigned int &bitmask, int count) {
		bitmask = ((count << 9) & m_uiArgsCountMask) | bitmask;
	}

	static void setInstructionMagicBit(unsigned int &bitmask) {
		bitmask = bitmask | m_uiInstructionMagicBit;
	}

	static void setFirstArgAsRegister(unsigned int &bitmask) {
		bitmask = bitmask | m_uiFirstArgumentMask;
	}

	static void setFirstArgAsSpecial(unsigned int &bitmask) {
		bitmask = bitmask | m_uiFirstArgumentIsSpecial;
	}

	static void setSecondArgAsRegister(unsigned int &bitmask) {
		bitmask = bitmask | m_uiSecondArgumentMask;
	}

	static void setSecondArgAsSpecial(unsigned int &bitmask) {
		bitmask = bitmask | m_uiSecondArgumentIsSpecial;
	}

private:
	static const unsigned int m_uiLeftBitmask = 0xff00;
	static const unsigned int m_uiRightBitmask = 0x00ff;

	static const unsigned int m_uiInstructionMagicBit = 0x8000;

	static const unsigned int m_uiArgsCountMask = 0x600;
	static const unsigned int m_uiFirstArgumentMask = 0x4000;
	static const unsigned int m_uiFirstArgumentIsSpecial = 0x2000;
	static const unsigned int m_uiSecondArgumentMask = 0x1000;
	static const unsigned int m_uiSecondArgumentIsSpecial = 0x800;

	static const unsigned int m_uiReservedBit = 0x100;
};

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
	virtual unsigned int get() const {
		return m_pPtr->get();
	}

	virtual const char *getBinary() const {
		return 0l;
	}
	virtual bool binary() const {
		return false;
	}
private:
	TByte *m_pPtr;
	std::vector<ArgType> *m_pArgs;
};
typedef std::list<TNode*>::const_iterator const_node_iterator;
class TEASerialize {
public:
	TEASerialize() {
	}
	virtual ~TEASerialize() {
	}

	virtual const_node_iterator getNodeBegin() const = 0;
	virtual const_node_iterator getNodeEnd() const = 0;
};

#endif /* TEASERIALIZE_H_ */
