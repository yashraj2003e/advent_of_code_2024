#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif

    string inp;
    getline(cin,inp);

    istringstream stream(inp);
    vector<string> arr;
    while(stream>>inp) {
        arr.push_back(inp);
    }

    for(int i=0;i<25;i++) {
        vector<string> temp;
        for(int j=0;j<arr.size();j++) {
            if(arr[j]=="0") {
                temp.push_back("1");
            }
            else if(arr[j].size()%2 == 0) {
                string left = arr[j].substr(0,arr[j].size()/2);
                string right = arr[j].substr(arr[j].size()/2,arr[j].size());
                temp.push_back(left);
                int zero = 0;
                for(auto it:right) {
                    if(it=='0') zero++;
                    else break;
                }
                if(zero==right.size()) {
                    temp.push_back("0");
                }
                else {
                    temp.push_back(right.substr(zero,right.size()));
                }
            }
            else {
                long long num = stoll(arr[j]);
                num*=2024;
                temp.push_back(to_string(num));
            }
        }
        arr = temp;
    }

    cout<<arr.size();
}