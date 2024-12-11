#include <bits/stdc++.h>
using namespace std;

typedef __int128 int128_t;

string int128ToString(int128_t num) {
    if (num == 0) return "0";

    bool isNegative = false;
    if (num < 0) {
        isNegative = true;
        num = -num;
    }

    string result;
    while (num > 0) {
        result.push_back((num % 10) + '0');
        num /= 10;
    }

    if (isNegative) {
        result.push_back('-');
    }

    reverse(result.begin(), result.end());
    return result;
}

int128_t stringToInt128(const string &str) {
    int128_t result = 0;
    bool isNegative = false;
    size_t start = 0;

    if (str[0] == '-') {
        isNegative = true;
        start = 1;
    }

    for (size_t i = start; i < str.size(); i++) {
        result = result * 10 + (str[i] - '0');
    }

    return isNegative ? -result : result;
}

class StoneBlinker {
private:
    map<int128_t, int128_t> stones;
    map<int128_t, vector<int128_t>> rules;

    void createBlinkRule(int128_t n) {
        vector<int128_t> rule;
        string ns = int128ToString(n);

        if (n == 0) {
            rule.push_back(1);
        } else if (ns.size() % 2 == 0) {
            size_t half = ns.size() / 2;
            int128_t a = stringToInt128(ns.substr(0, half));
            int128_t b = stringToInt128(ns.substr(half));
            rule.push_back(a);
            rule.push_back(b);
        } else {
            rule.push_back(n * 2024);
        }

        rules[n] = rule;
    }

public:
    StoneBlinker(const vector<string> &input) {
        for (const string &num : input) {
            int128_t n = stringToInt128(num);
            stones[n]++;
        }
    }

    void blink() {
        map<int128_t, int128_t> newStones;
        for (const auto &[key, count] : stones) {
            if (rules.find(key) == rules.end()) {
                createBlinkRule(key);
            }

            for (int128_t numToIncrease : rules[key]) {
                newStones[numToIncrease] += count;
            }
        }
        stones = newStones;
    }

    int128_t blinkSum() const {
        int128_t total = 0;
        for (const auto &[key, count] : stones) {
            total += count;
        }
        return total;
    }

    void simulate(int rounds) {
        for (int i = 1; i <= rounds; ++i) {
            blink();
        }
        cout << int128ToString(blinkSum()) << "\n";
    }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    string inp;
    getline(cin, inp);

    istringstream stream(inp);
    vector<string> arr;
    string num;
    while (stream >> num) {
        arr.push_back(num);
    }

    StoneBlinker blinker(arr);
    blinker.simulate(75);

    return 0;
}