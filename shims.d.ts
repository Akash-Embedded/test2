// Auto-generated. Do not edit.


    /**
     */

declare namespace GSM {

    /**
     * Initialize MU.
     */
    //% blockId=GSM_SIM900SendSms block="message %msg | number %number"
    //% group="SMS1" shim=GSM::SIM900SendSms
    function SIM900SendSms(msg: string, number: string): int32;

    /**
     * Initialize MU.
     */
    //% blockId=GSM_SIM900RecieveSms block="message %rcvMsg | number %number"
    //% group="SMS1" shim=GSM::SIM900RecieveSms
    function SIM900RecieveSms(rcvMsg: string, number: string): void;
}

// Auto-generated. Do not edit. Really.
