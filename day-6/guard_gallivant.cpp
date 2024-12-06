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

    int i = pos.first;
    int j = pos.second;
    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {-1,0,1,0};
    int ind = 3;
    int count = 0;
    set<pair<int,int>> s;
    s.insert({i,j});
    while(true) {
        int nrow = i + dx[ind];
        int ncol = j + dy[ind];
        if(nrow<0 || nrow>=arr.size() || ncol<0 || ncol>=arr.size()) {
            count++;
            break;
        }
        if(arr[nrow][ncol]=='#') {
            if(ind==0) {
                ind = 3;
            }
            else ind--;
        }
        else {
            if(s.find({nrow,ncol})==s.end()) count++;
            s.insert({nrow,ncol});
            arr[nrow][ncol] = 'X';
            i = nrow;
            j = ncol;
        }
    }

    //answer might be count+1 !
    cout<<count<<endl;
}