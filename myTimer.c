/*
 * myTimer.c
 *
 *  Created on: 5 March 2020
 *      Author: Tiara Hollins
 */

#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include "myTimer.h"

// TODO: Write a function that can intialize a Timer with particular values for pre-scale and count. --COMPLETED
// Aliases for the Timers and the preScaler arguments are defined in myTimer.h
void initTimer(unsigned int timer, unsigned int preScaler, unsigned int count)
{
    // For the specified timer and pre-scale value, put the timer in 32-bit periodic mode.
    Timer32_initModule(timer,preScaler,TIMER32_32BIT,TIMER32_PERIODIC_MODE);

    // For the specified timer, pass the count value.
    Timer32_setCount(timer,count);

    // For the specified timer, configure the timer to repeat once it elapses.
    Timer32_startTimer(timer,REPEAT);
}

// TODO: Write a function that indicates whether Timer0 has expired. --COMPLETED
// You have been given a such a function in the lecture slides.
bool timer0Expired(void)
{
    static unsigned int prev = MAX_VALUE;
    unsigned int cur;
    bool returnValue;

    cur = Timer32_getValue(TIMER0);
    returnValue = (cur > prev);
    prev = cur;
    return returnValue;
}

// TODO: Write a function that indicates whether Timer1 has expired. --COMPLETED
// This is essentially a copy of the previous function, using a different timer.
// Since we only have two timers, later in the course we will create software timers that use a common time base.
bool timer1Expired(void)
{
    static unsigned int prev = MAX_VALUE;
        unsigned int cur;
        bool returnValue;

        cur = Timer32_getValue(TIMER1);
        returnValue = (cur > prev);
        prev = cur;
        return returnValue;
}
