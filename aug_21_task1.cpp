#include <iostream>
#include <string>
class Car{
public:
    Car(std::string model,int year){
        this->model=model;
        this->year=year;
    }
    std::string DescribeCar(){
        return "Car Model: " + this->model + ", Year: " + std::to_string(this->year);
    }
private: 
    std::string model;
    int year;
};
class Person{
public:
    Person(std::string name,int age):name(name),age(age),car(nullptr){};
    ~Person(){
        delete car;
    }
    void assignCar(Car& car){
        this->car=new Car(car);
    }
    void DescribePerson(){
        if(car){
            std::cout<<"\nMy name is "<<this->name<<" and i am "<<this->age<<" years old .I have a car.(" << car->DescribeCar()<<")"<<std::endl;
        }
        else{
            std::cout<<"\nMy name is "<<this->name<<" and i am "<<this->age<<" years old."<<std::endl;
        }
    }
private:
    std::string name;
    int age;
    Car *car;
};

int main(){
    Car car1("BMW",2019);
    Person p1("Alice",23);
    p1.assignCar(car1);
    p1.DescribePerson();
}
