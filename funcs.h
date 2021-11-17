#pragma once
#include "time.h"
#include "movie.h"
#include "timeslot.h"
//Task A:
int minutesSinceMidnight(Time time);
int minutesUntil(Time earlier, Time later);
//Task B:
Time addMinutes(Time time0, int min);
//Task C:
std::string getTimeSlot(TimeSlot ts);
//Task D:
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie);
//Task F:
bool timeOverlap(TimeSlot ts1, TimeSlot ts2);