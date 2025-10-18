#include<iostream>
using namespace std;
class flight{
    int flight_no;
    char destination[20];
    float distance;
    float fuel;
    public:
    int calculate_fuel(float distance){
        if(distance<=1000)
            fuel = 500;
        else if(distance>1000 && distance<=2000)
            fuel = 1100;
        else
            fuel = 2200;
        return fuel;
    }
    void information_entry(){
        cout<<"\n Enter flight number: ";
        cin>>flight_no;
        cout<<"\n Enter destination: ";
        cin>>destination;
        cout<<"\n Enter flight distance: ";
        cin>>distance;
        fuel = calculate_fuel(distance);
    }
    void display_information(){
        cout<<"\n The flight number is: "<<flight_no;
        cout<<"\n The destination is: "<<destination;
        cout<<"\n The distance is: "<<distance;
        cout<<"\n The fuel in the flight is: "<<fuel;
    }
};
int main(){
    flight f1;
    float fuel  = 13.2;
    cout<<"\n Enter flight information: ";
    f1.information_entry();
    cout<<"\n Flight information is as follows: ";
    f1.display_information();
    return 0;
}