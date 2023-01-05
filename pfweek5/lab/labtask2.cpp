#include <iostream>
using namespace std;
string change(char bigsmall);
main()
{

 char bigsmall;
 cout<<"Enter alphabet:";
 cin>> bigsmall;
 string output= change(bigsmall);
 cout<<"alphabet is: "<< output<< endl;

  }

string change(char bigsmall)
{
   if(bigsmall=='a')
   {
     return "lowercase a";
    }
   if(bigsmall=='A')
   {
     return "uppercase A";
    }
}
