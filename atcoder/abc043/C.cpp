#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i] ;
    }
    int nax = 1e9 ;
    for(int i=-200;i<=200;i++){
        int ans = 0 ;
        for(int j=0;j<n;j++){
            ans += (v[j]-i)*(v[j]-i);
        }
        nax = min(nax,ans);
    }
    cout << nax << endl;
    return 0 ;
}
