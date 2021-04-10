/**
* Abc
* https://github.com/embedded-akash/pxt-light-bit
* Development environment specifics:
* Written in Microsoft Makecode
*/

//% color=#f44242 icon="\uf185"
namespace GSM {

    // -------------- 1. SMS ----------------
    /**
    * Send Text message
    */
    //% blockId=gsm_send_sms
    //% block="send message %msg| to %number"  
    //% weight=90
    //% blockGap=7
    //% group="SMS"
    export function sendSms(msg: string, number: string): number{
      return(GSM.SIM900SendSms(msg,number))
    }

    /**
    * Receive message
    */
    //% blockId=gsm_receive_sms
    //% block="receive sms from number %number"  
    //% weight=80
    //% blockGap=7
    //% group="SMS"
    export function receiveSms(phNumber: string): string{
      return (GSM.SIM900RecieveSms(phNumber))
    }

    /**
    * Recieve message any
    */
    //% blockId=gsm_recieve_sms_any
    //% block="recieve sms from any number"  
    //% weight=70
    //% blockGap=7
    //% group="SMS"
    export function recieveSmsAny(): string{
    let s: string = "0"
      return (GSM.SIM900RecieveSms(s))
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
        serial.redirect(pinRX, pinTX, BaudRate.BaudRate9600)
        //isConnected = true
        basic.pause(200)
    }
    
    // -------------- 3. TCP ----------------
    /**
    * connect to TCP server
    */
    //% blockId=gsm_connect_server
    //% block="connect to TCP server IP: %ip| port %port"  
    //% weight=90
    //% blockGap=7
    //% group="TCP"
    export function connectServer(ip: string, port: string): number{
      return(1)
    }
    
    /**
    * send data to TCP server
    */
    //% blockId=gsm_send_server
    //% block="send data %msg"  
    //% weight=90
    //% blockGap=7
    //% group="TCP"
    export function sendServer(msg: string): number{
      return(1)
    }

    /**
    * receive data from TCP server
    */
    //% blockId=gsm_receive_server
    //% block="receive data"  
    //% weight=90
    //% blockGap=7
    //% group="TCP"
    export function receiveServer(): number{
      return(1)
    }    
}
