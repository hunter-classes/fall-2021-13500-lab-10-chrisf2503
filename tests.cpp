#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "funcs.h"
#include "time.h"
//#include "movie.h"
//#include "timeslot.h"
Time t1 = {2, 9};
Time t2 = {9, 10};
Time t3 = {13,39};
Movie movie1 = {"Back to the Future", COMEDY, 116};
Movie movie2 = {"Black Panther", ACTION, 134};
TimeSlot morning = {movie1, {9, 15}};  
TimeSlot daytime = {movie2, {12, 15}}; 
TimeSlot evening = {movie2, {16, 45}};
TimeSlot night = {movie2, {13, 9}};
TimeSlot ran = {movie1, {18, 59}};
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
TEST_CASE("Task C:"){
    CHECK(getTimeSlot(daytime) == "Black Panther ACTION (134 min) [starts at 12:15, ends by 14:29]");
    CHECK(getTimeSlot(evening) == "Black Panther ACTION (134 min) [starts at 16:45, ends by 18:59]");
    CHECK(getTimeSlot(morning) == "Back to the Future COMEDY (116 min) [starts at 9:15, ends by 11:11]");
}
TEST_CASE("Task D: "){
    std::string sentence = getTimeSlot(scheduleAfter(morning, movie2));
    CHECK(sentence == "Black Panther ACTION (134 min) [starts at 11:11, ends by 13:25]");
    sentence = getTimeSlot(scheduleAfter(daytime, movie1));
    CHECK(sentence == "Back to the Future COMEDY (116 min) [starts at 14:29, ends by 16:25]");
    sentence = getTimeSlot(scheduleAfter(evening, movie2));
    CHECK(sentence == "Black Panther ACTION (134 min) [starts at 18:59, ends by 21:13]");
}
TEST_CASE("Task E: "){
    CHECK(timeOverlap(daytime, night));
    CHECK(timeOverlap(morning, evening) == false);
    CHECK(timeOverlap(ran, evening) == false);
    
}//*