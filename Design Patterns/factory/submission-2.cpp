#include <iostream>
#include <string>

// ======================================================
// 1. ABSTRACT PRODUCT
// ======================================================

class Vehicle {
public:
    virtual std::string getType() = 0;
    virtual ~Vehicle() {}
};

// ======================================================
// 2. CONCRETE PRODUCTS
// ======================================================

class Car : public Vehicle {
public:
    std::string getType() override {
        return "Car";
    }
};

class Truck : public Vehicle {
public:
    std::string getType() override {
        return "Truck";
    }
};

class Bike : public Vehicle {
public:
    std::string getType() override {
        return "Bike";
    }
};

// ======================================================
// 3. ABSTRACT CREATOR
// ======================================================

class VehicleFactory {
public:
    virtual Vehicle* createVehicle() = 0;  // Factory Method
    virtual ~VehicleFactory() {}
};

// ======================================================
// 4. CONCRETE CREATORS
// ======================================================

class CarFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Car();
    }
};

class TruckFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Truck();
    }
};

class BikeFactory : public VehicleFactory {
public:
    Vehicle* createVehicle() override {
        return new Bike();
    }
};