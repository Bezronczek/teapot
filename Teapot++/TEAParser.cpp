/*
 * TEAParser.cpp
 *
 *  Created on: 25-02-2013
 *      Author: Rafal Czaja
 */

#include "TEAParser.h"

TEAParser::TEAParser() :
		m_iAddress(0) {
	//Probably there is a need to read list available instruction from external resource
	Json::Reader jsonReader;
	Json::Value jsonRoot;
	std::ifstream ifs("./arch.json");
	bool bSuccess = jsonReader.parse(ifs, jsonRoot);
	ifs.close();
	if (bSuccess) {
		Json::Value jsonRegisters = jsonRoot.get("Registers",
				Json::Value::null);
		if (jsonRegisters == Json::Value::null)
			throw 1; // Later it will be std::exception
		Json::Value jsonRegisters64 = jsonRegisters.get("64",
				Json::Value::null);
		Json::Value jsonRegisters32 = jsonRegisters.get("32",
				Json::Value::null);
		Json::Value jsonRegisters16 = jsonRegisters.get("16",
				Json::Value::null);
		Json::Value jsonRegisters8 = jsonRegisters.get("8", Json::Value::null);

		TEAHelper<TEARegister> registerHelper(&m_RegisterMap);
		registerHelper.generateMap(TEARegister::B64, jsonRegisters64);
		registerHelper.generateMap(TEARegister::B32, jsonRegisters32);
		registerHelper.generateMap(TEARegister::B16, jsonRegisters16);
		registerHelper.generateMap(TEARegister::B8, jsonRegisters8);
	} else {
		std::cout << jsonReader.getFormatedErrorMessages() << std::endl;
	}
}

TEAParser::~TEAParser() {
}

void TEAParser::addToken(TEALex::state tokenType,
		const std::string & strTokenValue) {
}

