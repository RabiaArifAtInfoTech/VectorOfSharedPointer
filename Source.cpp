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
       std::cout<< " and has " << numDoors << " doors." << std::endl;
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
    void display() ;


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
void Plane::display()  {
    std::cout << getYear() << " " << getBrand() << " " << getModel() << " with " << getMileage() << " miles, priced at $" << getPrice() << " and has " << numEngines << " engines." << std::endl;
}
int main()
{
    std::shared_ptr<Car> carPtr = std::make_shared<Car>(2021, "Toyota", "Corolla", 0, 25000.0, 4);
    std::shared_ptr<Plane> planePtr = std::make_shared<Plane>(2021, "Boeing", "747", 0, 300000000.0, 4);


	carPtr->display();

    planePtr->display();

    std::vector<std::shared_ptr< Vehicle >> vecVehicle;

    vecVehicle.push_back(carPtr);
    vecVehicle.push_back(planePtr);

    auto it = vecVehicle.begin();

    for (auto it = vecVehicle.begin(); it != vecVehicle.end(); ++it)
        std::cout << *it << " ";


	std::cout << "\n\n\n";
	return 0;
}
