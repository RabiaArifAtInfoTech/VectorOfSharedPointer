#include<iostream>
#include<vector>

class Vehicle
{
    int year;
    std::string brand;
    std::string model;
    double mileage;
    double price;

public:
    // Constructors
    Vehicle() { };
    //{
    //   // year = 0, mileage = 0, price = 0;
    //}
    Vehicle(int yearX, std::string brandX, std::string modelX, double mileageX, double priceX)
        : year(yearX), brand(brandX), model(modelX), mileage(mileageX), price(priceX) {}

    // Other member functions
    virtual void display()
    {
        std::cout << year << " " << brand << " " << model << " with " << mileage << " miles, priced at $" << price;
    }

    //pure virtual function

    virtual void start()
    {
        std::cout << "Starting the Vehicle " << this->getModel() << std::endl;
    }


    // Getters
    int getYear() {
        return this->year;
    }
    std::string getBrand() {
        return this->brand;
    }
    std::string getModel() {
        return this->model;
    }
    double getMileage() {
        return this->mileage;
    }
    double getPrice() {
        return this->price;
    }

    // Setters
    void setYear(int yearX) {
        this->year = yearX;
    }
    void setBrand(std::string brandX) {
        this->brand = brandX;
    }
    void setModel(std::string modelX) {
        this->model = modelX;
    }
    void setMileage(double mileageX) {
        this->mileage = mileageX;
    }
    void setPrice(double priceX) {
        this->price = priceX;
    }

};

class Car : public Vehicle {

    int numDoors;
public:
    // Constructors
    Car();
    Car(int yearX, std::string makeX, std::string modelX, double mileageX, double priceX, int numDoorsX);

    // Getter
    int getNumDoors() const;

    // Setter
    void setNumDoors(int numDoors);

    // Overridden member function
    void display()
    {
        Vehicle::display();
        std::cout << " and has " << numDoors << " doors." << std::endl;
    }

    void start() {
        std::cout << "Starting the car " << this->getModel() << std::endl;
    }

};

// Constructors
Car::Car() : Vehicle(), numDoors(0) {}
Car::Car(int year, std::string brand, std::string model, double mileage, double price, int numDoorsX)
    : Vehicle(year, brand, model, mileage, price), numDoors(numDoorsX) {}

// Getter
int Car::getNumDoors() const {
    return numDoors;
}

// Setter
void Car::setNumDoors(int numDoors) {
    numDoors = numDoors;
}

class Plane : public Vehicle {
private:
    int numEngines;
public:
    // Constructors
    Plane();
    Plane(int year, std::string make, std::string model, double mileage, double price, int numEnginesX);

    // Getter
    int getNumEngines() const;

    // Setter
    void setNumEngines(int numEngines);

    // Overridden member function
    void display();

    void start() {
        std::cout << "Starting the plane " << this->getModel() << std::endl;
    }

};

// Constructors
Plane::Plane() : Vehicle(), numEngines(0) {}
Plane::Plane(int year, std::string make, std::string model, double mileage, double price, int numEnginesX)
    : Vehicle(year, make, model, mileage, price), numEngines(numEnginesX) {}

// Getter
int Plane::getNumEngines() const {
    return numEngines;
}

// Setter
void Plane::setNumEngines(int numEngines) {
    numEngines = numEngines;
}

// Overridden member function
void Plane::display() {
    std::cout << getYear() << " " << getBrand() << " " << getModel() << " with " << getMileage() << " miles, priced at $" << getPrice() << " and has " << numEngines << " engines." << std::endl;
}


int main()
{
    Car car1(2022, "Toyota", "Camry", 0, 30000.0, 2);

    Car car2(2019, "Toyota", "Prius", 1000, 20000.0, 4);

    Plane plane1(2002, "Airbus", "Airbus A38", 11000, 22233444.4, 8);

    Plane plane2(2012, "Airbus", "Airbus A32", 450, 333134666.577, 6);

    std::vector<Vehicle> vecVehicle;

    vecVehicle.push_back(car1);
    vecVehicle.push_back(car2);
    vecVehicle.push_back(plane1);
    vecVehicle.push_back(plane2);


    auto itr = vecVehicle.begin();

    std::cout << (*itr).getBrand() << std::endl;;
    (*itr).display();
    std::cout << std::endl;;
    (*itr).start();

    //Car* derived_ptr = dynamic_cast<Car*>(itr);

    // // Error	C2672	'std::dynamic_pointer_cast': no matching overloaded function found
   

    //// SOLUTION ::
    //// Creating a vector of pointers to the base class Vehicle and store pointers to objects of the derived classes in it:

    std::vector<Vehicle*> vecVehicle1;
    vecVehicle1.push_back(&car1);
    vecVehicle1.push_back(&car2);
    vecVehicle1.push_back(&plane1);
    vecVehicle1.push_back(&plane2);

    // Now we can access member functions of derived class using dynamic casting

    Car* carPtr = dynamic_cast<Car*>(vecVehicle1[1]);
    carPtr->display();
    carPtr->start();
    
    Plane* planePtr = dynamic_cast<Plane*>(vecVehicle1[2]);

    planePtr->display();
    planePtr->start();



    std::cout << "\n\n\n";
    return 0;
}
