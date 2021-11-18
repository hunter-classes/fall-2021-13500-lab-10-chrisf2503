#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "time.h"
//#include "movie.h"
//#include "timeslot.h"
Time t1 = {2, 9};
Time t2 = {9, 10};
Time t3 = {13,39};
Time createTimeObject(int hour, int min){
    Time t = {hour, min};
    return t;
}
TEST_CASE("Task A:"){
    CHECK(minutesSinceMidnight(t1) == 129);
    CHECK(minutesSinceMidnight(t2) == 550);
    CHECK(minutesSinceMidnight(t3) == 819);
    CHECK(minutesUntil(t1, t2) == 421);
    CHECK(minutesUntil(t2, t3) == 269);
    CHECK(minutesUntil(t1, t3) == 690);
}
TEST_CASE("Task B:"){
    Time test = addMinutes(t1, 60);
    int hour = test.h;
    int minutes = test.m;
    bool check = (test.h == 3 && test.m == 9);
    CHECK(check);
    test = addMinutes(t3, 160);
    check = (test.h == 16 && test.m == 19);
    CHECK(check);
    test = addMinutes(t2, 240);
    check = (test.h == 13 && test.m == 10);
    CHECK(check);
}