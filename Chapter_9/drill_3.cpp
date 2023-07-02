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
    void add_year(int n);
    //~Year();
private:
    static const int min = 1800;
    static const int max = 2200;
    int y;
};

class Day
{
public:
    class Invalid {};
    Day(int day);
    int day() const {return d;}
    void add_day(int n);
private:
    int d;
    static const int max = 31;
    static const int min = 1;
};



class Date
{
public:
    Date();
    //Date(Year y);
    Date(Day d, Month m, Year y);
    Day day()const{return d;}
    Month month()const{return m;}
    Year year()const{return y;}

    void add_day(int n);
    void add_month(int n);
    void add_year(int n);
private:
    Day d;
    Month m;
    Year y;
};

const Date& default_date();
ostream& operator<<(ostream& os, const Date& d);

Day::Day(int day){
    if (day > max || day < min){
        Invalid();
    }else
    {
        d = day;
    }
    
}


int main(int argc, char* argv[]){
    cout<<argc<<'\n';
    cout<<*argv<<'\n';
    // June 25, 1978.

    Date today(Day(25), Month::jun, Year(1978));
    cout<<today<<'\n';
    today.add_month(7);
    today.add_year(2);
    cout<<today<<'\n';

    Date defaultDate;
    cout<<defaultDate<<'\n';

    vector<Date>hello(10);
    for (size_t i = 0; i < 10; i++)
    {
        cout<<hello[i]<<'\n';
    }
    
    cout<<today<<'\n';
    today.add_day(1);
    cout<<today<<'\n';
    
}


Date::Date(Day day, Month month, Year year) : d(day), m(month), y(year){}


Date::Date()
    :d(default_date().day()),
    m(default_date().month()),
    y(default_date().year())
{}


void Date::add_day(int n){
    //Date::d += n;
    d.add_day(n);
}

void Day::add_day(int n)
{
    if(d < min|| d > max){
        throw Invalid{};
    }else{
        d += n;
    }
}

void Date::add_month(int n){
    // int size = n+int(m);
    int size = static_cast<int>(m) + n;
    if (size >= static_cast<int>(Month::des))
        m = Month::jan;
    else{
        m = static_cast<Month>(size);
    };
}
void Date::add_year(int n){
    y.add_year(n);
}
void Year::add_year(int n){
    int size = y+n;
    if(size <min || size > max){
        throw Invalid{};
    }else{
        y += n; 
    }
}

Year::Year(int year) : y(year){
    if(year<min||year>=max) 
        throw Invalid{}; 
}

const Date &default_date()
{
    static Date dd(Day(1), Month::jan, Year(2001));
    return dd;
}


ostream& operator<<(ostream& os, const Date& d){
    return os<<'('<<d.day().day()
             <<','<<int(d.month())
             <<','<<d.year().year()<<')';
}