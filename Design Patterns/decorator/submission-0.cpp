#include <string>

// ======================================================
// Component
// ======================================================

class Coffee {
public:
    virtual double getCost() const = 0;
    virtual ~Coffee() = default;
};

// ======================================================
// Concrete Component
// ======================================================

class SimpleCoffee : public Coffee {
public:
    double getCost() const override {
        return 1.1;
    }
};

// ======================================================
// Decorator Base Class
// ======================================================

class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;

public:
    explicit CoffeeDecorator(Coffee* c) : coffee(c) {}

    ~CoffeeDecorator() override {
        delete coffee;
    }
};

// ======================================================
// Concrete Decorators
// ======================================================

class MilkDecorator : public CoffeeDecorator {
public:
    explicit MilkDecorator(Coffee* c) : CoffeeDecorator(c) {}

    double getCost() const override {
        return coffee->getCost() + 0.5;
    }
};

class SugarDecorator : public CoffeeDecorator {
public:
    explicit SugarDecorator(Coffee* c) : CoffeeDecorator(c) {}

    double getCost() const override {
        return coffee->getCost() + 0.2;
    }
};

class CreamDecorator : public CoffeeDecorator {
public:
    explicit CreamDecorator(Coffee* c) : CoffeeDecorator(c) {}

    double getCost() const override {
        return coffee->getCost() + 0.7;
    }
};