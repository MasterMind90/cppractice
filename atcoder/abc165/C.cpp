#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
#define sim template < class c
#define int long long
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
~debug() { cerr << '\n'; }
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
typedef tree< pair<int,int>, null_type, less<pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
signed main(){
    fastio
    int n , m , q ;
    cin >> n >> m >> q ;
    vector<int> aa(q) , bb(q) , cc(q) , dd(q) ;
    for(int i = 0; i < q; i++){
        cin >> aa[i] >> bb[i] >> cc[i] >> dd[i] ;
    }
    vector<int> v ;
    auto solve = [&](){
        int sum = 0 ;
        for(int i = 0; i < q; i++){
            if ( v[bb[i] - 1] - v[aa[i] - 1] == cc[i] ) sum += dd[i] ;
        }
        return sum ;
    };
    int ans = 0 ; 
    if ( n == 2 ){
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                v.clear() ;
                v.push_back(i) ;
                v.push_back(j) ;
                ans = max(ans, solve()) ;
            }
        }
    }
    else if ( n == 3 ){
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                for(int k = j; k <= m; k++){
                    v.clear() ;
                    v.push_back(i) ;
                    v.push_back(j) ;
                    v.push_back(k) ;
                    ans = max(ans, solve()) ;
                }
            }
        }
    }
    else if ( n == 4 ){
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                for(int k = j; k <= m; k++){
                    for(int x = k; x <= m; x++){
                        v.clear() ;
                        v.push_back(i) ;
                        v.push_back(j) ;
                        v.push_back(k) ;
                        v.push_back(x) ;
                        ans = max(ans, solve());
                    }
                }
            }
        }
    }
    else if ( n == 5 ){
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                for(int k = j; k <= m; k++){
                    for(int x = k; x <= m; x++){
                        for(int y = x; y <= m; y++){
                            v.clear() ;
                            v.push_back(i) ;
                            v.push_back(j) ;
                            v.push_back(k) ;
                            v.push_back(x) ;
                            v.push_back(y) ;
                            ans = max(ans, solve());
                        }
                    }
                }
            }
        }
    }
    else if ( n == 6 ){
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                for(int k = j; k <= m; k++){
                    for(int x = k; x <= m; x++){
                        for(int y = x; y <= m; y++){
                            for(int u = y; u <= m; u++){
                                v.clear() ;
                                v.push_back(i) ;
                                v.push_back(j) ;
                                v.push_back(k) ;
                                v.push_back(x) ;
                                v.push_back(y) ;
                                v.push_back(u) ;
                                ans = max(ans, solve());
                            }
                        }
                    }
                }
            }
        }
    }
    else if ( n == 7 ){
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                for(int k = j; k <= m; k++){
                    for(int x = k; x <= m; x++){
                        for(int y = x; y <= m; y++){
                            for(int u = y; u <= m; u++){
                                for(int e = u; e <= m; e++){
                                    v.clear() ;
                                    v.push_back(i) ;
                                    v.push_back(j) ;
                                    v.push_back(k) ;
                                    v.push_back(x) ;
                                    v.push_back(y) ;
                                    v.push_back(u) ;
                                    v.push_back(e) ;
                                    ans = max(ans, solve());
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if ( n == 8 ){
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                for(int k = j; k <= m; k++){
                    for(int x = k; x <= m; x++){
                        for(int y = x; y <= m; y++){
                            for(int u = y; u <= m; u++){
                                for(int e = u; e <= m; e++){
                                    for(int w = e; w <= m; w++){
                                        v.clear() ;
                                        v.push_back(i) ;
                                        v.push_back(j) ;
                                        v.push_back(k) ;
                                        v.push_back(x) ;
                                        v.push_back(y) ;
                                        v.push_back(u) ;
                                        v.push_back(e) ;
                                        v.push_back(w) ;
                                        ans = max(ans, solve());
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if ( n == 9 ){
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                for(int k = j; k <= m; k++){
                    for(int x = k; x <= m; x++){
                        for(int y = x; y <= m; y++){
                            for(int u = y; u <= m; u++){
                                for(int e = u; e <= m; e++){
                                    for(int w = e; w <= m; w++){
                                        for(int z = w; z <= m; z++){
                                            v.clear() ;
                                            v.push_back(i) ;
                                            v.push_back(j) ;
                                            v.push_back(k) ;
                                            v.push_back(x) ;
                                            v.push_back(y) ;
                                            v.push_back(u) ;
                                            v.push_back(e) ;
                                            v.push_back(w) ;
                                            v.push_back(z) ;
                                            ans = max(ans, solve());
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else if ( n == 10 ){
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j++){
                for(int k = j; k <= m; k++){
                    for(int x = k; x <= m; x++){
                        for(int y = x; y <= m; y++){
                            for(int u = y; u <= m; u++){
                                for(int e = u; e <= m; e++){
                                    for(int w = e; w <= m; w++){
                                        for(int z = w; z <= m; z++){
                                            for(int p = z; p <= m; p++){
                                                v.clear() ;
                                                v.push_back(i) ;
                                                v.push_back(j) ;
                                                v.push_back(k) ;
                                                v.push_back(x) ;
                                                v.push_back(y) ;
                                                v.push_back(u) ;
                                                v.push_back(e) ;
                                                v.push_back(w) ;
                                                v.push_back(z) ;
                                                v.push_back(p) ;
                                                ans = max(ans, solve());
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0; 
}