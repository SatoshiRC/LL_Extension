/*
 * LL_Extension_USART_BlockingCommunication.hpp
 *
 *  Created on: Dec 6, 2020
 *      Author: conat
 */

#ifndef USART_LL_EXTENSION_USART_BLOCKINGCOMMUNICATION_HPP_
#define USART_LL_EXTENSION_USART_BLOCKINGCOMMUNICATION_HPP_

#include "LL_Extension_USART_BASE.hpp"
#include <string>

#ifndef CONFIG_DISABLE_MODULE_USART

namespace llex{

class USART_BlockingCommunication : public USART_Base{
private:

public:
	using USART_Base::USART_Base;
	enum class Error{
		None,
		Error,
	};

	Error transmit(uint8_t *addr, uint8_t size);
	Error print(std::string text);
	Error print(const char* text);
	Error println(std::string text);
	Error println(const char* text);
};
}


#endif /* CONFIG_DISABLE_MODULE_USART */

#endif /* USART_LL_EXTENSION_USART_BLOCKINGCOMMUNICATION_HPP_ */
