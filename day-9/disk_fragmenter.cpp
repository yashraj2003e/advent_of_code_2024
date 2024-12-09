#include<bits/stdc++.h>
using namespace std;

int main() {
    clock_t z = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif

    vector<string> res;

    string inp;
    getline(cin,inp);
    long long id = 0;

    for(int i=0;i<inp.size();i+=2) {
        for(int j=0;j<(inp[i]-'0');j++) {
            res.push_back(to_string(id));
        }
        for(int j=0;j<(inp[i+1]-'0');j++) {
            res.push_back(string(1,'.'));
        }
        id++;
    }
    for(auto it:res) cout<<it;
    cout<<endl;
    int i = 0;
    int j = res.size()-1;
    while(i<j) {
        while(i<j && res[i]!=".") i++;
        while(j>i && res[j]==".") j--;
        if(i>=j) break;
        swap(res[i],res[j]);
        i++;
        j--;
    }
//    for(auto it:res) cout<<it;
//    cout<<endl;
    long long ans = 0;
    for(int i=0;i<res.size();i++) {
        if(res[i]==".") break;
        ans += (stoll(res[i]) * i);
    }

    cout<<ans;

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
}