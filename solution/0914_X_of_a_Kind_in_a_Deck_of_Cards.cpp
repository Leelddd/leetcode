#include "alg.h"

unsigned gcd(unsigned u, unsigned v) {
    while (v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}

bool hasGroupsSizeX(vector<int> deck) {
    int a[10000] = {0};
    for (int i = 0; i < deck.size(); ++i) a[deck[i]]++;
    vector<int> numbers;
    for (int j = 0; j < 10000; ++j) {
        if (a[j] != 0) numbers.push_back(a[j]);
    }
    sort(numbers.begin(), numbers.end());
    unique(numbers.begin(), numbers.end());
    for (int k = 1; k < numbers.size(); ++k) {
        if (gcd(numbers[k], numbers[0]) == 1)return false;
    }
    return deck.size() > 1;
}

int main() {
    cout << hasGroupsSizeX({1, 2, 3, 4, 4, 3, 2, 1});
    cout << hasGroupsSizeX({1, 1, 1, 2, 2, 2, 3, 3});
    cout << hasGroupsSizeX({1});
    cout << hasGroupsSizeX({1, 1});
    cout << hasGroupsSizeX({1, 1, 2, 2, 2, 2});
    cout << hasGroupsSizeX({0, 0, 0, 1, 1, 1, 2, 2, 2});

}