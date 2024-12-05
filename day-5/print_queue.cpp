#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif

    unordered_map<int,set<int>> mymap;
    int total = 0;
    string inp;
    for(int i=0;i<1374;i++) {
        if(i==1176) {
            getline(cin,inp);
            continue;
        }
        getline(cin,inp);
        if(i<1176) {
            mymap[stoi(inp.substr(0,2))].insert(stoi(inp.substr(3,5)));
        } else {
            vector<int> arr;
            for(int j=0;j<inp.size();j+=3) {
                arr.push_back(stoi(inp.substr(j,2)));
            }

            int f = 0;
            for(int i=0;i<arr.size();i++) {
                for(int j=i+1;j<arr.size();j++) {
                    if(mymap.find(arr[i])==mymap.end()) {
                        f = 1;
                        break;
                    }
                    if(mymap[arr[i]].find(arr[j])==mymap[arr[i]].end()) {
                        f = 1;
                        break;
                    }
                }
                if(f) break;
            }

            if(f==1) {
                continue;
            }

            reverse(arr.begin(),arr.end());

            for(int i=0;i<arr.size();i++) {
                for(int j=i+1;j<arr.size();j++) {
                    if(mymap[arr[i]].find(arr[j])!=mymap[arr[i]].end()) {
                        f = 1;
                        break;
                    }
                }
                if(f) break;
            }
            if(f==1) {
                continue;
            }

            if(f==0) {
                int mid = arr.size()/2;
                total+=arr[mid];
            }
        }
    }

    cout<<total;

}