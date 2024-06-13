int main() {
    // The use of unique pointers (std::unique_ptr).
    std::vector<std::unique_ptr<Dessert>> desserts;
    desserts.push_back(std::make_unique<Cake>(5.0));  // Sweet cake!
    desserts.push_back(std::make_unique<Cookie>(4.0, 6.0));  // Crunchy cookie with lots of choco chips!

    // ...

    // Accessing memory after deallocation.
    Cake* danglingPointer = dynamic_cast<Cake*>(desserts[0].get());
    desserts.clear(); // Deallocate memory.

    // Attempt to access memory through the dangling pointer.
    danglingPointer->candleCount(); // Implemented only for cakes.

    return 0;
}