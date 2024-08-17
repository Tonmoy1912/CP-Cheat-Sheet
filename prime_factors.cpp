#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define MAX LONG_LONG_MAX
#define MIN LONG_LONG_MIN
#define endl '\n'

//time complexity: O(sqrt(n))
//argument: number, map to store prime factor with number of occurence
void getPrimeFactors(int x,unordered_map<int,int> &m){
    int i=2;
    while(i*i<=x){
        while(x%i==0){
            m[i]++;
            x/=i;
        }
        i++;
    }
    if(x>1){
        m[x]++;
    }
}

int main(){
    
    return 0;
}