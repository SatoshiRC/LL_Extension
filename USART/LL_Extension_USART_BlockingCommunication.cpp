/*
 * LL_Extension_USART_BlockingCommunication.cpp
 *
 *  Created on: Dec 6, 2020
 *      Author: conat
 */

#include "LL_Extension_USART_BlockingCommunication.hpp"

namespace llex{

USART_BlockingCommunication::Error USART_BlockingCommunication::transmit(uint8_t *addr, uint8_t size){
	USART_BlockingCommunication::Error error = USART_BlockingCommunication::Error::None;
	USART_Base::enableDirectionTx();

	while(!USART_Base::isActiveFlag_TXE());

	for(uint8_t n=0; n<size+1; n++){
		USART_Base::transmitData(*(addr+n));
		while(!USART_Base::isActiveFlag_TXE());
	}

	USART_Base::disableDirectionTx();
	return error;
}

USART_BlockingCommunication::Error USART_BlockingCommunication::print(std::string text){
	return transmit((uint8_t*)text.c_str(), text.length());
}

USART_BlockingCommunication::Error USART_BlockingCommunication::print(const char* text){
	return print(std::string(text));
}

USART_BlockingCommunication::Error USART_BlockingCommunication::println(std::string text){
	text.append("\r\n");
	return transmit((uint8_t*)text.c_str(), text.length());
}

USART_BlockingCommunication::Error USART_BlockingCommunication::println(const char* text){
	return println(std::string(text));
}
}
