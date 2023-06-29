/*
Drill
This drill simply involves getting the sequence of versions of Date to work.
For each version define a Date called today initialized to June 25, 1978. 
Then, define a Date called tomorrow and give it a value by copying today into it and increasing 
its day by one using add_day(). Finally, output today and tomorrow using a << defined as in §9.8.
Your check for a valid date may be very simple. Feel free to ignore leap years. 
However, don’t accept a month that is not in the [1,12] range or day of the month 
that is not in the [1,31] range. Test each version with at least one invalid date (e.g., 
2004, 13, –5).
 1. The version from §9.4.1
 2. The version from §9.4.2

*/


#include "../std_lib_facilities.h"

struct Date{
    int day;
    int month;
    int year;
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    void add_day(int n);
};

void init_date(Date& today, int day, int month, int year);
void printDate(Date& today);

int main(int argc, char* argv[]){
    cout<<argc<<'\n';
    cout<<*argv<<'\n';
// 1. The version from §9.4.1
// June 25, 1978.
    Date today(25,06,1978);
    // init_date(today, 25, 06, 1978);
    printDate(today);
    today.add_day(1);
    printDate(today);

    Date tomorrow = today;
    tomorrow.add_day(1);

    printDate(today);
    printDate(tomorrow);
}

void printDate(Date& today){
    cout<<today.day<<"/";
    cout<<today.month<<"-";
    cout<<today.year<<"\n";
}

void init_date(Date& today, int day, int month, int year){
    today.day = day;
    today.month = month;
    today.year = year;
}

void Date::add_day(int n){
    Date::day += n;
}