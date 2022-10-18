#include "../std_lib_facilities.h"

int main()
{
  try{
    
    cout<<"1.Success!\n";       //1. Capital C was used for cout
    cout<<"2.Success!\n";       //2. No '"' in the end of this statement
    cout<<"3.Success"<<"!\n";    //3. No '"' and ';' 'in the end of this statement 
    cout<<"4.Success"<<'\n';    //4. Undeclared variable 'success'
    int res = 7;              // string res = 7; invalid converstion              
    vector<int> a(10);
    a[5] = res;
    cout <<"5.Success!\n";      //5. Not a viable conversion from int to string
    vector<int>b(10);
    b[5] = 7;                 //b(5) = 7; - cannot use b(5)
    if(b[5]!=7)               //b(5) same mistake
      cout <<"6.Success!\n";    //6. Use [] instead of ()
    int cond = 1;
    if(cond) cout<<"7.Success!\n";
    else cout<<"Fail!\n";     //7. Undeclared varabile 'cond' and no brackets {} in the
                              //if else statement
    bool c = true;           
    if(c)cout<<"8.Success!\n";
    else cout<<"Fail!\n";     //8. No brackets {} in the if and else statement. Maybe there
                              //there is no need for it in this case? Either way we need to 
                              //change c = false into c = true to cout "Success".
    string s = "ape"; 
    bool o = "fool">s;
    if(o)cout<<"9.Sucsess!\n";  //9. boo is not a type of object, but bool is.
                              //"fool" is a string and < is comparing it with string s.
                              //Which gives us false, because fool is not less than ape.
                              //If we switch it so > then it gives true.
    string t = "ape";
    if(t<="fool")cout<<"10.Success!\n";//10. t = "ape" does not equal "fool", 
                                    //but t is less than or equal to "fool"
    string d = "ape";
    if(d<="fool")cout<<"11.Success!\n";//11. again. t does not equal "fool",
                                    //it is less than and cout uses two '<'
    string y = "ape";
    if(y<"fool") cout<<"12.Success!\n"; //12. You cannot use '+' operator here. Use <.
                                     //And again, cout uses '<<' not '<'
    vector<char>v(5);
    for(int i = 0; i<v.size();++i)
      cout<<i<<"13.Success!\n";          //13. The for loop statement was declared too early and 
                                   //this loop will never end, because 0 will always be 
                                   //less than v.size(). Use i < v.size() and it
                                   //will count 5 times.
    vector<char>k(5);
    for (int i=0;i<v.size();++i)
      cout<<i<<"14.Success!\n";        //14. This one was alittle harder to spot. First the
                                  //statement was declared too early to cout "success".
                                  //Second we use <=v.size(). and it counts 6 times
                                  //v.size() counts 5 and we loop 0 to 5 and not 1 to 5
                                  //For readability it is better to write < than <= 
                                  //Alternat. we could write .size()-1 or int i = 1.
    string h = "15.Success!\n"; 
    for(int i=0;i<10;++i)
      cout<<i<<h[i];             //15. It looks like we are trying to print out values
                              //inside a vector, or print out Success 6 times.
                              //What happens here is that type string is actually
                              //an array of chars. and we are printing 
                              //[0]S[1]u[2]c[3]c[4]e[5]s. which is not an error.
                              //Lets increase it to 10 so we print out all the chars.
    if(true)
      cout<<"16.Success!\n";
    else
      cout<<"Fail!\n";     //16. "if (true) then" isn't a function

    int x = 2000;
    int j = x;
    if(j==2000)
      cout << "17.Success!\n"; //17. Wrong converion. You cannot converse int 2000 ti a char

    string m = "18.Success!\n";
    for(int i = 0; i<9;++i)
      cout<<i<<m[i];        //18. It can be 9 and not 10 loops to print Success!\n 
                            //Although 9 is a magic const

    vector<int> g(5);
    for(int i=0; i<g.size();++i)
      cout<<i<<"19.Success!\n"; //19. The loop statement closes too early to print success.
                             //the vector is not declared correctly 'vector g(5);'
                             //is not correct. it it states the condition <= 
    int i= 0; 
    int z= 0;
    while (i<10)
      ++i;
    if(z<i)
      cout<<"20.success!\n";   //20. this will never be a success because, the while 
                            //loop will run for ever until i is greater than 10.
                            //the increment is done on ++z and should be on ++i.
    double X = 2;
    double D = 5/(x-2);
    if(D==2*X+0.5)
      cout<<"21.Success!\n"; //21. int X = 2; should be changed to a double so there is no
                          //conversion loss. And D states 5/(x-2) = 5/0 and you can never
                          //divide by 0.
    string B = "22.Success!\n"; 
    for(int i=0;i<10;++i)
      cout<<B[i];         //22. (int i=0;i<=10;++i) 10 is a magic const and should be
                          //defind as B.size() instead or B changed to a string and 
                          //then i<10
                          //vector cannot be defined as string<char>B="Success!\n";
                          //or a string type does not use <char> in it aswell?
    int I = 0;
    int J = 0;
    while(I<10)
      ++I;
    if(J<I)
      cout<<"23.success!\n"; //23. Endless while loop because it increments by ++J
                             //and not by ++I and J is not declared variable
    double L =4;
    double U= 5/(L-2);
    if(U==2*L+0.5)
      cout<<"24. success!\n";  //26. the if statement shoud use '==' and not '='
                               //int L should probably be a double so we do not lose
                               //in the conversion
    cout<<"25.Success!\n";     //25. cin<<"Success!\n"; should be cin>>
                               //because it is an input 
                               //and it has to be input into a variable,
                               //so lets change it to cout<<"success!\n"
    return 0;
  }
  catch (exception& e){
    cerr<<"error: "<<e.what()<<'\n';
    keep_window_open();
    return 1;
  }
  catch(...){
    cerr<<"Oops: unknown exception!\n";
    keep_window_open();
    return 2;
  }
}
