/*Header File--------------------------------------------------------------------------*/
#include "pacing.h"

/*Private Variables--------------------------------------------------------------------*/
string pacingstate;
string pacingmode;
int lower_rate_limit = 0;
int upper_rate_limit = 0;
int max_sensor_rate = 0;
int vPacing = 0;
double v_pace_amp = 0;
double v_pulse_width = 0;
double pace_time = 0;


/*Getters and Setters------------------------------------------------------------------*/
string get_pacingstate(void)
{
	return pacingstate;
}

string get_pacingmode(void)
{
	return pacingmode;
}

int get_lower_rate_limit(void)
{
	return lower_rate_limit;
}

int get_upper_rate_limit(void)
{
	return upper_rate_limit;
}

int get_max_sensor_rate(void)
{
	return max_sensor_rate;
}

double get_v_pace_amp(void)
{
	return v_pace_amp;
}

double get_v_pulse_width(void)
{
	return v_pulse_width;
}

void set_pacingstate(string input)
{
	pacingstate = input;
}

void set_pacingmode(string input)
{
	pacingmode = input;
}

void set_lower_rate_limit(int input)
{
	lower_rate_limit = input;
}

void set_upper_rate_limit(int input)
{
	upper_rate_limit = input;
}

void set_max_sensor_rate(int input)
{
	max_sensor_rate = input;
}

void set_v_pace_amp(double input)
{
	v_pace_amp = input;
}

void set_v_pulse_width(double input)
{
	v_pulse_width = input;
}

/*Private Functions--------------------------------------------------------------------*/

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
		// Write Logic HIGH To Chamber's pin
    vPacing = 1;
		DigitalOut(LED1,0);
}

// Pace stop function
//
// Stops the pacing
void pace_stop(void)
{
	// Write Logic LOW To Chamber's pin
    vPacing = 0;
		DigitalOut(LED1,1);
}

int isvPacing(void)
{
	return vPacing;
}

void set_paceofftime(void)
{
	pace_time = lower_rate_limit/60 - v_pulse_width;
}