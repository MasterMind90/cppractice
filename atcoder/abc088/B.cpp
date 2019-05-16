#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int &x : v){
        cin >> x ;
    }
    sort(v.rbegin(),v.rend());
    int alice = 0 ;
    int bob = 0 ;
    for(int i=0;i<n;i++){
        if ( i % 2 == 0 ) alice += v[i];
        else bob += v[i] ;
    }
    cout << alice - bob << endl;
    return 0 ;
}
