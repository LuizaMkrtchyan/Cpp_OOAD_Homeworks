#include <iostream>
#include<string>

class Vehicle{
public:
    Vehicle(double weight,double max_speed):weight(weight),max_speed(max_speed){};
    virtual void Describe()const{
        std::cout<<"Weight: "<<this->weight<<" Max Speed: "<<this->max_speed<<std::endl;
    }
protected:
    double weight;
    double max_speed;
};
class Car:public Vehicle{
public:
    Car(double weight,double max_speed,std::string fuel_type):Vehicle(weight,max_speed),fuel_type(fuel_type){}
    void Describe()const override{
        std::cout<<"Weight: "<<weight<<" Max Speed: "<<max_speed<<" Fuel Type: "<<fuel_type<<std::endl;
    }
private:
std::string fuel_type;
};
int main(){
    Vehicle vehicle(1300,230);
    Car car1(1000,300,"Gasoline");
    vehicle.Describe();
    car1.Describe();
    //Vehicle Pointer to Car object
    Vehicle* vehptr=&car1;
    vehptr->Describe();
}