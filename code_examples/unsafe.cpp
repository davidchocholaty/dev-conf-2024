#include <iostream>

int main() {
    int donuts[] = {1, 2, 3, 4, 5}; // Mmm... donuts!
    int* bart = donuts; // Bart's pointer to the donuts.

    std::cout << "Ay caramba!" << std::endl;

    for (int i = 0; i < 5; ++i) { // Bart's prank - doubling the donuts!
        // No bounds checking.
        *(bart + i) = *(bart + i) * 2; // Unsafe pointer arithmetic.
    }

    std::cout << "Uh oh! Bart's modified donuts: ";
    
    for (int i = 0; i < 5; ++i) {
        std::cout << donuts[i] << " ";
    }
    
    std::cout << "Woo-hoo!" << std::endl;

    return 0;
}

