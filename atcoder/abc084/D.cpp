#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10 ;
bool flag[MAXN];
bool factor(int x){
    int cnt = 0 ;
    while( x % 2 == 0 ){
        cnt++;
        x/=2 ;
        if ( cnt >= 2 ) return false ;
    }
    for(int i=3;i*i<=x;i+=2){
        while( x % i == 0 ){
            cnt++;
            x /= i ;
            if ( cnt >= 2 ) return false;
        }
    }
    if ( x > 2 ){
        cnt++ ;
    }
    if ( cnt >= 2 ) return false ;
    return true ;
}
int main(){
    for(int i=3;i<=MAXN;i+=2){
        if ( factor(i) && factor( (i+1)/2 ) ){
            flag[i] = true ;
        }
    }
    vector<int> v(MAXN+10);
    v[0] = 0 ;
    for(int i=1;i<v.size();i++){
        v[i] = v[i-1];
        if ( flag[i] )
            v[i]++;
    }
    int q ;
    cin >> q ;
    while(q--){
        int l , r ;
        cin >> l >> r ;
        cout << v[r] - v[l-1] << endl;
    }
    return 0 ;
}
