#include<bits/stdc++.h>
using namespace std;

int n = 52;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif

    vector<vector<char>> arr(n,vector<char>(n,'.'));

    vector<pair<int,int>> pos;

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cin>>arr[i][j];
            if(arr[i][j]=='0') {
                pos.push_back({i,j});
            }
        }
    }

    int score = 0;

    vector<int> dx = {0,1,0,-1};
    vector<int> dy = {-1,0,1,0};
    for(int i=0;i<pos.size();i++) {

            int row = pos[i].first;
            int col = pos[i].second;

            queue<pair<int,int>> q;
            q.push({row,col});
            vector<vector<int>> vis(n,vector<int>(n,0));
            vis[row][col] = 1;
            while(!q.empty()) {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                if(arr[r][c] == '9') {
                    score++;
                    continue;
                }

                for(int i=0;i<4;i++){
                    int nrow = r + dx[i];
                    int ncol = c + dy[i];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && arr[nrow][ncol]==arr[r][c]+1 && !vis[nrow][ncol]) {
                        q.push({nrow,ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
    }



    cout<<score;

}