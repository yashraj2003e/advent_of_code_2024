#include<bits/stdc++.h>
using namespace std;

vector<long long int> nums;
long long int n;

bool canMake(long long int i, long long int cur) {
    if (cur > n || cur <= 0) {
        return false;
    }

    if (i >= nums.size() && cur == n) {
        return true;
    }

    if (i >= nums.size()) {
        return false;
    }

    return canMake(i + 1, cur + nums[i]) || canMake(i + 1, cur * nums[i]);
}

bool check() {
    long long int cur = nums[0];
    return canMake(1, cur);
}

signed main() {
    clock_t z = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif

    long long int answer = 0;
    string input;
    regex rgx(R"(^(\d+):\s*(\d+(?:\s+\d+)*)$)");
    smatch match;
    for (long long int i = 0; i < 850; i++) {
        nums.clear();
        getline(cin, input);
        if (regex_match(input, match, rgx)) {
            n = stoll(match[1]);
            string others = match[2];
            long long int cur = 0;
            long long int total = 0;
            for (char other : others) {
                if (other == ' ') {
                    nums.push_back(cur);
                    total+=cur;
                    cur = 0;
                    continue;
                }
                cur = cur * 10 + (other - '0');
            }

            if (cur != 0) {
                total+=cur;
                nums.push_back(cur);
            }
            if(total>n) continue;
            if (check()) answer += n;
        }
    }

    cout << to_string(answer) << endl;
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
}