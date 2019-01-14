#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
map<long long,long long> m ;
long long n ;
vector<ll> subset ;
bool dfs(long long x,long long cnt){
    if ( subset.size() > n ) return false ;
    if ( subset.size() == n ){
        for(long long &x : subset){
            cout << x << ' '  ;
        }
        cout << endl;
        return true ;
    }
    if ( x % 3 == 0 && m[x/3LL] > 0 ){
        m[x/3LL]--;
        subset.push_back(x/3LL);
        if ( dfs(x/3LL,cnt+1LL) == true ) {
            return true ;
        }
        else {
            m[x/3LL]++;
            subset.pop_back();
        }
    }
    if ( m[x*2LL] > 0 ) {
        m[x*2LL]--;
        subset.push_back(x*2LL) ;
        if ( dfs(x*2LL,cnt+1LL) == true ){
            return true ;
        }
        else {
            m[x*2LL]++;
            subset.pop_back();
        }
    }
    return false ;
}

int main(){
    cin >> n ;
    for(int i=0;i<n;i++){
        long long x ;
        cin >> x ;
        m[x]++;
    }
    for(auto p : m){
        subset.clear();
        subset.push_back(p.first);
        if ( dfs(p.first,1LL) == true ) {
            return 0 ;
        }
    }
    return 0  ;
}
