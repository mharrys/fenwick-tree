#include "fenwick_tree.hpp"

#include <iostream>
#include <sstream>

// Implementation to handle test cases from Kattis on stdin.
int main()
{
    // I/O performance adjustment
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, q; // length of array, number of operations
    std::cin >> n >> q;

    fenwick_tree<long> ft(n);

    char op;
    long a, b;
    std::stringstream output;
    for (auto i = 0; i < q; i++) {
        std::cin >> op;

        if (op == '?') {
            std::cin >> a;
            output << ft.sum(a) << "\n";
        } else /* op == '+' */ {
            std::cin >> a >> b;
            ft.add(a, b);
        }
    }

    std::cout << output.str();

    return 0;
}
