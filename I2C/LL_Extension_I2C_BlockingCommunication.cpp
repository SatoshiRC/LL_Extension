/*
 * LL_Extension_I2CBlockingCommunication.cpp
 *
 *  Created on: Jan 8, 2021
 *      Author: satohi ohya
 */
#ifndef CONFIG_DISABLE_MODULE_I2C

#include "LL_Extension_I2C_BlockingCommunication.hpp"

namespace llex {

void I2C_BlockingCommunication::masterTransmit(uint16_t slaveAddress, uint8_t* pData, uint8_t dataSize, uint16_t timeout, AddressSize addressSize){

	beginMasterHandle(slaveAddress, addressSize, TransferDirection::Write, timeout);

	if(error != Error::None){
		generateStopCondition();
		return;
	}

	for(uint8_t n=0; n<dataSize;){
		while(!isActiveFlagTransmitDataEmpty()){
			if(isTimeout(beginTime, timeout)){
				LOG("timeout: transmit data not empty");
				error = Error::TimeOut;
				generateStopCondition();
				return;
			}
		}

		transmit8bit(*(pData+n++));
		LOG("transmit data: " + std::to_string(*(pData + n-1)) + ", data number: " + std::to_string(n-1));
		if(n >= dataSize){
			break;
		}
		if(isActiveFlagByteTransferFinished()){
			transmit8bit(*(pData+n++));
			LOG("transmit data: " + std::to_string(*(pData + n-1)) + ", data number: " + std::to_string(n-1));
		}
	}

	generateStopCondition();

}

void I2C_BlockingCommunication::masterReceive(){

}

void I2C_BlockingCommunication::slaveTransmit(){

}

void I2C_BlockingCommunication::slaveReceive(uint8_t* pData, uint8_t dataSize, uint16_t timeout){
	if(beginSlavehandle(timeout) != TransferDirection::Read){
		error = Error::TransferDirection;
		return;
	}

	if(error != Error::None){
		generateStopCondition();
		return;
	}

	for(uint8_t n=0; n<dataSize; n++){
		receiveElement(*(pData + n), timeout);
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
			volatile uint8_t tmpData = receive8bit();
			(void) tmpData;
			if(error != Error::BufferError){
				error = Error::BufferError;
				LOG("<Error> buffer overrun");
			}
		}
	}
}

I2C_BlockingCommunication::Error I2C_BlockingCommunication::getError(){
	return error;
}

void I2C_BlockingCommunication::clearError(){
	error = Error::None;
}

bool I2C_BlockingCommunication::isTimeout(uint64_t beginTime, uint16_t timeout){
	return (timeout <= systemTime - beginTime);
}



void I2C_BlockingCommunication::beginMasterHandle(uint16_t address, AddressSize addressSize, TransferDirection direction, uint16_t timeout){
	beginTime = systemTime;
	error = Error::None;

	if(!isEnable()){
		enable();
	}

	if(isActiveFlagBusBusy()){
		LOG("bus busy");

		error = Error::BusBusy;
		return;
	}

	disablePOS();

	generateStartCondition();
	LOG("generate start condition");

	while(!isActiveFlagStartBit()){
		if(isTimeout(beginTime, timeout)){
			error = Error::TimeOut;
			return;
		}
	}

	if(addressSize == AddressSize::BIT7){
		transmit8bit((address<<1) + (uint8_t)direction);
		LOG("send address in 7Bits mode, send data is " + std::to_string((address<<1) + (uint8_t)direction));

		while(!isActiveFlagAddress()){
			if(isTimeout(beginTime, timeout)){
				LOG("time out while waiting address flag is sited");

				error = Error::TimeOut;
				return;
			}
		}
	}else{
		//TODO: 10bit address transmit
	}
	clearFlagAddress();
	LOG("clear address flag");
}

I2C_base::TransferDirection I2C_BlockingCommunication::beginSlavehandle(uint16_t timeout){
	disablePOS();
	LOG("disable POS");

	acknowledgeNextData(llex::I2C_base::AcknowledgeType::ACK);
	LOG("acknowledge next data");

	while(isActiveFlagStartBit());
	LOG("start detected")
	LOG("waiting...");
	while(!isActiveFlagAddress());
	LOG("received address is matched own address");
	clearFlagAddress();
	LOG("clear address flag");

	return getTransferDirection();

}

} /* namespace llex */
#endif /* CONFIG_DISABLE_MODULE_I2C */
