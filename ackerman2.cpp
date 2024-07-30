#include <iostream>
#include <stack>
#include <tuple>
//Non-Recursive Implementation

unsigned int ackermann_non_recursive(unsigned int m, unsigned int n) {
    std::stack<std::tuple<unsigned int, unsigned int>> stack;
    stack.push(std::make_tuple(m, n));
    unsigned int result = 0;

    while (!stack.empty()) {
        auto [m, n] = stack.top();
        stack.pop();

        if (m == 0) {
            result = n + 1;
        } else if (n == 0) {
            stack.push(std::make_tuple(m - 1, 1));
        } else {
            stack.push(std::make_tuple(m - 1, 0)); // Placeholder for result
            stack.push(std::make_tuple(m, n - 1));
            continue;
        }
        // the source from chatGPT