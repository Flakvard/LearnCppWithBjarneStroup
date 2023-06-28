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
 3. The version from §9.4.3
 4. The version from §9.7.1
 5. The version from §9.7.4

*/


#include "../std_lib_facilities.h"

struct Date{
    int year;
    int month;
    int day;
};

Date add_day(Date today);

int main(int argc, char* argv[]){
// 1. The version from §9.4.1
// June 25, 1978.
    Date today;
    today.day = 25;
    today.month = 06;
    today.year = 1978;

    Date tomorrow = add_day(today);

    cout<<today.day;
    cout<<today.month;
    cout<<today.year;

    cout<<'\n';

    cout<<tomorrow.day;
    cout<<tomorrow.month;
    cout<<tomorrow.year;
}

Date add_day(Date today){
    today.day = today.day + 1;
    return today;
}