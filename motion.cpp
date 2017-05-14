#include "motion.h"
#include "FXOS8700Q.h"

I2C i2c(PTE25, PTE24);
FXOS8700QAccelerometer acc(i2c, FXOS8700CQ_SLAVE_ADDR1);
//DigitalOut rled(LED1);
//DigitalOut gled(LED2);

/* Constants and Declares */
int numCount;
int const MAX_NUM_COUNTS = 3;
int const TIMING_PERIOD = 20; // Sensor polling interval

uint8_t motion_exceeded_threshold = 0;

void initialize_motion () {
		//char p;
//		while (p!= 's')
//		{
//			p = pc.getc();
//		}
    acc.enable();
}

bool isMotionThresholdExceeded () {
    return motion_exceeded_threshold;
}

void resetMotionDetection () {
    motion_exceeded_threshold = 0;
}

/**** Function: a_count
 * return: void
 * parameters: none
 * A function called if motion detection interrupt flag is set.  Maintains
 * a global counter and sets a timer to keep track of number of flags within
 * timing limit.
 */
void a_count(void) {
    /* step 1 increment the counter */
    numCount++;


    if (numCount >= MAX_NUM_COUNTS) {
//        rled = !rled;   // toggle LEDs to show acceleration threshold reached
//        gled = !gled;   // toggle LEDS to show acceleration threshold reached
        motion_exceeded_threshold = 1;
    }
}

void motion_thread () {
				motion_data_units_t acc_data, mag_data;
				motion_data_counts_t acc_raw, mag_raw;
				float xAcc, yAcc, zAcc;

				acc.getAxis(acc_raw);

        acc.getX(xAcc);
        acc.getY(yAcc);
        acc.getZ(zAcc);

        float magtd = xAcc*xAcc + yAcc*yAcc + zAcc*zAcc;
        if (magtd > 3.0f) { // Greater than (1.5G of Accel.)^2
            a_count();      // increment acceleration event counter
        }
				
}
