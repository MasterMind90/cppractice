#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);
struct Sq{
    int a , b , c , d ; 
    bool operator==(Sq &z){
        if ( a != z.a ) return false ; 
        if ( b != z.b ) return false ; 
        if ( c != z.c ) return false ; 
        if ( d != z.d ) return false ; 
        return true ; 
    }
};
void solve(){
    int n , m ; 
    cin >> n >> m ; 
    vector<Sq> v(n) ; 
    bool ok = false ; 
    for(int i = 0; i < n; i++){
        cin >> v[i].a >> v[i].b >> v[i].c >> v[i]. d ; 
        if ( v[i].b == v[i].c ) ok = true ; 
    }
    if ( m & 1 ) {
        cout << "NO" << endl;
        return ; 
    }
    if ( not ok ) {
        cout << "NO" << endl;
        return ; 
    }
    bool ok2 = false ; 
    for(int i = 0; i < n; i++){
        Sq X = v[i] ; 
        swap(X.b, X.c) ; 
        for(int j = 0; j < n; j++){
            if ( X == v[j] ) ok2 = true ; 
        }
    }
    if ( ok2 ) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; 
    cin >> t ;
    while(t--) solve() ; 

    cout.flush();
    return 0;
}
