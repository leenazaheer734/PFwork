#include <iostream>
using namespace std;
main()
{
    string movies[5] ={"Gladiator", "StarWars", "Terminator", "Takinglives", "TombRider"};
    string watching;
    int price, quantity;

    cout<<"Enter movie name: ";
    cin>> watching;
    cout<<"HOw maony tickets you want to buy: ";
    cin>> quantity;

    for(int index=0; index < 4; index++)
    {
        if(movies[index] == watching)
        {
            if(index%2 == 0)
            {
                price = 450 * quantity;
            }
            else{
                price = 475 * quantity;
            }
        }
    }
    cout<<"price after discount: "<< price;

}