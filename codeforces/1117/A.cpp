#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n ; 
    cin >> n ;
    vector<long long> v(n);
    long long MAX = 0 ;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if ( v[i] > MAX ) MAX = v[i] ;
    }
    int maxLen = 0 ;
    int cnt = 0 ;
    for(int i=0;i<n;i++){
        if ( v[i] != MAX ) cnt = 0 ;
        if ( v[i] == MAX ){
            cnt++;
            maxLen = max(maxLen,cnt);
        }
    }
    cout << maxLen << endl;
    return 0 ; 
}

