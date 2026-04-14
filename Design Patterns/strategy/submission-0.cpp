#include <vector>
#include <string>

// ============================================
// Person
// ============================================

class Person {
private:
    std::string lastName;
    int age;
    bool married;

public:
    Person(const std::string& ln, int a, bool m)
        : lastName(ln), age(a), married(m) {}

    int getAge() const {
        return age;
    }

    bool isMarried() const {
        return married;
    }
};

// ============================================
// Strategy Interface
// ============================================

class PersonFilter {
public:
    virtual bool apply(const Person& person) const = 0;
    virtual ~PersonFilter() = default;
};

// ============================================
// Concrete Strategies
// ============================================

class AdultFilter : public PersonFilter {
public:
    bool apply(const Person& person) const override {
        return person.getAge() >= 18;
    }
};

class SeniorFilter : public PersonFilter {
public:
    bool apply(const Person& person) const override {
        return person.getAge() >= 65;
    }
};

class MarriedFilter : public PersonFilter {
public:
    bool apply(const Person& person) const override {
        return person.isMarried();
    }
};

// ============================================
// Context
// ============================================

class PeopleCounter {
private:
    PersonFilter* filter = nullptr;

public:
    void setFilter(PersonFilter& f) {
        filter = &f;
    }

    int count(const std::vector<Person>& people) const {
        int result = 0;
        if (!filter) return result;

        for (const Person& p : people) {
            if (filter->apply(p)) {
                result++;
            }
        }
        return result;
    }
};