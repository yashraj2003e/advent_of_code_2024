#include<bits/stdc++.h>
using namespace std;

int check(vector<int> arr,unordered_map<int,set<int>>& mymap) {
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

    return f;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif

    unordered_map<int,set<int>> mymap;
    int total = 0;
    string inp;
    for(int i=0;i<1375;i++) {
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

            int f = check(arr,mymap);

            if(!f) continue;

            unordered_map<int,int> mymap1;

            vector<int> extra;

            for(auto it:arr) {
                set<int> k;
                for(auto i:mymap[it]) {
                    k.insert(i);
                }
                int c = 0;
                for(int j=0;j<arr.size();j++) {
                    if(arr[j]!=it && k.find(arr[j])!=k.end()) {
                        mymap1[it]++;
                        c++;
                    }
                }

                if(c==0) {
                    extra.push_back(it);
                }

            }

            vector<pair<int,int>> arr1;

//            for(auto it:extra) cout<<it<<" ";
//            cout<<endl;

            for(auto it:mymap1) {
//                cout<<it.first<<" "<<it.second<<endl;
                arr1.emplace_back(it.first,it.second);
            }

            for(auto it:extra) {
                arr1.emplace_back(it,0);
            }


            sort(arr1.begin(),arr1.end(),[](pair<int,int> a,pair<int,int> b) {
                return a.second > b.second;
            });

            for(int i=0;i<arr.size();i++) {
                arr[i] = arr1[i].first;
            }

            int mid = arr.size()/2;
            total += arr[mid];
        }
    }

    cout<<total;

}