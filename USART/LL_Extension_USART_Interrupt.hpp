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
	using USART_Base::USART_Base;
	USART_Interrupt(USART_TypeDef *USARTx = nullptr,
			std::function<void(int)> completeReceive = [](int dataSize){},
			std::function<void(void)> completeTransmit = [](){},
			std::function<void(void)> idleDetected = [](){})
	:USART_Base(USARTx),
	 completeReceive(completeReceive),
	 completeTransmit(completeTransmit),
	 idleDetected(idleDetected){

	}

	enum class Error{
		None,
		Error,
		Busy,
	};
	Error IT_Handller();
	Error transmit(uint8_t *addr, uint8_t size);
	Error receive(uint8_t *addr, uint8_t const&size);

	Error receive_untill_EOL(uint8_t *addr, uint8_t size, std::string eol);

private:
	bool isEnableEOL;
	bool isReceive;
	bool isTransmit;
	uint8_t *bufferAddr;
	uint8_t bufferSize;
	uint8_t countData;
	std::string eol;
	std::function<void(int)> completeReceive;
	std::function<void(void)> completeTransmit;
	std::function<void(void)> idleDetected;
};

} /* namespace llex */
#endif /* CONFIG_DISABLE_MODULE_USART */

#endif /* USART_LL_EXTENSION_USART_INTERRUPT_HPP_ */
