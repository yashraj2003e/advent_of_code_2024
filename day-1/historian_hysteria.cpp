#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    int n;
    std::string inp;
    std::vector<int> a;
    std::vector<int> b;

    int i = 0;
    while(std::getline(std::cin,inp)) {
        std::istringstream stream(inp);
        std::string word;
        while(stream>>word) {
            if(i%2==0) a.push_back(stoi(word));
            else b.push_back(stoi(word));
            i++;
        }
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    long long count = 0;

    for(int i=0;i<a.size();i++) {
        count += abs(a[i]-b[i]);
    }

    std::cout<<count;

}