#include <vector>

// ============================================
// Abstract Prototype
// ============================================

class Shape {
public:
    virtual ~Shape() = default;
    virtual Shape* clone() const = 0;
};

// ============================================
// Concrete Prototype: Square
// ============================================

class Square : public Shape {
private:
    int length;

public:
    explicit Square(int l) : length(l) {}

    int getLength() const {
        return length;
    }

    Shape* clone() const override {
        return new Square(length);
    }
};

// ============================================
// Concrete Prototype: Rectangle
// ============================================

class Rectangle : public Shape {
private:
    int width;
    int height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int getWidth() const {
        return width;
    }

    int getHeight() const {
        return height;
    }

    Shape* clone() const override {
        return new Rectangle(width, height);
    }
};

// ============================================
// Test Class
// ============================================

class Test {
public:
    std::vector<Shape*> cloneShapes(const std::vector<Shape*>& shapes) {
        std::vector<Shape*> clones;
        for (Shape* s : shapes) {
            clones.push_back(s->clone());
        }
        return clones;
    }
};