#include <iostream>
using namespace std;
void calculatepercentage(int number);
main()
{
    int number;
    cout<<"Enter number: ";
    cin>> number;
    calculatepercentage(number);

}
void calculatepercentage(int number)
{
    int check, minibus=0, truck=0, train=0;
    for(int x=1; x<= number; x++)
    {
        cin>> check;
        if(check <= 3 )
        {
            minibus = minibus+ check;
        }
        if(check >3 && check<= 11)
        {
            truck = truck + check;
        }
        if(check>11)
        {
            train = train + check;
        }
        
    }
    int total = minibus+truck+train;
    float bymini = (minibus*100.0)/total;
    float bytruck = (truck* 100.0)/total;
    float bytrain = (train* 100.0)/total;
    float avgprice = (minibus* 200.0 +truck*175.0+ train*120.0)/ total;
    cout<<"byminibus: "<<bymini<<endl;
    cout<<"by truck: "<<bytruck<< endl;
    cout<<"byt train: "<<bytrain<<endl;
    cout<<"average price: "<<avgprice<< endl;
}