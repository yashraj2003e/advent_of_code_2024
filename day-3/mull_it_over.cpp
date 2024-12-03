#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif

    long long ans = 0;

    string s;
    getline(cin,s);
    regex pattern(R"(mul\(\d+,\d+\))");

    auto words_begin = sregex_iterator(s.begin(),s.end(),pattern);
    auto words_end = sregex_iterator();

    for(sregex_iterator it=words_begin;it!=words_end;it++) {
        string f = it->str();
        long long x = 0,y = 0;
        int i = 0;
        while(i<f.size()) {
            if(f[i]=='(') {
                i++;
                while(f[i]!=',') {
                    x = x*10 + (f[i]-'0');
                    i++;
                }
                i++;
                while(f[i]!=')') {
                    y = y*10 + (f[i]-'0');
                    i++;
                }
                break;
            }
            i++;
        }
        ans += x*y;
    }

    cout<<ans<<endl;


}