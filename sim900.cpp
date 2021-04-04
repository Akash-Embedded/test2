/**
*/
#include "pxt.h"
#include <string.h>

using namespace pxt;
namespace GSM {
uint8_t checkResponseMsgStart();
uint8_t checkResponseDk();
uint8_t checkRecievedMsg(uint8_t *buffer);
uint8_t response[100];
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
uBit.serial.send((uint8_t *)number->getUTF8Data(), number->getLength());
uBit.serial.send((uint8_t *)"\"\r",2);

uBit.sleep(2000);
if(checkResponseMsgStart() == 0)
	return 2;
uBit.serial.send((uint8_t *)msg->getUTF8Data(), msg->getLength());
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
//% blockId=GSM_SIM900RecieveSms block= Recieved message from number %number"
//% group="SMS1"
String SIM900RecieveSms(String number)
{
	String s = mkString("Error",-1);
	if(uBit.serial.setRxBufferSize(100) != MICROBIT_OK)
		return s;
	if(uBit.serial.setTxBufferSize(100) != MICROBIT_OK)
			return s;
	uBit.serial.send((uint8_t *)"AT\r",3);
	uBit.sleep(1000);
	if(checkResponseDk() == 0)
		return s;

	uBit.serial.send((uint8_t *)"AT+CMGF=1\r",10);
	uBit.sleep(1000);
	if(checkResponseDk() == 0)
		return s;

	uBit.serial.send((uint8_t *)"AT+CNMI=1,2,0,0,0\r",18);
	uBit.sleep(1000);
	if(checkResponseDk() == 0)
		return s;

	bool recieved = false;
	uint8_t recMsg[99];
	while(recieved != true)
	{
		if(checkRecievedMsg(recMsg) == 1)
		{
			return (mkString((const char *)&recMsg[0],-1));
		}
		recieved = true;
	}
}

uint8_t checkRecievedMsg(uint8_t *buffer)
{
	const int len = uBit.serial.read(&response[0], 99,  MicroBitSerialMode::ASYNC);
	if(len == 0)
		return 0;
	else
	{
		response[len] = 0;
		for(uint8_t lc = 0; lc < len; lc++)
		{
			if(response[lc] == 'C'  && response[lc+1] == 'M' && response[lc+2] == 'T' && response[lc+3] == ':')
			{
				for(uint8_t lc2 = lc+4; lc2 < len; lc2++)
				{
					if(response[lc2] == 0x0D  && response[lc2+1] == 0x0A)
					{
						strncpy((char *)buffer, (const char *)&response[lc2+2], len-lc-4);
						return 1;
					}
				}
			}
		}
		return 0;
	}
}
}
