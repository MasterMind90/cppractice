#include <iostream>
#include <set>
#include <vector>
#include <queue>
using namespace std;
void solve(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    vector<int> cnt(n + 1) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
        cnt[v[i]]++ ;
    }
    int nix = 1e9 + 10 ;
    int index = -1 ;
    for(int i = 0; i < n; i++){
        if ( cnt[v[i]] == 1 ) {
            if ( v[i] < nix ) {
                nix = v[i] ;
                index = i + 1 ;
            }
        }
    }
    cout << index << endl;
}
int main(){
    ios_base::sync_with_stdio(false) ; cin.tie(0) ;
    int t ;
    cin >> t ;
    while(t--) solve() ;

    return 0 ;
}
