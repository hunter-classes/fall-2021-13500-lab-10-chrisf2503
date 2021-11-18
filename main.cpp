#include <iostream>
#include "funcs.h"
#include "time.h"
#include "movie.h"
#include "timeslot.h"

int main(){
    std::cout << "Task A: \n";
    Time earlier = {10, 30};
    int totalmin = minutesSinceMidnight(earlier);
    std::cout << totalmin << "\n";
    Time later = {13, 40};
    totalmin = minutesSinceMidnight(later);
    std::cout << totalmin << "\n";
    int gap = minutesUntil(earlier, later);
    std::cout << gap << "\n";
    std::cout << "----------------------\nTask B:\n";
    Time time0 = {8, 10};
    std::cout << "Original Hour: " << time0.h << " Original minutes: " << time0.m << "\n";
    std::cout << "Adding minutes: 125\n";
    time0 = addMinutes(time0, 125);
    std::cout << "New Hour: " << time0.h << " New Minutes: " << time0.m << "\n";
    std::cout << "----------------------\nTask C:\n";
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    TimeSlot morning = {movie1, {9, 15}};  
    TimeSlot daytime = {movie2, {12, 15}}; 
    TimeSlot evening = {movie2, {16, 45}};
    std::cout << getTimeSlot(morning) << '\n';
    std::cout << getTimeSlot(daytime) << '\n';
    std::cout << getTimeSlot(evening) << '\n';
    std::cout << "----------------------\nTask D:\n";
    TimeSlot newTs = scheduleAfter(evening, movie2);
    std::cout << "Current movie playing: " << getTimeSlot(evening) << '\n';
    std::cout << "Next movie to play: " << getTimeSlot(newTs) << "\n";
    std::cout << "----------------------\nTask E:\n";
    //timeOverlap(morning, daytime);
    std::cout << "morning timeslot, daytime timeslot: ";
    if(timeOverlap(morning, daytime)){
        std::cout << "Does overlap\n";
    } 
    else{
        std::cout << "Does not overlap\n";
    }//*/
}