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
 3. The version from §9.4.3
 4. The version from §9.7.1
 5. The version from §9.7.4

*/

#include "../std_lib_facilities.h"

enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, okt, nov, des
};

class Year
{
public:
    class Invalid {};
    Year(int y);
    int year(){return y;}
    //~Year();
private:
    static const int min = 1800;
    static const int max = 2200;
    int y;
};



class Date
{
public:
    Date();
    //Date(Year y);
    Date(int d, Month m, Year y);
    void add_day(int n);
    int day()const{return d;}
    Month month()const{return m;}
    Year year()const{return y;}
private:
    int d;
    Month m;
    Year y;
};

const Date& default_date();
ostream& operator<<(ostream& os, const Date& d);


int main(int argc, char* argv[]){
    cout<<argc<<'\n';
    cout<<*argv<<'\n';
    // June 25, 1978.

    Date today(25, Month::jun, Year(1978));
    Date defaultDate;
    cout<<defaultDate.day()<<'\n';
    vector<Date>hello(10);
    for (size_t i = 0; i < 10; i++)
    {
        cout<<hello[i]<<'\n';
    }
    
    //cout<<defaultDate.month()<<'\n';
    //cout<<defaultDate.year()<<'\n';
    //cout<<today.day()<<'\n';
    today.add_day(1);
    // cout<<today.day()<<'\n';
    // cout<<today.year()<<'\n'; TODO: FIX
    // cout<<today.month()<<'\n'; TODO: fix
    
}

// Date::Date() :d(1), m(Month::jan), y(2000) {};

Date::Date(int day, Month month, Year year) : d(day), m(month), y(year){}


Date::Date()
    :d(default_date().day()),
    m(default_date().month()),
    y(default_date().year())
{}


void Date::add_day(int n){
    Date::d += n;
}

Year::Year(int year) : y(year){
    if(year<min||year>=max) 
        throw Invalid{}; 
}

const Date &default_date()
{
    static Date dd(1, Month::jan, Year(2001));
    return dd;
}


ostream& operator<<(ostream& os, const Date& d){
    return os<<'('<<d.day()
             <<','<<int(d.month())
             <<','<<d.year().year()<<')';
}