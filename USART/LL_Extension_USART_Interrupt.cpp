/*
 * LL_Extension_USART_Interrupt.cpp
 *
 *  Created on: Jan 13, 2022
 *      Author: satohi ohya
 */

#include <USART/LL_Extension_USART_Interrupt.hpp>


#include "GPIO/LL_Extension_GPIO_all.hpp"
extern llex::GPIO PA5;

namespace llex {
USART_Interrupt::Error USART_Interrupt::IT_Handller(){
	if(isActiveFlag_RXNE()){
		uint8_t tmpData = receiveData();
		if(countData<bufferSize){
			*(bufferAddr+countData) = tmpData;
		}
		countData += 1;

		if(countData>=bufferSize){
			disableReceiveIT();
			completeReceive(countData);
			countData = 0;
		}else if(isEnableEOL && tmpData == *(eol.rbegin())){
			const auto eolIt = eol.rbegin();
			uint8_t n=1;
			for(; n<eol.length(); n++){
				if(*(bufferAddr+countData-n-1) != *(eolIt+n)){
					break;
				}
			}
			if(n==eol.length()){
				isEnableEOL = false;
				disableReceiveIT();
				completeReceive(countData);
				countData = 0;
			}
		}
	}else if(isActiveFlag_IDLE()){
		clearFlag_IDLE();
		idleDetected();
	}else if(isActiveFlag_TXE()){
		transmitData(*(bufferAddr+countData));
		countData += 1;
	}else if(isActiveFlag_TC()){
		completeTransmit();
		disableDirectionTx();
		bufferAddr = nullptr;
	}else if(isActiveFlag_PE()){

	}else if(isActiveFlag_LBD()){
		clearFlag_LBD();

	}
	return Error::None;
}

USART_Interrupt::Error USART_Interrupt::receive(uint8_t *addr, uint8_t const&size){
	if(mode != Mode::none){
		return Error::Busy;
	}
	bufferAddr = addr;
	bufferSize = size;
	enableReceiveIT();
	return Error::None;
}

USART_Interrupt::Error USART_Interrupt::receive_untill_EOL(uint8_t *addr, uint8_t size, std::string eol){
	if(mode != Mode::none){
		return Error::Busy;
	}
	bufferAddr = addr;
	bufferSize = size;
	isEnableEOL = true;
	this->eol=eol;
	enableDirectionRx();
	enableReceiveIT();
	return Error::None;
}

USART_Interrupt::Error USART_Interrupt::transmit(uint8_t *addr, uint8_t size){
	return Error::None;
}
} /* namespace llex */
