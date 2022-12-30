#include <iostream>
using namespace std;

main()
{
    int holidays;
    int workdaymin=63;
    int holidaymin=127;
 
  cout<<"Enter number of holidays: ";
  cin>> holidays;
   
   int workingdays=365-holidays;
   int   totalplay=(workingdays*workdaymin)+(holidays*holidaymin);

   cout<< "total play time is " <<totalplay<< " min per year"<< endl;

   int tomnorm=30000 ;
   int diffplay= tomnorm-totalplay;

  if(totalplay> tomnorm)
 {
   int extraplay=totalplay-tomnorm;

  cout<< "Tom will run away!"<< endl;
  cout<<"difference fom norm is "<< extraplay<< " min for play" << endl;
 }
    
  if(totalplay<= tomnorm)
 {
  cout<<"Tom will sleep well!"<< endl;
  cout<<"difference fom norm is "<< diffplay<< " min less for play" << endl;
  }
}

