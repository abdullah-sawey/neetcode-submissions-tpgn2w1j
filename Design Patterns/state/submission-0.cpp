#include <memory>

// Forward declaration
class Document;

// ============================================
// State Interface
// ============================================

class State {
public:
    virtual ~State() = default;
    virtual void publish(Document& document) = 0;
};

// ============================================
// Context
// ============================================

class Document {
private:
    std::unique_ptr<State> state;
    bool approved = false;

public:
    Document();

    void setState(std::unique_ptr<State> newState) {
        state = std::move(newState);
    }

    void publish() {
        state->publish(*this);
    }

    void setApproval(bool value) {
        approved = value;
    }

    bool isApproved() const {
        return approved;
    }

    State* getState() const {
        return state.get();
    }
};

// ============================================
// Concrete States
// ============================================

class Draft : public State {
public:
    void publish(Document& document) override;
};

class Review : public State {
public:
    void publish(Document& document) override;
};

class Published : public State {
public:
    void publish(Document& document) override {
        // Final state – no transition
    }
};

// ============================================
// State Implementations
// ============================================

void Draft::publish(Document& document) {
    document.setState(std::make_unique<Review>());
}

void Review::publish(Document& document) {
    if (document.isApproved()) {
        document.setState(std::make_unique<Published>());
    } else {
        document.setState(std::make_unique<Draft>());
    }
}

// ============================================
// Document Constructor
// ============================================

Document::Document()
    : state(std::make_unique<Draft>()) {}