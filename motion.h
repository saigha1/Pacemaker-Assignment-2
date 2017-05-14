#include "mbed.h"

void initialize_motion(void) ;
bool isMotionThresholdExceeded(void);
void resetMotionDetection(void);
void a_count(void);
void motion_thread(void);