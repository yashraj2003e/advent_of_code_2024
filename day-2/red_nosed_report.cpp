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

    int safe = 0;

    for(int i=0;i<1000;i++) {
        std::string s;
        std::getline(std::cin,s);
        std::istringstream stream(s);
        std::vector<std::string> arr;
        while(stream>>s) {
            arr.push_back(s);
        }


        int inc = 0,dec = 0;
        for(int i=0;i<arr.size()-1;i++) {
            if(stoi(arr[i])<stoi(arr[i+1])) inc++;
            if(stoi(arr[i])>stoi(arr[i+1])) dec++;
        }
        if(inc!=arr.size()-1 && dec!=arr.size()-1) continue;
        int f = 0;
        for(int i=0;i<arr.size()-1;i++) {
            if(abs(stoi(arr[i])-stoi(arr[i+1]))>3) {
                f = 1;
                break;
            }
        }
        if(f==0) {
            safe++;
        }
    }

    std::cout<<safe<<std::endl;


}