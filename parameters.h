/*Module Includes----------------------------------------------------------------------*/
#include "pacing.h"
#include "serial.h"

/*Library Includes---------------------------------------------------------------------*/
#include <bitset>
#include <string>

/*Std----------------------------------------------------------------------------------*/
using namespace std;
using std::string;

/*Getters and Setters------------------------------------------------------------------*/
string get_pacingstate(void);
string get_pacingmode(void);
int get_lower_rate_limit(void);
int get_upper_rate_limit(void);
int get_max_sensor_rate(void);
double get_v_pace_amp(void);
double get_v_pulse_width(void);
string get_activity_theshold(void);
int get_reaction_time(void);
int get_response_factor(void);
int get_recovery_time(void);

//Private Functions--------------------------------------------------------------------*/
void build_struct(void);
std::bitset<8> bitsetString_8(string input);
std::bitset<16> bitsetString_16(string input);
int int_handler(string input);
double double_handler(string input_1,string input_2);
int verify_struct(void);
int isValid(double value, double lower_limit, double upper_limit, double increment);
void assign_values(void);
