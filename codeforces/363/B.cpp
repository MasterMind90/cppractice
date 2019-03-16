#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k ; 
    cin >> n >> k ; 
    vector<int> v(n) ; 
    for(int &x : v){
        cin >> x ;
    }
    vector<int> sum(n+1,0) ; 
    for(int i=1;i<=n;i++){
        sum[i] += sum[i-1] ; 
        sum[i] += v[i-1] ; 
    }
    int index = 0 ; 
    long long nax = 1e18  ;
    for(int i=1;i+k<=n+1;i++){
        if ( sum[i+k-1] - sum[i-1] < nax ){
            nax = sum[i+k-1] - sum[i-1] ; 
            index = i ; 
        }
    }
    cout << index << endl;
    return 0 ; 
}
