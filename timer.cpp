#include "timer.h"
#include "motion.h"

/*Private variables*/
double timer = 0;
Ticker time_ticker;
double t_vPace = 0;
double t_vPaceOff = 0;
double t_egram = 0;
double t_motion = 0;
double t_serial = 0;
int vPace = 0;
int vPaceSet = 0;
int notvPaceSet = 0;
int pending = 0;


// Initializes timing
//
// The function attaches a 0.1ms ticker to a timing function
void timer_init(void)
{
    time_ticker.attach(&timer_tick, 0.0001);
		schedule_event();
}

// The timing function
//
// Increments the timer variable each tick (0.1ms)
void timer_tick(void)
{
    if (timer != 0 && !pending)
    {
        excute_events();
    }
    timer += 0.1;
    // if (check_pacing() == 1)
    //{
    //  pace_now();
    //}
}

// Returns the current timer value
//
// The function returns a double that represents the timer value in ms
double get_timer(void)
{
    return timer;
}

// Timer reset function
//
// Resets the value of the timer variable to zero
//
// I'm still not sure when the timer starts and when it resets
void reset_timer(void)
{
    timer = 0;
}


// Event scheduling function
//
// Schedules an event to happen after deltatime
// The events can be pacing, sensing, ecg streaming, etc..
//
// When parameters are set first time this function will be called
void schedule_event(void)
{
//    if (event == "vpace") // Start Ventricular pace
//    {
//        t_vPace = timer + deltatime;

//    }
//    else if (event == "vpaceoff") // Stop Ventricular pace
//    {
//        t_vPaceOff = timer + deltatime;
//    }
//    if (event == "egram")
//    {
//        t_egram = timer + deltatime;
//    }
//    if (event == "motion")
//    {
//        t_motion = timer + deltatime;
//    }
//		if (event == "serial")
//		{
//			t_serial = timer + deltatime;
//		}
			pending = 1;
			if (get_serialtime() > 0)
			{
				t_serial = timer + get_serialtime();
			}
			if (get_lower_rate_limit()> 0 && get_v_pulse_width() > 0 && t_serial != 0 && vPaceSet == 0)
			{
				vPaceSet = 1;
				t_vPace = timer + (60000/get_lower_rate_limit() -  get_v_pulse_width());
				
			}
			if (get_v_pulse_width() > 0 && get_lower_rate_limit()> 0 && t_serial != 0 && notvPaceSet == 0)
			{
				notvPaceSet = 1;
				t_vPaceOff = t_vPace + get_v_pulse_width();
				
			}
			pending = 0;
}

// Event excuting function
//
// Checks if it is time to excute a scheduled event or not
void excute_events(void)
{
		
		if (timer > t_vPace && isvPacing() == 0 && t_vPace != 0 && vPaceSet == 1) // Start Ventricular pace
    {
        pace_now();
				send_float(timer);
				notvPaceSet = 0;
				schedule_event();
    }
    if (timer > t_vPaceOff && isvPacing() == 1 && t_vPaceOff != 0 && notvPaceSet == 1) // Stop Ventricular pace
    {
        pace_stop();
				vPaceSet = 0;
				schedule_event();
    }
		if (timer > t_serial && t_serial != 0)
		{	
				t_serial = 0;
				read_function_code();
				schedule_event();
		}
		
		
    
//    if (timer > t_egram & t_egram != 0)
//    {
//        send_egram();
//    }
//    if (timer > t_motion & t_motion != 0)
//    {
//        motion_thread();
//    }

}



// NOTE TO SELF: Add markers for waiting to perform the next step
