#include <iostream>
#include <vector>

void printCombination(const std::vector<int>& combination) {
    for (int num : combination) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

bool nextCombination(std::vector<int>& combination, int n) {
    int r = combination.size();
    int i = r - 1;
    while (i >= 0 && combination[i] == n - r + i) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    combination[i]++;
    for (int j = i + 1; j < r; j++) {
        combination[j] = combination[j - 1] + 1;
    }
    return true;
}

int main() {
    int n = 5;
    int r = 3;
    std::vector<int> combination(r);
    for (int i = 0; i < r; i++) {
        combination[i] = i;
    }
    do {
        printCombination(combination);
    } while (nextCombination(combination, n));
    return 0;
}
