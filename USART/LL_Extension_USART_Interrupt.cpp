/*
 * LL_Extension_USART_Interrupt.cpp
 *
 *  Created on: Jan 13, 2022
 *      Author: satohi ohya
 */

#include "LL_Extension_USART_Interrupt.hpp"

namespace llex {
void USART_Interrupt::IT_Handller(){
	if(isActiveFlag_RXNE()){
		if(countData<bufferSize){
			*(bufferAddr+countData) = receiveData();
		}
		countData += 1;

		if(countData>=bufferSize){
			disableReceiveIT();
			completeReceive();
			countData = 0;
		}
	}
}

void USART_Interrupt::receive(uint8_t *addr, const uint8_t &size){
	if(mode != Mode::none){
		return;
	}
	bufferAddr = addr;
	bufferSize = size;
	enableReceiveIT();
}

void USART_Interrupt::transmit(uint8_t *addr, uint8_t size){
}
} /* namespace llex */
