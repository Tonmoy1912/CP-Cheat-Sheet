#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define endl '\n'

vector<int> getPrimes(ll n){
    vector<int> sieve(n+1);
    int l=sqrt(n);
    for(ll i=2;i<=l;i++){
        if(sieve[i]==0){
            for(ll j=i*i;j<=n;j+=i){
                sieve[j]=1;
            }
        }
    }
    vector<int> ans;
    for(int i=2;i<=n;i++){
        if(sieve[i]==0){
            ans.push_back(i);
        }
    }
    return ans;
}

int main(){
    
    vector<int> arr=getPrimes(100);
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;
    
    return 0;
}