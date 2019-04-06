#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<long long> v(n) ;
    for(long long &x : v){
        cin >> x ;
    }
    int nax = 1 ;
    for(int i=n-1;i>=0;i--){
        if ( v[i] != v[0] ){
            nax = max(nax,i);
            break;
        }
    }
    for(int i=0;i<n;i++){
        if ( v[i] != v[n-1] ){
            nax = max(nax,n-i-1);
            break;
        }
    }
    cout << nax << endl;



    return 0 ;
}
