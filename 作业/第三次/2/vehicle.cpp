#include"vehicle.h"


Vehicle::Vehicle(int num, string engine) : engine_(engine),wheel_(num)
{//这句话不能在这里，因为每次子类构建的时候就会打印
    // cout << "Finish building a vehicle with " \
    // << this->wheel_.get_num() << " wheels and a " << this->engine_.get_name() << " engine." << endl;
}


void Vehicle::describe()
{
    cout << "Finish building a vehicle with " \
    << this->wheel_.get_num() << " wheels and a " << this->engine_.get_name() << " engine." << endl;

    cout << "A vehicle with " << this->wheel_.get_num() \
    << " wheels and a " << this->engine_.get_name() << " engine." << endl;
}
Vehicle::~Vehicle()
{

}