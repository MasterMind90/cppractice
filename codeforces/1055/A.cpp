#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);
typedef long long ll;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const ll INF = 1e18 + 10 ;
#define f first
#define s second

const int N = 1000 ;

vector<int> v[N + N + 10];
vector<bool> vis(N + N + 10);

void dfs(int x){
    if ( vis[x] ) return ;
    vis[x] = true ;
    for(int &c : v[x]){
        dfs(c);
    }
}

int main(){

    int n , s ;
    cin >> n >> s ;

    vector<vector<int> > c(2,vector<int>(n+1)) ;
    for(int i = 0; i < 2; i++){
        for(int j = 1; j <= n; j++){
            cin >> c[i][j] ;
        }
    }
    if ( c[0][1] == 0 ){
        if ( s == 1 ){
            return cout << "YES" << endl, 0;
        }
        else return cout << "NO" << endl, 0;
    }
    if ( c[1][1] ){
        v[1].push_back(1 + n);
    }
    int last = 1;
    for(int i = 2; i <= n; i++){
        if ( c[0][i] ){
            v[last].push_back(i);
            last = i ;
            if ( c[1][i] ){
                v[last].push_back(i + n);
            }
        }
    }
    bool first = true;
    for(int i = n; i >= 1; i--){
        if ( c[1][i] && first ){
            last = i;
            first = false;
        }
        else if ( c[1][i] ){
            v[last].push_back(i);
            last = i ;
        }
    }
    debug() << imie(v);
    dfs(1);
    if ( vis[s] ){
        cout << "yes" << endl;
    }
    else cout << "no" << endl;



    return 0 ;
}

/*
1000101
1001011
*/
