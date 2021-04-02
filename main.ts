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

    // -------------- 1. SMS ----------------
    /**
    * Send Text message
    */
    //% blockId=gsm_send_sms
    //% block="send message %msg| to %number"  
    //% weight=90
    //% blockGap=7
    //% group="SMS1"
    export function sendSms(msg: string, number: string): number{
      sendSms(msg,number)
      return 2
    }

    /**
    * Recieve message
    */
    //% blockId=gsm_recieve_sms
    //% block="recieve sms from number %number"  
    //% weight=80
    //% blockGap=7
    //% group="SMS1"
    export function recieveSms(number: string): number{
      return 3
    }

    /**
    * Recieve message any
    */
    //% blockId=gsm_recieve_sms_any
    //% block="recieve sms from any number"  
    //% weight=70
    //% blockGap=7
    //% group="SMS1"
    export function recieveSmsAny(number: string): number{
      return 4
    }
    // -------------- 2. Settings ----------------
    /**
     * Connect DFPlayer Mini
     * @param pinRX RX Pin, eg: SerialPin.P0
     * @param pinTX TX Pin, eg: SerialPin.P1
     */
    //% blockId=gsm_connect
    //% block="connect to GSM SIM900A, RX:%pinRX|TX:%pinTX"   
    //% weight=80	
    //% blockGap=7
    //% group="SETTINGS"
    export function connect(pinRX: SerialPin = SerialPin.P0, pinTX: SerialPin = SerialPin.P1): void {
        //serial.redirect(pinRX, pinTX, BaudRate.BaudRate9600)
        //isConnected = true
        //basic.pause(100)
    }
}
