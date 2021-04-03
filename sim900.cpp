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
	String recponse;
	uBit.serial.send((uint8_t *)"AT\r",sizeof("AT\r"));
	uBit.sleep(1000);
	if(checkResponseDk() == 0)
		return 0;

	uBit.serial.send((uint8_t *)"AT+CMGF=1\r",sizeof("AT+CMGF=1\r"));
	uBit.sleep(1000);
	if(checkResponseDk() == 0)
		return 0;

	uBit.serial.send((uint8_t *)"AT+CMGS=\"+919717338103\"\r",sizeof("AT+CMGS=\"+919717338103\"\r"));
	uBit.sleep(1000);
	if(checkResponseMsgStart() == 0)
		return 0;
	uBit.serial.send((uint8_t *)"Hello",sizeof("Hello"));
	uBit.serial.send((uint8_t *)"\r",sizeof("\r"));
	uBit.serial.sendChar(26);
	uBit.sleep(3000);
	if(checkResponseDk() == 0)
		return 0;
	//int read(uint8_t *buffer, int bufferLen, MicroBitSerialMode mode = MICROBIT_DEFAULT_SERIAL_MODE);
	//ManagedString read(int size, MicroBitSerialMode mode = MICROBIT_DEFAULT_SERIAL_MODE);
//AT+CMGF=1\r
//AT+CMGS=\"XXXXXXXXXX\"\r
//wait for >
//message\r
//26\r

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
		if((strstr((const char *)&response[0], "OK") != NULL) || (strstr((const char *)&response[0], "ok") != NULL))
		{
		    return 1;
		}
		else
		{
			return 0;
		}
	}
}
uint8_t checkResponseMsgStart()
{
	uint64_t time = system_timer_current_time();
	int c = 0;
	do {
		c = uBit.serial.read(MicroBitSerialMode::ASYNC);
	} while(c !='>' && system_timer_current_time()-time<1000);

	if (system_timer_current_time()-time>=1000) {
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
