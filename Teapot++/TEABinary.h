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
			std::cout << "Cos tam, cos tam" << std::endl;
		}
	}
private:
	std::fstream *m_pStream;
};

#endif /* TEABINARY_H_ */
