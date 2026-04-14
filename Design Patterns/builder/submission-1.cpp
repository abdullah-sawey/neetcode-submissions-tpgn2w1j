#include <string>

class Meal {
private:
    double cost = 0.0;
    bool takeOut = false;
    std::string mainCourse;
    std::string drink;

public:
    double getCost() const {
        return cost;
    }

    bool getTakeOut() const {
        return takeOut;
    }

    std::string getMain() const {
        return mainCourse;
    }

    std::string getDrink() const {
        return drink;
    }

    void setCost(double c) {
        cost = c;
    }

    void setTakeOut(bool t) {
        takeOut = t;
    }

    void setMain(const std::string& m) {
        mainCourse = m;
    }

    void setDrink(const std::string& d) {
        drink = d;
    }
};

class MealBuilder {
private:
    Meal meal;

public:
    MealBuilder& addCost(double c) {
        meal.setCost(c);
        return *this;
    }

    MealBuilder& addTakeOut(bool t) {
        meal.setTakeOut(t);
        return *this;
    }

    MealBuilder& addMainCourse(const std::string& m) {
        meal.setMain(m);
        return *this;
    }

    MealBuilder& addDrink(const std::string& d) {
        meal.setDrink(d);
        return *this;
    }

    Meal build() {
        return meal;
    }
};