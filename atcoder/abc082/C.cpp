#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    map<int,int> m ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        m[x]++;
    }
    int ans = 0 ;
    for(auto &p : m){
        if ( p.second > p.first ) ans += (p.second - p.first);
        else if ( p.second < p.first ) ans += p.second ;
    }
    cout << ans << endl;

    return 0 ;
}
