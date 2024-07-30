#include <iostream>
#include <vector>
#include <string>

// Helper function to print the powerset
void printPowerset(const std::vector<std::vector<std::string>>& powerset) {
    std::cout << "{ ";
    for (const auto& subset : powerset) {
        std::cout << "{";
        for (const auto& elem : subset) {
            std::cout << elem << " ";
        }
        std::cout << "} ";
    }
    std::cout << "}" << std::endl;
}

// Recursive function to generate the powerset
void generatePowerset(const std::vector<std::string>& set, std::vector<std::vector<std::string>>& powerset, std::vector<std::string>& current, int index) {
    if (index == set.size()) {
        powerset.push_back(current);
        return;
    }

    // Exclude the current element
    generatePowerset(set, powerset, current, index + 1);

    // Include the current element
    current.push_back(set[index]);
    generatePowerset(set, powerset, current, index + 1);
    current.pop_back();
}

// Function to compute the powerset
std::vector<std::vector<std::string>> powerset(const std::vector<std::string>& set) {
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> current;
    generatePowerset(set, result, current, 0);
    return result;
}

int main() {
    std::vector<std::string> set = {"a", "b", "c"};
    std::vector<std::vector<std::string>> result = powerset(set);
    printPowerset(result);
    return 0;
}