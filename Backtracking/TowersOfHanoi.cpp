#include <iostream>

void TowersOfHanoi (char a, char b, char c, int n) {

    if (n == 0) return;
    TowersOfHanoi (a, c, b, n - 1);
    std::cout << a << " -> " << c << std::endl;
    TowersOfHanoi (b, a, c, n - 1);
}

int main () {
    int n = 0;
    std::cout << "Define the Height of Tower: ";
    std::cin >> n;  
    std::cout << "Steps for collecting tower on rod 'C': " << std::endl;
    TowersOfHanoi('A', 'B', 'C', n);
}