#include <iostream>
using namespace std;

main()
{
  string name;
  int marks;
  cout<< "Enter your name: ";
  cin>> name;
  
  if(name == "Ali")
 {
   cout<< "Welcome to Section B" <<endl;
 }

 cout<< "Enter your marks out of 100: ";
 cin>> marks;
 
 if(marks > 50)
 {
  cout<< "PASS"<< endl;
 }

 if(marks == 50)
 {
   cout<< "mehnat karo" << endl;
  }

 if(marks < 50)
 {
  cout<< "FAIL" << endl;
 }
  
} 