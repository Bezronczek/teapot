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
	virtual unsigned int get() = 0;
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
