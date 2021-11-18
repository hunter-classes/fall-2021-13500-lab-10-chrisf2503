#include <iostream> 
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

int minutesSinceMidnight(Time time){
    return (time.h * 60) + time.m;
}
int minutesUntil(Time earlier, Time later){
    int earlyTotal = minutesSinceMidnight(earlier);
    int lateTotal = minutesSinceMidnight(later);
    return lateTotal - earlyTotal;
}
Time addMinutes(Time time0, int min){
    int totalMin = time0.m + min;
    if(totalMin >= 60){
        time0.m = totalMin - 60;
        time0.h += 1;
        time0 = addMinutes(time0, 0);
    }
    return time0;
}
std::string getMovie(Movie mv){
    std::string output = "";
    std::string g = "";
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    output = mv.title + " " + g + " (" + std::to_string(mv.duration) + " min)";
    return output;
}
std::string getTimeSlot(TimeSlot ts){
    std::string output = getMovie(ts.movie) + " [starts at " + std::to_string(ts.startTime.h) + ":" + std::to_string(ts.startTime.m) + ",";
    Time t = addMinutes(ts.startTime, ts.movie.duration);
    output += " ends by " + std::to_string(t.h) + ":" + std::to_string(t.m) + "]";
    return output;
}
TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot newTs;
    Time newTime = addMinutes(ts.startTime, ts.movie.duration);
    newTs = {nextMovie, newTime};
    return newTs;
}
bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    int lowerMin = minutesSinceMidnight(ts1.startTime);
    //std::cout << lowerMin << '\n';
    int trackOrig = lowerMin;
    int upperMin = minutesSinceMidnight(addMinutes(ts1.startTime, ts1.movie.duration));
    //std::cout << upperMin << '\n';
    int nextMovie = minutesSinceMidnight(ts2.startTime);
    //std::cout << nextMovie << '\n';
    if(lowerMin <= nextMovie && nextMovie < upperMin){
        return true;
        //std::cout << "this should return true";
    }
    else{
        lowerMin = minutesSinceMidnight(ts2.startTime);
        //std::cout << lowerMin << '\n';
        upperMin = minutesSinceMidnight(addMinutes(ts2.startTime, ts2.movie.duration));
        //std::cout << upperMin << '\n';
        nextMovie = minutesSinceMidnight(ts1.startTime);
        if(lowerMin <= trackOrig && trackOrig < upperMin){
            return true;
            //std::cout << "this should return true\n";
        }
        else{
            return false;
            //std::cout << "this should return false\n";
        }//*/
    
    }
}