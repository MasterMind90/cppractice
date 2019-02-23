#include <bits/stdc++.h>

using namespace std;

int main(){
    long long w1,h1,w2,h2;
    cin >> w1 >> h1 >> w2 >> h2 ;
    long long ans = w1+2 ; 
    ans += 2*h1;
    ans += w2+2;
    ans += h2;
    ans += h2-1;
    ans += w1-w2;
    ans++;
    cout << ans << endl;
    return 0 ;
}
