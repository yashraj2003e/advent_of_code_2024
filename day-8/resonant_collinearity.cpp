#include<bits/stdc++.h>
using namespace std;
vector<vector<char>> arr(10,vector<char>(10,'.'));
int check(int a,int b,int c,int d) {
    int e = a>=0 && a<10 && b>=0 && b<10;
    int f = c>=0 && c<10 && d>=0 && d<10;
    if(e && arr[a][b]=='#') e--;
    if(f && arr[c][d]=='#') f--;

    if(e) arr[a][b] = '#';
    if(f) arr[c][d] = '#';
    return e+f;
}

int main() {
    clock_t z = clock();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
#endif
    unordered_map<char,vector<vector<int>>> mymap;
    char d;
    for(int i=0;i<10;i++) {
        for(int j=0;j<10;j++) {
          cin>>d;
          if(d!='.') {
              arr[i][j] = d;
              mymap[d].push_back({i,j});
          }
        }
    }

    int total = 0;
    for(auto it:mymap) {
        vector<vector<int>> v = it.second;
        for(int i=0;i<v.size();i++) {
            for(int j=i+1;j<v.size();j++) {
                int nrow = abs(v[i][0]-v[j][0]);
                int ncol = abs(v[i][1]-v[j][1]);
                if(v[i][0]<v[j][0] && v[i][1]<v[j][1]) {
                    total += check(v[i][0]-nrow,v[i][1]-ncol,v[j][0]+nrow,v[j][1]+ncol);
                }
                else if(v[i][0]>v[j][0] && v[i][1]<v[j][1]) {
                    total += check(v[i][0]+nrow,v[i][1]-ncol,v[j][0]-nrow,v[j][1]+ncol);
                }
                else if(v[i][0]<v[j][0] && v[i][1]>v[j][1]) {
                    total += check(v[i][0]-nrow,v[i][1]+ncol,v[j][0]+nrow,v[j][1]-ncol);
                }
                else if(v[i][0]==v[j][0]) {
                    int t = v[i][1];
                    int t1 = v[j][1];
                    if(t>t1) {
                        swap(t,t1);
                    }
                    total += check(v[i][0]-nrow,t-ncol,v[j][0]+nrow,t1+ncol);
                }
                else if(v[i][1]==v[j][1]){
                    int t = v[i][1];
                    int t1 = v[j][1];
                    if(t>t1) {
                        swap(t,t1);
                    }
                    total += check(t-nrow,v[i][1]-ncol,t1+nrow,v[j][1]+ncol);
                }
            }
        }
    }
    for(auto it:arr) {
        for(auto i:it) cout<<i;
        cout<<endl;
    }
    cout<<total;
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
}