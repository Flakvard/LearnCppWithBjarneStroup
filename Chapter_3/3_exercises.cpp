#include "./std_lib_facilities.h"

int main()
{
    //Exercise 3:This program converts miles to kilometers.
    /* 
    double miles = 0;           //initilize the variable miles to 0
    cout<<"Please write miles you want to convert to km\n";
    cin>>miles;
    cout<<miles<<" is in km = "<<(miles*1.609);
    */

    //Exercise 2: declare a invalid varialbe name = int double = 0;

    //Exercise 3: Enter two numbers and show what is greater, the sum and ratio.
    /*
    double val1 = 0;
    double val2 = 0;
    double ratio = 0;
    cin>>val1>>val2;
    if (val1 > val2)
    {
        cout<<val1<<" is greater than "<<val2;
        cout<<"\nThe sum of both is = "<<(val1+val2);
        ratio = val2/val1;
        cout<<"\nThe ratio between both is = "<<ratio;
    }else{
        cout<<val2<<" is greater than "<<val1;
        cout<<"\nThe sum of both is = "<<(val1+val2);
        ratio = val1/val2;
        cout<<"\nThe ratio between both is = "<<ratio;
    }
    */

   //Excercise 4: Enter three integer or string values, and then output the numerical or alfabetical squence separated by commas.
    
    string num1; //change the variable type to int for the integer version
    string num2; //change the variable type to int for the integer version
    string num3; //change the variable type to int for the integer version

    /*
    Dif. sequence 
    num1,num2,num3
    num1,num3,num2
    num2,num1,num3
    num2,num3,num1
    num3,num2,num1
    num3,num1,num2
    */
    while(cin>>num1>>num2>>num3)
    {
        if (num1>num2&&num1>num3)
        {
            if (num2>num3)
            {
                /* num1,num2,num3 */
                cout<<num3<<", "<<num2<<", "<<num1<<"\n";
            }else
                /* num1,num3,num2 */
                cout<<num2<<", "<<num3<<", "<<num1<<"\n";

        }else if (num2>num1&&num2>num3)
        {
            if (num1>num3)
            {
                /* num2,num1,num3 */
                cout<<num3<<", "<<num1<<", "<<num2<<"\n";
            }else
                /* num2,num3,num1 */
                cout<<num1<<", "<<num3<<", "<<num2<<"\n";

        }else if (num3>num1&&num3>num2)
        {
            if (num2>num1)
            {
                /* num3,num2,num1 */
                cout<<num1<<", "<<num2<<", "<<num3<<"\n";
            }else
                /* num3,num1,num2 */
                cout<<num2<<", "<<num1<<", "<<num3<<"\n";
        }  
    }

    

}