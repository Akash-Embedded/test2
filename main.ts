/**
* Abc
* https://github.com/embedded-akash/pxt-light-bit
* Development environment specifics:
* Written in Microsoft Makecode
*/


/**
 * Functions to operate the gatorlight sensor
 */

 enum gatorlightType{
	 Lux=1,
	 adcVal=2,
 }



//% color=#f44242 icon="\uf185"
namespace GSM {

    // Functions for reading light from the gatorlight in lux or straight adv value

    /**
    * Reads the number
    */
    // -------------- 1. SMS ----------------
    //%blockId=gsm_send_sms
    //% block="send message %msg| to %number"  
    //% weight=90	
    //% blockGap=7
    //% group="SMS"
    export function sendSms(msg: string, number: string): number{
      sendSms(msg,number)
      return 1
      }
}
