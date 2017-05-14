#include "pacing.h"
#include "timer.h"
#include "rtos.h"

// Pace now function
//
// A function that is called to generate pace according to the
// settings i.e. the chamber
//
// ** I'm not sure if I should have the chamber as an argument or
//    there is another way
//
// *** I think a possible solution is to find out what mode it's
//     or have a chamber variable that is set when parameters are
void pace_now(void)
{
    // Pace in here
    DigitalOut(LED1, 0);
    schedule_event("vpaceoff", 1000);
}

// Pace stop function
//
// Stops the pacing
void pace_stop(void)
{
    DigitalOut(LED1, 1);
    schedule_event("vpace", 500);
}
