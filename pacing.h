/*Module Includes----------------------------------------------------------------------*/
#include "mbed.h"
//#include "timer.h"

/*Library Includes---------------------------------------------------------------------*/
#include <string>

/*Std----------------------------------------------------------------------------------*/
using std::string;

/*Getters and Setters------------------------------------------------------------------*/
string get_pacingstate(void);
string get_pacingmode(void);
int get_lower_rate_limit(void);
int get_upper_rate_limit(void);
int get_max_sensor_rate(void);
double get_v_pace_amp(void);
double get_v_pulse_width(void);
void set_pacingstate(string input);
void set_pacingmode(string input);
void set_lower_rate_limit(int input);
void set_upper_rate_limit(int input);
void set_max_sensor_rate(int input);
void set_v_pace_amp(double input);
void set_v_pulse_width(double input);
void set_pacetime(void);
double get_pacetime(void);


/*Private Functions--------------------------------------------------------------------*/
void pace_now(void);
void pace_stop(void);
void reset_pacetime(void);
int isvPacing(void);
