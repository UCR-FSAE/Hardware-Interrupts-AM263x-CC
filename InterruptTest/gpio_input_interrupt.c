/*
 *  Copyright (C) 2021 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <kernel/dpl/DebugP.h>
#include <kernel/dpl/ClockP.h>
#include <kernel/dpl/AddrTranslateP.h>
#include <kernel/dpl/HwiP.h>
#include "ti_drivers_config.h"
#include "ti_drivers_open_close.h"
#include "ti_board_open_close.h"

/*
 * This example configures a GPIO pin in input mode
 * and configures it to generate interrupt on rising edge.
 * The application waits for 5 key presses, prints the
 * number of times the keys are pressed and exits.
 */

// Extra comments for better understanding code


uint32_t            gGpioBaseAddr = GPIO_PUSH_BUTTON_BASE_ADDR;  // Macro auto generated from TI drivers through syscfg
HwiP_Object         gGpioHwiObject;                              // Declares specific interrupt object to be used with construction
volatile uint32_t   gGpioIntrDone = 0;                           // Global variable to be used in example

static void GPIO_bankIsrFxn(void *args);                         // The hardware interrupt declaration

extern void Board_gpioInit(void);
extern void Board_gpioDeinit(void);
extern uint32_t Board_getGpioButtonIntrNum(void);
extern uint32_t Board_getGpioButtonSwitchNum(void);              // Helper functions in board.c

void gpio_input_interrupt_main(void *args)
{
    int32_t         retVal;
    uint32_t        pinNum, intrNum, buttonNum;
    uint32_t        waitCount = 5;
    HwiP_Params     hwiPrms;                                     // Interrupt object meant to hold all parameters

    /* Open drivers to open the UART driver for console */
    Drivers_open();
    Board_driversOpen();
    Board_gpioInit();

    DebugP_log("GPIO Input Interrupt Test Started ...\r\n");
    DebugP_log("GPIO Interrupt Configured for Rising Edge (Button release will trigger interrupt) ...\r\n");

    pinNum          = GPIO_PUSH_BUTTON_PIN;
    intrNum         = Board_getGpioButtonIntrNum();              // Sets the interrupt number to match push button interrupt number
    buttonNum       = Board_getGpioButtonSwitchNum();

    /* Address translate */
    gGpioBaseAddr = (uint32_t) AddrTranslateP_getLocalAddr(gGpioBaseAddr);

    /* Register pin interrupt */
    HwiP_Params_init(&hwiPrms);                                  // Initializes interrupt object to be able to be used
    hwiPrms.intNum   = intrNum;                                  // .intNum sets the location of the interrupt in memory. Location is set to one linked with GPIO push button
    hwiPrms.callback = &GPIO_bankIsrFxn;                         // Links the interrupt function to interrupt object
    hwiPrms.args     = (void *) pinNum;                          // Passes this number as parameter when interrupt called
    /* GPIO interrupt is a pulse type interrupt */
//    hwiPrms.isPulse  = TRUE;                                   // Sets that the interrupt to enter on the rising edge of clock cycle, commented out for this example
    retVal = HwiP_construct(&gGpioHwiObject, &hwiPrms);          // Constructs Interrupt and sets it to be active
    DebugP_assert(retVal == SystemP_SUCCESS );

    DebugP_log("Press and release SW%d button on EVM to trigger GPIO interrupt ...\r\n", buttonNum);
    while(gGpioIntrDone < waitCount)
    {
        /* Keep printing the current GPIO value */
        DebugP_log("Key is pressed %d times\r\n", gGpioIntrDone);
        ClockP_sleep(1);
    }
    DebugP_log("Key is pressed %d times\r\n", gGpioIntrDone);

    DebugP_log("GPIO Input Interrupt Test Passed!!\r\n");
    DebugP_log("All tests have passed!!\r\n");

    Board_gpioDeinit();
    Board_driversClose();
    Drivers_close();
}

static void GPIO_bankIsrFxn(void *args)
{
    uint32_t    pinNum = (uint32_t) args;
    uint32_t    bankNum =  GPIO_GET_BANK_INDEX(pinNum);
    uint32_t    intrStatus, pinMask = GPIO_GET_BANK_BIT_MASK(pinNum);

    /* Get and clear bank interrupt status */
    intrStatus = GPIO_getBankIntrStatus(gGpioBaseAddr, bankNum);
    GPIO_clearBankIntrStatus(gGpioBaseAddr, bankNum, intrStatus);

    /* Per pin interrupt handling */
//    if(intrStatus & pinMask)
//    {
//        gGpioIntrDone++;        // Commented out and altered to immediately increase when ISR is entered into.
//    }
    gGpioIntrDone++;
}
