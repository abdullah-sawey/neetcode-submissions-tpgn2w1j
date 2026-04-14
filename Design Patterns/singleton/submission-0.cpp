#include <string>

// ======================================================
// SINGLETON
// ======================================================

class Singleton {
private:
    static Singleton* instance;   // single instance
    std::string value;

    // Private constructor: prevents direct creation
    Singleton() = default;

    // Prevent copy and assignment
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Access point to the single instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    std::string getValue() const {
        return value;
    }

    void setValue(const std::string& v) {
        value = v;
    }
};

// ======================================================
// STATIC MEMBER INITIALIZATION
// ======================================================

Singleton* Singleton::instance = nullptr;