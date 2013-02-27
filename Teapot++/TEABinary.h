/*
 * TEABinary.h
 *
 *  Created on: 27-02-2013
 *      Author: Rafal Czaja
 */

#ifndef TEABINARY_H_
#define TEABINARY_H_
#include <fstream>
#include <iostream>
#include "TEASerialize.h"
class TEABinary {
public:
	TEABinary(const std::string &strOutput);
	virtual ~TEABinary();

	void operator <<(const TEASerialize &obj) {
		for (const_node_iterator it = obj.getNodeBegin();
				it != obj.getNodeEnd(); ++it) {
			unsigned int out = ((*it)->get());
			m_pStream->write(reinterpret_cast<char *>(&out), sizeof(int));
		}
	}
private:
	std::fstream *m_pStream;
};

#endif /* TEABINARY_H_ */
