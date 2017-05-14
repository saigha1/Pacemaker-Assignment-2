/*Header File--------------------------------------------------------------------------*/
#include "parameters.h"

/*Structures---------------------------------------------------------------------------*/

//Structure that holds programmable values
struct prog
{
    string pacingstate;
    string pacingmode;
    int lower_rate_limit;
    int upper_rate_limit;
    int max_sensor_rate;
    double v_pace_amp;
    double v_pulse_width;
    string activity_threshold;
    int reaction_time;
    int response_factor;
    int recovery_time;
};

/*Private Variables--------------------------------------------------------------------*/

//Create sructure of type prog named progStruct
prog progStruct;

/*Getters and Setters------------------------------------------------------------------*/

//Private Functions--------------------------------------------------------------------*/

//Builds a structure of type prog and sets the instance variables
void build_struct(void)
{
    //Read pacing mode
    progStruct.pacingmode = read_byte();
		
    //if OFF mode:
    if (progStruct.pacingmode == "00000000")
    {
        //OFF
    }

    //else if VOOR mode:
    else if (progStruct.pacingmode == "00100101")
    {
        //VOOR
        //Read next byte, store in lower_rate_limit
        progStruct.lower_rate_limit = int_handler(read_byte());
        //Read next byte, store in upper_rate_limit
        progStruct.upper_rate_limit = int_handler(read_byte());
        //Read next byte, store in max_sensor_rate
        progStruct.max_sensor_rate = int_handler(read_byte());
        //Read next two bytes, store first in left, store second in right
        string byte_1 = read_byte();
        string byte_2 = read_byte();
        //Set v_pace_amp as doublehandler(left,right)
        progStruct.v_pace_amp = double_handler(byte_1,byte_2);
        //Read next two bytes, store first in left, store second in right
        byte_1 = read_byte();
        byte_2 = read_byte();
        //Set v_pulse_width as doublehandler(left,right)
        progStruct.v_pulse_width = double_handler(byte_1,byte_2);
        //Read next byte, store in activity_threshold
        progStruct.activity_threshold = read_byte();
        //Read next byte, store in reaction_time
        progStruct.reaction_time = int_handler(read_byte());
        //Read next byte, store in response_factor
        progStruct.response_factor = int_handler(read_byte());
        //Read next byte, store in recovery_time
        progStruct.recovery_time = int_handler(read_byte());
    }

}

//Converts a char<8> sized string of 0's and 1's to a bitset<8>
std::bitset<8> bitsetString_8(string input){
    bitset<8> output (input);
    return output;
}

//Converts a char<16> sized string of 0's and 1's to a bitset<16>
std::bitset<16> bitsetString_16(string input){
    bitset<16> output (input);
    return output;
}

//Converts a char<8> sized string of 0's and 1's to an int
int int_handler(string input)
{
    int output = bitsetString_8(input).to_ulong();
    return output;
}

//Converts two char<8> sized strings of 0's and 1's to a double
//
//Additional Info:
//Both strings are concatenated to create one char<16> sized string.
//The char<16> sized string is converted to an int.
//The int is converted to a double where the last 2 numbers are placed right of the doubleing point.
//
double double_handler(string input_1, string input_2)
{
    double output = double(bitsetString_16(input_1+input_2).to_ulong())/100;
    return output;
}

//returns 1 if the progStruct has valid instance variables
int verify_struct(void)
{
    if (get_pacingmode() == "00100101") //Make sure mode is VOOR
    {
        //Do Nothing
    }

    else
    {
        return 0;
    }

    if ( isValid(progStruct.lower_rate_limit , 50, 90, 1) == 0) //lower rate limit verification
    {
        return 0;
    }

    if ( isValid(progStruct.upper_rate_limit, 50, 175, 5) == 0) //upper rate limit verification
    {
        return 0;
    }

    if ( isValid(progStruct.max_sensor_rate, 50, 175, 5) == 0) //max sensor rate verification
    { 
        return 0;
    }

    if ( isValid(progStruct.v_pace_amp, 3.5, 7.0, 0.5) == 0) //pace applitude verification
    {
        return 0;
    }

    if ( isValid(progStruct.v_pulse_width,0.1, 1.9, 0.1) == 0) //pulse width verification
    {
        return 0;
    }

    if ( isValid(progStruct.reaction_time, 10, 50, 10) == 0) //reaction time verification
    {
        return 0;
    }

    if ( isValid(progStruct.response_factor, 1, 16, 1) == 0) //response factor verification
    {
        return 0;
    }

    if ( isValid(progStruct.recovery_time, 2, 16, 1) == 0){ //recovery time verification
        return 0;
    }
    
    return 1; //all variables are valid
}

int isValid(double value, double lower_limit, double upper_limit, double increment)
{
    double div = value/increment; //divides value by increment. if div has decimals, value is not following incrementation
    if (lower_limit <= value && value <= upper_limit && (div == (int)div) ) {
        return 1;
    }
    else {
        return 0;
    }
}

void assign_values(void)
{
    //set_pacingstate(progStruct.pacingstate);
    set_pacingmode(progStruct.pacingmode);
    set_lower_rate_limit(progStruct.lower_rate_limit);
    set_upper_rate_limit(progStruct.upper_rate_limit);
    set_max_sensor_rate(progStruct.max_sensor_rate);
    set_v_pace_amp(progStruct.v_pace_amp);
    set_v_pulse_width(progStruct.v_pulse_width);
		flush_serial();
		set_serialtime();
}
