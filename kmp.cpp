#include<bits/stdc++.h>
using namespace std;

class KMP{
    vector<int> getKMP(string &s,int n){
        vector<int> arr(n);
        int i=1,j=0;
        while(i<n){
            while(j!=0 && s[j]!=s[i]){
                j=arr[j-1];
            }
            if(s[j]==s[i]){
                j++;
            }
            arr[i]=j;
            i++;
        }
        return arr;
    }
    public:
    /* if sub is a substring of str the it return the first index 
    in str where it appears else return -1*/
    int kmp(string &str,string &sub){
        int m=str.size();
        int n=sub.size();
        vector<int> arr=getKMP(sub,n);
        int i=0,j=0;
        while(i<m){
            while(j!=0 && str[i]!=sub[j]){
                j=arr[j-1];
            }
            if(str[i]==sub[j]){
                j++;
            }
            if(j==n){
                return i-(n-1);
            }
            i++;
        }
        return -1;
    }
};