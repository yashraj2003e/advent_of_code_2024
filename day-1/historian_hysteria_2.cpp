#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<unordered_map>

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    int n;
    std::string inp;
    std::vector<int> a;
    std::unordered_map<int,int> mymap;

    int i = 0;
    while(std::getline(std::cin,inp)) {
        std::istringstream stream(inp);
        std::string word;
        while(stream>>word) {
            if(i%2==0) a.push_back(stoi(word));
            else mymap[stoi(word)]++;
            i++;
        }
    }

    sort(a.begin(),a.end());
    long long count = 0;

    for(auto it:a) {
        count += (it*mymap[it]);
    }

    std::cout<<count;

}