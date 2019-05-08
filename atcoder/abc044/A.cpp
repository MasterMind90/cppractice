#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k , x , y ;
    cin >> n >> k >> x >> y ;
    int ans = min(n,k) * x + (n - min(n,k))  * y ;
    cout << ans << endl;
    return 0 ;
}
