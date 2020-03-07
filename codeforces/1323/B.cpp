#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define int long long
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
typedef long long ll;
const ll MOD = 1e9 + 7 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;
const double EPS = 1e-6 ; 
signed main(){
    fastio
    int n , m , k ; 
    cin >> n >> m >> k ; 
    vector<int> a(n) , b(m) ; 
    for(int i = 0; i < n; i++){
        cin >> a[i] ; 
    }
    for(int i = 0; i < m; i++){
        cin >> b[i] ; 
    }
    vector<int> groupsA ; 
    for(int i = 0; i < n;){
        if ( a[i] == 1 ){
            int cnt = 0 ; 
            while(i < n && a[i] == 1){
                cnt++ ;
                i++ ; 
            }
            groupsA.push_back(cnt) ; 
        }
        else i++ ; 
    }
    vector<int> groupsB ; 
    for(int i = 0; i < m;){
        if ( b[i] == 1 ){
            int cnt = 0 ; 
            while(i < m && b[i] == 1){
                cnt++ ;
                i++ ; 
            }
            groupsB.push_back(cnt) ; 
        }
        else i++ ; 
    }
    sort(groupsA.begin(), groupsA.end());
    sort(groupsB.begin(), groupsB.end());
    debug() << imie(groupsA) ; 
    debug() << imie(groupsB) ; 
    vector<pair<int,int> > div ; 
    for(int i = 1; i * i <= k; i++){
        if ( k % i == 0 ){
            if ( k / i != i ) {
                div.push_back(make_pair(i, k / i));
                div.push_back(make_pair(k / i, i));
            }
            else{
                div.push_back(make_pair(i , i));
            }
        }
    }
    sort(div.begin(), div.end()) ;
    debug() << imie(groupsA) ; 
    debug() << imie(groupsB) ; 
    debug() << imie(div) ;
    int mm = (int) groupsB.size()  ;
    vector<int> sum(mm + 1) ; 
    for(int i = 0; i < mm; i++){
        sum[i + 1] = sum[i] + groupsB[i] ; 
    }
    debug() << imie(sum) ;
    int ans = 0 ;
    for(int i = 0; i < div.size(); i++){
        int x = div[i].first ; 
        int y = div[i].second ; 
        debug() << imie(x) imie(y) ;
        int index1 = lower_bound(groupsA.begin(), groupsA.end(), x) - groupsA.begin() ; 
        int index2 = lower_bound(groupsB.begin(), groupsB.end(), y) - groupsB.begin() ; 
        for(int j = index1; j < groupsA.size(); j++){
            int width = groupsA[j] - x + 1; 
            int height = (sum[mm] - sum[index2]) - (mm - index2) * y + (mm - index2) ; 
            debug() << imie(height) ;
            ans += width * height ; 
        }
    }
    cout << ans << endl;
    return 0; 
}