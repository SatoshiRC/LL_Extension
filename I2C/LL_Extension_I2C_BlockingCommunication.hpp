/*
 * LL_Extension_I2CBlockingCommunication.hpp
 *
 *  Created on: Jan 8, 2021
 *      Author: satohi ohya
 */
#ifndef CONFIG_DISABLE_MODULE_I2C

#ifndef I2C_LL_EXTENSION_I2C_BLOCKINGCOMMUNICATION_HPP_
#define I2C_LL_EXTENSION_I2C_BLOCKINGCOMMUNICATION_HPP_

#include "LL_Extension_I2C_BASE.hpp"

extern uint64_t systemTime;

#ifdef I2C_LL_EXTENSION_I2C_BLOCKINGCOMMUNICATION_DEBUG
#include "USART/LL_Extension_USART_all.hpp"
extern llex::USART_BlockingCommunication usart2;
#define LOG(_STR_) usart2.println(_STR_);
#else /*I2C_LL_EXTENSION_I2C_BLOCKINGCOMMUNICATION_DEBUG*/
#define LOG(_STR_) do{}while(0);
#endif/*I2C_LL_EXTENSION_I2C_BLOCKINGCOMMUNICATION_DEBUG*/
namespace llex {

/*
 *
 */
class I2C_BlockingCommunication: public I2C_base {
public:
	enum class Error{
		None,
		BusBusy,
		TimeOut,
		ACK,
		TransferDirection,
		BufferError,
		DataSizeError,
	};
	using I2C_base::I2C_base;
	I2C_BlockingCommunication(I2C_TypeDef *I2Cx):I2C_base(I2Cx){
		error = Error::None;
		beginTime = 0;
	};

	void masterTransmit(uint16_t slaveAddress, uint8_t* pData, uint8_t dataSize, uint16_t timeout = 100, AddressSize addressSize = AddressSize::BIT7);
	template<class element>
	void masterTransmit(uint16_t slaveAddress, element begin, element end = nullptr, uint16_t timeout = 100, AddressSize addressSize = AddressSize::BIT7){
		beginMasterHandle(slaveAddress, addressSize, TransferDirection::Write, timeout);

		if(error != Error::None){
			generateStopCondition();
			return;
		}

		if(end == (element)nullptr){
			end = begin + 1;
		}

		for(auto it = begin; it < end; it++){
			LOG("transmit element: "+ std::to_string(*it));
			transmitElement(*it, timeout);
		}

		generateStopCondition();
	}

	void masterReceive();

	void slaveTransmit();

	void slaveReceive(uint8_t* pData, uint8_t dataSize, uint16_t timeout = 100);

	template<class element>
	void slaveReceive(element begin, element end = nullptr, uint16_t timeout = 100){
		if(beginSlavehandle(timeout) != TransferDirection::Write){
			error = Error::TransferDirection;
			return;
		}

		if(error != Error::None){
			generateStopCondition();
			return;
		}

		for(auto it = begin; it<end; it++){
			receiveElement(*it, timeout);
			if((bool)error){
				generateStopCondition();
				return;
			}
		}
		while(!isActiveFlagStopDetection()){
			if(isTimeout(beginTime, timeout)){
				LOG("<Error> timeout");
				error = Error::TimeOut;
				generateStopCondition();
				return;
			}
			if(isActiveFlagReceiveDataNotEmpty()){
				if(error != Error::BufferError){
					error = Error::BufferError;
					LOG("<Error> buffer overrun");
				}
				generateStopCondition();
				break;
			}
		}

		acknowledgeNextData(AcknowledgeType::NACK);
		clearFlagStopDetection();

	}

	Error getError();
	void clearError();


private:
	Error error;
	uint64_t beginTime;
	bool isTimeout(uint64_t beginTime, uint16_t timeout);
	void beginMasterHandle(uint16_t address, AddressSize addressSize, TransferDirection direction, uint16_t timeout);
	TransferDirection beginSlavehandle(uint16_t timeout);

	template<typename T>
	void transmitElement(const T &element, uint16_t timeout){
		const uint8_t *pelement = (uint8_t *)&element;
		for(int8_t n=sizeof(T)-1; n>=0; n--){
			while(!isActiveFlagTransmitDataEmpty()){
				if(isTimeout(beginTime, timeout)){
					LOG("<Error> timeout: transmit data not empty");
					error = Error::TimeOut;
					generateStopCondition();
					return;
				}
			}
			transmit8bit(*(pelement + n));
			LOG("transmit data: " + std::to_string(*(pelement + n)) + ", data number: " + std::to_string(n));
		}
	}

	template<typename T>
	void receiveElement(const T &element, uint16_t timeout){
		uint8_t *pelement = (uint8_t *)&element;
		for(int8_t n=sizeof(T)-1; n>=0; n--){
			while(!isActiveFlagReceiveDataNotEmpty()){
				if(isTimeout(beginTime, timeout)){
					LOG("<Error> timeout: Receive data is empty");
					error = Error::TimeOut;
					generateStopCondition();
					return;
				}
				if(isActiveFlagStopDetection()){
					LOG("<Error> buffer under run");
					error = Error::BufferError;
					return;
				}
			}
			*(pelement + n) = receive8bit();
			LOG("receive data: " + std::to_string(*(pelement + n)) + ", data number: " + std::to_string(n));
		}
	}

};

} /* namespace llex */

#endif /* I2C_LL_EXTENSION_I2C_BLOCKINGCOMMUNICATION_HPP_ */

#endif /* CONFIG_DISABLE_MODULE_I2C */
