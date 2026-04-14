#include <cmath>

// ============================================
// Square (Concrete class – MUST be instantiable)
// ============================================

class Square {
protected:
    double sideLength;

public:
    explicit Square(double side) : sideLength(side) {}

    virtual double getSideLength() const {
        return sideLength;
    }

    virtual ~Square() = default;
};

// ============================================
// SquareHole (Client)
// ============================================

class SquareHole {
private:
    double length;

public:
    explicit SquareHole(double l) : length(l) {}

    bool canFit(const Square& square) const {
        return square.getSideLength() <= length;
    }
};

// ============================================
// Circle (Adaptee)
// ============================================

class Circle {
private:
    double radius;

public:
    explicit Circle(double r) : radius(r) {}

    double getRadius() const {
        return radius;
    }
};

// ============================================
// Adapter
// ============================================

class CircleToSquareAdapter : public Square {
private:
    const Circle& circle;

public:
    explicit CircleToSquareAdapter(const Circle& c)
        : Square(c.getRadius() * 2), circle(c) {}

    double getSideLength() const override {
        return circle.getRadius() * 2;
    }
};