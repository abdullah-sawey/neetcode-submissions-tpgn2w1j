#include <string>
#include <vector>

// ======================================================
// Observer
// ======================================================

class Customer {
private:
    std::string name;
    int notifications = 0;

public:
    explicit Customer(const std::string& n) : name(n) {}

    void notify(const std::string&) {
        notifications++;
    }

    int countNotifications() const {
        return notifications;
    }
};

// ======================================================
// Subject
// ======================================================

class OnlineStoreItem {
private:
    std::string name;
    int stock;
    std::vector<Customer*> subscribers;

public:
    OnlineStoreItem(const std::string& n, int s)
        : name(n), stock(s) {}

    void subscribe(Customer* customer) {
        subscribers.push_back(customer);
    }

    void unsubscribe(Customer* customer) {
        for (auto it = subscribers.begin(); it != subscribers.end(); ++it) {
            if (*it == customer) {
                subscribers.erase(it);
                break;
            }
        }
    }

    void updateStock(int newStock) {
        bool notify = (stock == 0 && newStock > 0);
        stock = newStock;

        if (notify) {
            for (Customer* c : subscribers) {
                c->notify(name);
            }
        }
    }
};