// Base class representing a dessert.
class Dessert {
public:
    virtual ~Dessert() = default; // Destructor allowing polymorphic behavior and memory management.
    virtual double yumminess() const = 0; // Pure virtual function, making Dessert an abstract base class.
};
