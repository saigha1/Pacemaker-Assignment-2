#include "mbed.h"
#include "pacing.h"
#include "motion.h"
#include "serial.h"
#include "egram.h"
#include "function.h"
#include <string>

void timer_init(void);
void timer_tick(void);
double get_timer(void);
void reset_timer(void);
void schedule_event(void);
void excute_events(void);
