/*
 * LL_Extension_USART_Interrupt.hpp
 *
 *  Created on: Jan 13, 2022
 *      Author: satohi ohya
 */

#ifndef USART_LL_EXTENSION_USART_INTERRUPT_HPP_
#define USART_LL_EXTENSION_USART_INTERRUPT_HPP_

#ifndef CONFIG_DISABLE_MODULE_USART

#include "LL_Extension_USART_BASE.hpp"
#include "string"
#include "functional"

namespace llex {

/*
 *
 */
class USART_Interrupt: public USART_Base {
public:
	USART_Interrupt(USART_TypeDef *USARTx = nullptr,
			std::function<void(void)> completeReceive = [](){})
	:USART_Base(USARTx),
	 completeReceive(completeReceive){
		isEnableEOL = false;
		bufferAddr = nullptr;
		bufferSize = 0;
		countData = 0;
	}

	void IT_Handller();
	void transmit(uint8_t *addr, uint8_t size);
	void receive(uint8_t *addr, uint8_t const&size);

private:
	bool isEnableEOL;
	uint8_t *bufferAddr;
	uint8_t bufferSize;
	uint8_t countData;
	const std::function<void(void)> completeReceive;
};

} /* namespace llex */
#endif /* CONFIG_DISABLE_MODULE_USART */

#endif /* USART_LL_EXTENSION_USART_INTERRUPT_HPP_ */
