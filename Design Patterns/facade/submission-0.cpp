#include <string>

// ============================================
// Order
// ============================================

class Order {
private:
    std::string details;
    bool takeOut;

public:
    Order(const std::string& d, bool t)
        : details(d), takeOut(t) {}

    std::string getDetails() const {
        return details;
    }

    bool isTakeOut() const {
        return takeOut;
    }
};

// ============================================
// Food
// ============================================

class Food {
protected:
    std::string food;

public:
    explicit Food(const std::string& f) : food(f) {}
    virtual ~Food() = default;

    virtual std::string getFood() const {
        return food;
    }
};

// ============================================
// Packaged Food
// ============================================

class PackagedFood : public Food {
public:
    explicit PackagedFood(const std::string& f)
        : Food(f + " in a bag") {}
};

// ============================================
// Cashier
// ============================================

class Cashier {
public:
    Order takeOrder(const std::string& item, bool takeOut) {
        return Order(item, takeOut);
    }
};

// ============================================
// Chef
// ============================================

class Chef {
public:
    Food prepareFood(const Order& order) {
        return Food(order.getDetails());
    }
};

// ============================================
// Kitchen Staff
// ============================================

class KitchenStaff {
public:
    PackagedFood packageFood(const Food& food) {
        return PackagedFood(food.getFood());
    }
};

// ============================================
// Facade
// ============================================

class DriveThruFacade {
private:
    Cashier cashier;
    Chef chef;
    KitchenStaff kitchenStaff;

public:
    Food takeOrder(const std::string& item, bool takeOut) {
        Order order = cashier.takeOrder(item, takeOut);
        Food food = chef.prepareFood(order);

        if (order.isTakeOut()) {
            return kitchenStaff.packageFood(food);
        }

        return food;
    }
};