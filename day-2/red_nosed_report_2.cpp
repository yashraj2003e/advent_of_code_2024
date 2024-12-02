#include<iostream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<unordered_set>

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
        std::vector<int> arr;
        while(stream>>s) {
            arr.push_back(stoi(s));
        }

        int j = 0;
        int k = 1;

        int first = -1;
        int second = -1;
        int c = 0;
        while(k<arr.size()) {
            if((arr[k]-arr[j]<=3 && arr[k]-arr[j]>0)) {
                j++;
                k++;
                continue;
            }

            if(first!=-1) {
                c = 2;
                break;
            }
            first = j;
            second = k;

            j+=2;
            k+=2;
        }

        if(first==-1 && c!=2) {
            safe++;
            continue;
        }

        if(c!=2) {
            j = first;
            k = second;
            std::vector<int> a,b;

            for(int l=0;l<arr.size();l++) {
                if(l!=j) {
                    a.push_back(arr[l]);
                }
                if(l!=k) {
                    b.push_back(arr[l]);
                }
            }

            int t = 0;
            for(int i=0;i<a.size()-1;i++) {
                if(a[i+1]-a[i]>3 || a[i+1]-a[i]<=0) {
                    t++;
                    break;
                }
            }

            for(int i=0;i<b.size()-1;i++) {
                if(b[i+1]-b[i]>3 || b[i+1]-b[i]<=0) {
                    t++;
                    break;
                }
            }

            if(t<2) {
                safe++;
                continue;
            }

        }

        j = 0;
        k = 1;
        c = 0;
        first = -1;
        second = -1;
        while(k<arr.size()) {
            if((arr[j]-arr[k]<=3 && arr[j]-arr[k]>0)) {
                j++;
                k++;
                continue;
            }

            if(first!=-1) {
                c = 2;
                break;
            }
            first = j;
            second = k;

            j+=2;
            k+=2;
        }

        if(first==-1 && c!=2) {
            safe++;
            continue;
        }

        if(c!=2) {
            j = first;
            k = second;
            std::vector<int> a,b;

            for(int l=0;l<arr.size();l++) {
                if(l!=j) {
                    a.push_back(arr[l]);
                }
                if(l!=k) {
                    b.push_back(arr[l]);
                }
            }

            int t = 0;
            for(int i=0;i<a.size()-1;i++) {
                if(a[i]-a[i+1]>3 || a[i]-a[i+1]<=0) {
                    t++;
                    break;
                }
            }

            for(int i=0;i<b.size()-1;i++) {
                if(b[i]-b[i+1]>3 || b[i]-b[i+1]<=0) {
                    t++;
                    break;
                }
            }

            if(t<2) {
                safe++;
                continue;
            }

        }
    }

    std::cout<<safe<<std::endl;
}