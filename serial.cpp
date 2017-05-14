/*Header File--------------------------------------------------------------------------*/
#include "serial.h"

/*Private Variables--------------------------------------------------------------------*/
Serial pc(USBTX,USBRX);
double TIMING_PERIOD = 1000; 

//string that stores the serial
string serial;

//incremental value, identifies a char in the serial string
int increment = 0;

//K_SYNC char<8> string 
string K_SYNC = "00010110";

/*Getters and Setters------------------------------------------------------------------*/

string get_serial(void)
{
	return serial;
}

//Setter serial
void set_serial(string input)
{
	serial = input;
}

//Private Functions--------------------------------------------------------------------*/

//Reads the next char<8> substring in serial, increment increases by 8 after execution
string read_byte(void)
{
	string byte = "";
	for (int i=0; i < 8; i++)
	{
		byte += pc.getc();
	}
	return byte;
}

//Flushes the serial string
void flush_serial(void)
{
//	char c;
//	while (pc.readable() > 0)
//	{
//		c = pc.getc();
//	}
}

//Checks for K_SYNC_byte at the start of the serial, if it is not found, the serial is flushed
int find_sync_byte(void)
{
	string insync = read_byte();
	if (insync == K_SYNC)
	{
		//TIMING_PERIOD = 0;
		return 1;
	}
	if (insync == "")
	{
		return 0;
	}
	//flush_serial();
	return 0;
}

double get_serial_timing(void)
{
	return TIMING_PERIOD;
}

void send_serial(string serialout)
{
	pc.printf(serialout.c_str());
	pc.printf("\n");
}

void send_float(double num)
{
	pc.printf("%f", num);
	pc.printf("\n");
}

void reset_serialtime(void)
{
	//flush_serial();
	TIMING_PERIOD = 0;
}

void set_serialtime(void)
{
	//flush_serial();
	TIMING_PERIOD = 1000;
}

double get_serialtime(void)
{
	return TIMING_PERIOD;
}
