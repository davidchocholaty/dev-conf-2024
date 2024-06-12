#include <iostream>
#include <vector>

void addBeer(std::vector<int>& beers) {
    beers.push_back(10);  // Potential buffer overflow if vector was manually managed!
}

int main() {
    int* beerFridge = new int[5]; // Yeah, new fridge!
    delete[] beerFridge; // Throw away the scrap!
    std::cout << beerFridge[0];  // Use-after-free.

    std::vector<int> beerCollection(5);
    addBeer(beerCollection); // Add 10 more beers.
    
    int* lostBeer = new int(42); // A lovely special beer.
    // Forgot to delete lostBeer, potential memory leak here!
    
    return 0;  // Potential memory leak due to lostBeer!
}

