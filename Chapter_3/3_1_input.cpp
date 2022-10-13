#include "./std_lib_facilities.h"

int main()
{
    cout << "Enter the name of the person you want to write to and the age.\n Also write the name of a friend he/she knows.\nPlease choose m = male or f = female for the friend?\n";
    string first_name;                                      // first_name is a variable of type string
    string friends_name;                                    // friends_name is a variable of type string
    int age;                                                // age is a variable of type int
    char friend_sex;                                        // friend_sex is a variable of type char and initilized to be 0 "not assigned"
    while(cin >> first_name >> age >> friends_name >> friend_sex) // read characters into first_name
    {
        cout << "Dear " << first_name << ",\n"
                << "How are you?\nI am fine. I miss you.\n"
                << "Have you seen " << friends_name << " lately?\n";
    
        if (friend_sex == 'm')
        {
            cout << "If you see " << friends_name << " please ask him to call me.\n";
        }
        else if (friend_sex == 'f')
        {
            cout << "If you see " << friends_name << " please ask her to call me.\n";
        }
        else
            cout << "ERROR: You have not assigned a gender for your friend\n";

        if (age < 0 || age > 110)
        {
            simple_error("You're kidding!\n");
        }
        else if (age < 12)
        {
            ++age;
            cout << "Next year you will be " << age << "!\n";
        }
        else if (age == 17)
        {
            cout << "Next year you will be able to vote\n";
        }
        else if (age > 70)
        {
            cout << "I hope you are enjoying retirement.\n";
        }
        cout << "Yours sincerely,\n\nMr. SYG\n";
    }
}