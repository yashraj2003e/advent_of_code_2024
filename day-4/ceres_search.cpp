#include<bits/stdc++.h>
using namespace std;

int diagonal(vector<vector<char>>& arr,int i,int j,string text) {
    int ans = 0;
    int x = 0;
    int m = i;
    int n = j;
    while(m<arr.size() && n<arr.size() && x<4 && arr[m][n]==text[x]) {
        m++;
        n++;
        x++;
    }
    if(x==4) ans++;
    x = 0;
    m = i;
    n = j;
    while(m<arr.size() && n>-1 && x<4 && arr[m][n]==text[x]) {
        m++;
        n--;
        x++;
    }
    if(x==4) ans++;

    return ans;
}

int down(vector<vector<char>>& arr,int i,int j,string text) {
    int row = i;
    int x = 0;
    while(row<arr.size() && x<4 && arr[row][j]==text[x]) {
        x++;
        row++;
    }
    if(x==4) return 1;
    return 0;
}

bool findWord(vector<vector<char>>& grid, int x, int y, string word, int dx, int dy) {
    int n = grid.size();
    int m = word.size();
    for (int i = 0; i < m; ++i) {
        int nx = x + i * dx;
        int ny = y + i * dy;
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || grid[nx][ny] != word[i]) {
            return false;
        }
    }
    return true;
}

int countWord(vector<vector<char>>& grid, string word) {
    int count = 0;
    vector<pair<int, int>> directions = {
            {0, 1}, {1, 0}, {1, 1}, {1, -1},
            {0, -1}, {-1, 0}, {-1, -1}, {-1, 1}
    };
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[i].size(); ++j) {
            for (auto [dx, dy] : directions) {
                if (findWord(grid, i, j, word, dx, dy)) {
                    ++count;
                }
            }
        }
    }
    return count;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    string total;

    vector<vector<char>> arr(140,vector<char>(140,'.'));

    for(int i=0;i<140;i++) {
        string current;
        cin>>current;
        for(int j=0;j<140;j++) {
            arr[i][j] = current[j];
        }
        total += current;
    }

    int ans = 0;

    for(int i=0;i<140;i++) {
        for(int j=0;j<140;j++) {
            if(arr[i][j]=='X') {
                ans+=diagonal(arr,i,j,"XMAS");
                ans+=down(arr,i,j,"XMAS");
            }
            if(arr[i][j]=='S') {
                ans+=diagonal(arr,i,j,"SAMX");
                ans+=down(arr,i,j,"SAMX");
            }
        }
    }

    for(int i=0;i<140;i++) {
        for(int j=0;j<140;j++) {
            if(j<137) {
                string g = "";
                for(int k=0;k<4;k++) {
                    g+=string(1,arr[i][k+j]);
                }
                if(g=="SAMX" || g=="XMAS") ans++;
            }
        }
    }

    cout<<ans;
}