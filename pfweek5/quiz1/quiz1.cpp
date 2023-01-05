#include<iostream>
#include<cmath>
using namespace std;

main()
{
  int number;
 cout<<"Enter a number: ";
 cin>> number;
  int rem1=number%10;
 int num1=number/10;
 int rem2=num1%10;
 int num2=num1/10;

 int cuuub=pow(rem1,3);

 int cuuuuub=pow(num2,3);

 int cuuuub=pow(rem2,3);


 int sum=cuuub+cuuuub+cuuuuub;
 cout<<sum<<endl;

  if(sum==number)
{
  cout<<"is armstrong";
}
  if(sum!=number)
{
  cout<<"is not armstrong";
}
 
}


 
 