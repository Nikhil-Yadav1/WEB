#include <iostream>
#include <algorithm>
#include <random>

int main() {
    std::vector<int> myArray = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    // Create a random number generator
    std::random_device rd;
    std::mt19937 g(rd());

    // Shuffle the array
    std::shuffle(myArray.begin(), myArray.end(), g);

    // Print the shuffled array
    for (const int& element : myArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}