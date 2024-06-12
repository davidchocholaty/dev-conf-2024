#include <iostream>
#include <memory>
#include <vector>

// Base class representing a dessert.
class Dessert {
public:
    // Destructor allowing polymorphic behavior and memory management.
    virtual ~Dessert() = default;
    // Pure virtual function, making Dessert an abstract base class.
    virtual double yumminess() const = 0;
};

// Derived class representing a cake.
class Cake : public Dessert {
public:
    // Constructor initializing sweetness.
    Cake(double sweetness) : sweetness(sweetness) {}
    double yumminess() const override {
        return sweetness * 1.5; // Yumminess factor for cakes.
    }
    void candleCount() const { // Only for cakes.
        std::cout << "Number of candles: " << static_cast<int>(sweetness) << std::endl;
    }
private:
    double sweetness; // Member variable storing sweetness.
};

// Derived class representing a cookie.
class Cookie : public Dessert {
public:
    // Constructor initializing crunchiness and choco_chips.
    Cookie(double crunchiness, double choco_chips) : crunchiness(crunchiness), choco_chips(choco_chips) {}
    double yumminess() const override {
        return crunchiness * 2.0 + choco_chips * 3.0; // Yumminess factor for cookies.
    }
private:
    double crunchiness, choco_chips; // Member variables storing crunchiness and choco_chips.
};

void print_yumminess(const Dessert& dessert) {
    std::cout << "Yumminess: " << dessert.yumminess() << std::endl;
}

int main() {
    // The use of unique pointers (std::unique_ptr).
    std::vector<std::unique_ptr<Dessert>> desserts;
    // Sweet cake! Creating a Cake object and storing its unique pointer in the vector.
    desserts.push_back(std::make_unique<Cake>(5.0));
    // Crunchy cookie with lots of choco chips! Creating a Cookie object and storing 
    // its unique pointer in the vector.
    desserts.push_back(std::make_unique<Cookie>(4.0, 6.0));

    for (const auto& dessert : desserts) {
        print_yumminess(*dessert);
    }

    // Accessing memory after deallocation
    Cake* danglingPointer = dynamic_cast<Cake*>(desserts[0].get());
    desserts.clear(); // Deallocate memory

    // Attempt to access memory through the dangling pointer
    danglingPointer->candleCount(); // Accessing memory after deallocation

    return 0;
}
