/**
*/
#include "pxt.h"
#include <string.h>

using namespace pxt;
namespace GSM {
uint8_t checkResponseMsgStart();
uint8_t checkResponseDk();

/**
* Initialize MU.
*/
//% blockId=GSM_SIM900SendSms block="message %msg | number %number"
//% group="SMS1"
int SIM900SendSms(String msg, String number)
{
if(uBit.serial.setRxBufferSize(100) != MICROBIT_OK)
	return 0;
if(uBit.serial.setTxBufferSize(100) != MICROBIT_OK)
		return 0;
uBit.serial.send((uint8_t *)"AT\r",3);
uBit.sleep(1000);
if(checkResponseDk() == 0)
	return 0;

uBit.serial.send((uint8_t *)"AT+CMGF=1\r",10);
uBit.sleep(1000);
if(checkResponseDk() == 0)
	return 1;

uBit.serial.send((uint8_t *)"AT+CMGS=\"",9);
uBit.serial.send((uint8_t *)number, number->getLength());
uBit.serial.send((uint8_t *)"\"\r",2);

uBit.sleep(2000);
if(checkResponseMsgStart() == 0)
	return 2;
uBit.serial.send((uint8_t *)msg, msg->getLength());
uBit.serial.sendChar(26);
uBit.sleep(3000);
if(checkResponseDk() == 0)
	return 3;
return 4;
}

uint8_t checkResponseDk()
{
uint8_t response[100];
const int len = uBit.serial.read(&response[0], 99,  MicroBitSerialMode::ASYNC);
if(len == 0)
	return 0;
else
{
	response[len] = 0;
	for(uint8_t lc = 0; lc < len; lc++)
	{
		if((response[lc] == 'O' || response[lc] == 'o') && (response[lc+1] == 'K' || response[lc+1] == 'k'))
		{
			return 1;
		}
	}
	return 0;
}
}
uint8_t checkResponseMsgStart()
{
uint64_t time = system_timer_current_time();
char c = 0;
do {
	c = uBit.serial.read(MicroBitSerialMode::ASYNC);
} while(c !='>' && system_timer_current_time()-time<10000);

if (system_timer_current_time()-time>=10000) {
	return 0;
}
return 1;
}
/**
* Initialize MU.
*/
//% blockId=GSM_SIM900RecieveSms block="message %rcvMsg | number %number"
//% group="SMS1"
void SIM900RecieveSms(String rcvMsg, String number)
{

}

}
