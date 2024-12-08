#include<bits/stdc++.h>
using namespace std;

/*
 *
 *
 * Poorly written !
 *
 *
 *
 */

vector<vector<char>> arr(50,vector<char>(50,'.'));
set<pair<int,int>> pos;
int check(int a,int b) {
    int e = a>=0 && a<50 && b>=0 && b<50;
    if(e) {
        pos.insert({a,b});
    }
    return e;
}

int check1(int a,int b) {
    int e = a>=0 && a<50 && b>=0 && b<50;
    if(e) {
        pos.insert({a,b});
    }
    return e;
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
    for(int i=0;i<50;i++) {
        for(int j=0;j<50;j++) {
            cin>>d;
            if(d!='.') {
                arr[i][j] = d;
                mymap[d].push_back({i,j});
            }
        }
    }

    int total = 0;
    set<pair<int,int>> pos;
    for(auto it:mymap) {
        vector<vector<int>> v = it.second;
        for(int i=0;i<v.size();i++) {
            pos.insert({v[i][0],v[i][1]});
            for(int j=i+1;j<v.size();j++) {
                int nrow = abs(v[i][0]-v[j][0]);
                int ncol = abs(v[i][1]-v[j][1]);
                if(v[i][0]<v[j][0] && v[i][1]<v[j][1]) {
                    if(check(v[i][0]-nrow,v[i][1]-ncol)) {
                        int nr = v[i][0]-nrow;
                        int nc = v[i][1]-ncol;
                        while(nr>=0 && nc>=0) {
                            pos.insert({nr,nc});
                            nr = nr-nrow;
                            nc = nc-ncol;
                        }
                    }
                    if(check1(v[j][0]+nrow,v[j][1]+ncol)) {
                        int nr = v[j][0]+nrow;
                        int nc = v[j][1]+ncol;
                        while(nr<50 && nc<50) {
                            pos.insert({nr,nc});
                            nr = nr+nrow;
                            nc = nc+ncol;
                        }
                    }
                }
                else if(v[i][0]>v[j][0] && v[i][1]<v[j][1]) {
                    if(check(v[i][0]+nrow,v[i][1]-ncol)){
                        int nr = v[i][0]+nrow;
                        int nc = v[i][1]-ncol;
                        while(nr<50 && nc>-1) {
                            pos.insert({nr,nc});
                            nr = nr+nrow;
                            nc = nc-ncol;
                        }
                    }
                    if(check1(v[j][0]-nrow,v[j][1]+ncol)) {
                        int nr = v[j][0]-nrow;
                        int nc = v[j][1]+ncol;
                        while(nr>-1 && nc<50) {
                            pos.insert({nr,nc});
                            nr = nr-nrow;
                            nc = nc+ncol;
                        }
                    }
                }
                else if(v[i][0]<v[j][0] && v[i][1]>v[j][1]) {
                    if(check(v[i][0]-nrow,v[i][1]+ncol)) {
                        int nr = v[i][0]-nrow;
                        int nc = v[i][1]+ncol;
                        while(nr>-1 && nc<50) {
                            pos.insert({nr,nc});
                            nr = nr-nrow;
                            nc = nc+ncol;
                        }
                    }
                    if(check1(v[j][0]+nrow,v[j][1]-ncol)) {
                        int nr = v[j][0]+nrow;
                        int nc = v[j][1]-ncol;
                        while(nr<50 && nc>-1) {
                            pos.insert({nr,nc});
                            nr = nr+nrow;
                            nc = nc-ncol;
                        }
                    }
                }
                else if(v[i][0]==v[j][0]) {
                    int t = v[i][1];
                    int t1 = v[j][1];
                    if(t>t1) {
                        swap(t,t1);
                    }
                    if(check(v[i][0]-nrow,t-ncol)) {
                        int nr = v[i][0]-nrow;
                        int nc = t-ncol;
                        while(nr>-1 && nc>-1) {
                            pos.insert({nr,nc});
                            nr = nr-nrow;
                            nc = nc-ncol;
                        }
                    }
                    if(check1(v[j][0]+nrow,t1+ncol)) {
                        int nr = v[j][0]+nrow;
                        int nc = t1+ncol;
                        while(nr<50 && nc<50) {
                            pos.insert({nr,nc});
                            nr = nr+nrow;
                            nc = nc+ncol;
                        }
                    }
                }
                else if(v[i][1]==v[j][1]){
                    int t = v[i][1];
                    int t1 = v[j][1];
                    if(t>t1) {
                        swap(t,t1);
                    }
                    if(check(t-nrow,v[i][1]-ncol)) {
                        int nr = t-nrow;
                        int nc = v[i][1]-ncol;
                        while(nr>-1 && nc>-1) {
                            pos.insert({nr,nc});
                            nr = nr-nrow;
                            nc = nc-ncol;
                        }
                    }
                    if(check1(t1+nrow,v[j][1]+ncol)) {
                        int nr = t1+nrow;
                        int nc = v[j][1]+ncol;
                        while(nr<50 && nc<50) {
                            pos.insert({nr,nc});
                            nr = nr+nrow;
                            nc = nc+ncol;
                        }
                    }
                }
            }
        }
    }

    cout<<pos.size();
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);
}