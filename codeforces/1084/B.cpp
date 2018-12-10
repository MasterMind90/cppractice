#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
int main(){
    ll n , s ;
    cin >> n >> s ;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    ll MIN = v[0];
    ll sum = 0LL ;
    for(int i=1;i<n;i++){
        sum+=(v[i]-MIN);
        v[i] = MIN ;
        if ( sum >= s ){
            cout << MIN << endl;
            return 0 ;
        }
    }
    ll remain = s - sum ;
    ll level = remain/n;
    if ( remain % n != 0 ) level++;

    if ( sum + MIN*n < s ){
        cout << -1 << endl;
        return 0 ;
    }
    if ( level > MIN ){
        cout << -1 << endl;
    }
    else cout << MIN-level << endl;


    return 0 ;
}
