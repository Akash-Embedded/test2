// Auto-generated. Do not edit.


    /**
     */

declare namespace GSM {

    /**
     * Initialize MU.
     */
    //% blockId=GSM_SIM900SendSms block="send message %msg| to %number"
    //% group="SMS" shim=GSM::SIM900SendSms
    function SIM900SendSms(msg: string, number: string): int32;

    /**
     * Initialize MU.
     */
    //% blockId=GSM_SIM900RecieveSms block= Receive message from number %number"
    //% group="SMS" shim=GSM::SIM900RecieveSms
    function SIM900RecieveSms(number: string): string;
}

// Auto-generated. Do not edit. Really.
