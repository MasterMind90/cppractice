#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main(){
    int t ;
    cin >> t ;
    while(t--){
        int a , b , x , y ;
        cin >> a >> b >> x >> y ;
        int up = x * b ;
        int down = (a - x - 1) * b ;
        int right = (b - y - 1) * a ;
        int left = y * a ;
        cout << max({up, down, right, left}) << endl;
    }

    return 0 ;
}
