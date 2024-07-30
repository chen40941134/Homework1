#include <iostream>
//Recursive Implementation

unsigned int ackermann(unsigned int m, unsigned int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return ackermann(m - 1, 1);
    } else {
        return ackermann(m - 1, ackermann(m, n - 1));
    }
}

int main() {
    std::cout << "Ackermann(2, 3) = " << ackermann(2, 3) << std::endl; // Output: 9
    return 0;
}
//the source from chatGPT