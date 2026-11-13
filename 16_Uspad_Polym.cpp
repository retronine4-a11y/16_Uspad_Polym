#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Employer
{
public:
    virtual void Print() = 0;
    virtual ~Employer() {}
};

class President : public Employer
{
private:
    string developmentStrategy;

public:
    President(string developmentStrategy)
    {
        this->developmentStrategy = developmentStrategy;
    }

    void Print() override
    {
        cout << "Position: President" << endl;
        cout << "Development strategy: " << developmentStrategy << endl;
        cout << "Manages the entire company" << endl;
        cout << "Manages the entire company" << endl;
        
    }
};

class Manager : public Employer
{
private:
    int employeeCount;

public:
    Manager(int employeeCount)
    {
        this->employeeCount = employeeCount;
    }

    void Print() override
    {
        cout << "Position: Manager" << endl;
        cout << "Number of subordinates: " << employeeCount << endl;
        cout << "Manages employees and departments" << endl;
    }
};

class Worker : public Employer
{
private:
    int qualificationLevel;

public:
    Worker(int qualificationLevel)
    {
        this->qualificationLevel = qualificationLevel;
    }

    void Print() override
    {
        cout << "Position: Worker" << endl;
        cout << "Qualification level: " << qualificationLevel << endl;
        cout << "Performs work tasks" << endl;
    }
};

//

class Transport
{
protected:
    string name;
    double speed;
    double passengerPrice;
    double cargoPrice;

public:
    Transport(string n, double s, double pp, double cp)
    {
        name = n;
        speed = s;
        passengerPrice = pp;
        cargoPrice = cp;
    }

    virtual void Print(double distance, int passengers, double cargo)
    {
        double time = distance / speed;

        cout << "Transport: " << name << endl;
        cout << "Speed: " << speed << " km/h" << endl;
        cout << "Travel time: " << time << " hours" << endl;
        cout << "Number of passengers: " << passengers << endl;
        cout << "Cargo weight: " << cargo << " kg" << endl;
        cout << "Passenger transportation cost: "
            << passengers * distance * passengerPrice << " UAH" << endl;
        cout << "Cargo transportation cost: "
            << cargo * distance * cargoPrice << " UAH" << endl;
    }

    virtual ~Transport() {}
};

class Car : public Transport
{
public:
    Car() : Transport("Car", 80, 2, 0.5) {}
};

class Bicycle : public Transport
{
public:
    Bicycle() : Transport("Bicycle", 15, 1, 0.2) {}
};

class Cart : public Transport
{
public:
    Cart() : Transport("Cart", 5, 0.5, 0.1) {}
};

int main()
{
    Employer* employees[3];

    President p("Technological development");
    Manager m(25);
    Worker w(4);

    employees[0] = &p;
    employees[1] = &m;
    employees[2] = &w;

    for (int i = 0; i < 3; i++)
    {
        employees[i]->Print();
        cout << "----------------------" << endl;
    }

    cout << "\nPress any key...";
    _getch();
    system("cls");

    //

    double distance;
    int passengers;
    double cargo;
    cout << "Enter distance (km): ";
    cin >> distance;

    cout << "Enter number of passengers: ";
    cin >> passengers;

    cout << "Enter cargo weight (kg): ";
    cin >> cargo;

    cout << "\n";

    Car car;
    Bicycle bicycle;
    Cart cart;

    Transport* transports[3];

    transports[0] = &car;
    transports[1] = &bicycle;
    transports[2] = &cart;

    for (int i = 0; i < 3; i++)
    {
        transports[i]->Print(distance, passengers, cargo);
        cout << "----------------------" << endl;
    }

    cout << "\nPress any key to exit...";
    _getch();
}
