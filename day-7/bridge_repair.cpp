#include<bits/stdc++.h>
using namespace std;

/*
 *
 *
 *
 * Does not work in c++, (datatype issues probably)
 * same code works in python !
 *
 *
 */

string to_string(__int128 value) {
    if (value == 0) return "0";
    string result;
    while (value > 0) {
        result.push_back('0' + (value % 10));
        value /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}


bool canMake(__int128 i,__int128& n,vector<__int128>& nums,__int128 cur) {

    if(cur>n || cur<=0) {
        return false;
    }

    if(i>=nums.size() && cur==n) {
        return true;
    }
    return canMake(i+1,n,nums,cur+nums[i]) || canMake(i+1,n,nums,cur*nums[i]);
}


bool check(__int128& n,vector<__int128>& nums) {
    __int128 cur = nums[0];
    return canMake(1,n,nums,cur);
}


signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif

    __int128 answer = 0;
    for(__int128 i=0;i<850;i++) {
        string input;
        getline(cin,input);
        regex rgx(R"(^(\d+):\s*(\d+(?:\s+\d+)*)$)");
        smatch match;
        if (regex_match(input, match, rgx)) {
            __int128 n = stoll(match[1]);
            string others = match[2];
            vector<__int128> nums;
            __int128 cur = 0;
            __int128 total = 0;
            __int128 total1 = 1;
            for (char other : others) {
                if (other == ' ') {
                    if (cur != 0) {
                        total+=cur;
                        total1*=cur;
                        nums.push_back(cur);
                        cur = 0;
                    }
                    continue;
                }
                cur = cur * 10 + (other - '0');
            }

            if (cur != 0) {
                total+=cur;
                total1*=cur;
                nums.push_back(cur);
            }

            for(auto it:nums) {
                if(it==0) {
                    cout<<0<<endl;
                }
            }

            if(total>n || total1<n) {
                continue;
            }

            if(check(n,nums)) answer+=n;
        }
    }

    cout << to_string(answer) << endl;
}
