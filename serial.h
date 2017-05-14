/*Library Includes---------------------------------------------------------------------*/
#include "mbed.h"
#include <string>

/*Std----------------------------------------------------------------------------------*/
using std::string;

/*Getters and Setters------------------------------------------------------------------*/
string get_serial(void);
void set_serial(string input);

/*Private Functions--------------------------------------------------------------------*/
string read_byte(void);
void flush_serial(void);
int find_sync_byte(void);
double get_serial_timing(void);
void send_serial(string serialout);
void set_serialtime(void);
void reset_serialtime(void);
double get_serialtime(void);
void send_float(double num);
