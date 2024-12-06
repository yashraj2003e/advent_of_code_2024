#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif

    vector<vector<char>> arr(130,vector<char>(130,'.'));

    pair<int,int> pos;
    for(int i=0;i<130;i++) {
        for(int j=0;j<130;j++) {
            cin>>arr[i][j];
            if(arr[i][j]=='^') {
                pos = {i,j};
            }
        }
    }

    vector<pair<int,int>> positions;

    int i = pos.first;
    int j = pos.second;
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {-1,0,1,0};
    int ind = 3;
    set<pair<int,int>> s;
    s.insert({i,j});
    while(true) {
        int nrow = i + dx[ind];
        int ncol = j + dy[ind];
        if(nrow<0 || nrow>=arr.size() || ncol<0 || ncol>=arr.size()) {
            break;
        }
        if(arr[nrow][ncol]=='#') {
            if(ind==0) {
                ind = 3;
            }
            else ind--;
        }
        else {
            if(s.find({nrow,ncol})==s.end()) {
                positions.emplace_back(nrow,ncol);
            }
            s.insert({nrow,ncol});
            i = nrow;
            j = ncol;
        }
    }

    sort(positions.begin(),positions.end(),[](pair<int,int>& a,pair<int,int>& b) {
        if(a.first == b.first) return a.second<b.second;
        return a.first < b.first;
    });

    int count = 0;

    for(int k=0;k<positions.size();k++) {
        int a = positions[k].first;
        int b = positions[k].second;
        i = pos.first;
        j = pos.second;
        ind = 3;
        arr[a][b] = '#';
        set<vector<int>> s1;
        while(true) {
            int nrow = i + dx[ind];
            int ncol = j + dy[ind];

            if(s1.find({nrow,ncol,ind})!=s1.end()) {
                count++;
                break;
            }
            s1.insert({nrow,ncol,ind});

            if(nrow<0 || nrow>=arr.size() || ncol<0 || ncol>=arr.size()) {
                break;
            }

            if(arr[nrow][ncol]=='#') {
                if(ind==0) {
                    ind = 3;
                }
                else {
                    ind--;
                }
            }
            else {
                i = nrow;
                j = ncol;
            }
        }
        arr[a][b] = '.';
    }

    cout<<count<<endl;
}