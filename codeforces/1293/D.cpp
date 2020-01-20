#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
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
const ll N = 1e7 + 10 ;
const ll INF = 1e18 + 10 ;
const ll limit = 3e16 ; 
ll x0, y0, ax, ay, bx, by ;  
ll xs, ys , t ;
vector<pair<ll,ll> > points ; 
void generate(){
    points.push_back(make_pair(x0, y0)) ; 
    while(x0 <= limit && y0 <= limit){
        ll a = ax ; 
        ll b = x0 ; 
        x0 = a * b; 
        x0 += bx ; 
        a = ay ; 
        b = y0 ; 
        y0 = a * b ;
        y0 += by ;
        points.push_back(make_pair(x0, y0));
    }
}
ll dist(ll a, ll b, ll c, ll d){
    return abs(a - c) + abs(b - d) ; 
}
int main(){
    fastio
    cin >> x0 >> y0 >> ax >> ay >> bx >> by ; 
    cin >> xs >> ys >> t ; 
    generate() ; 
    debug() << imie(points) ;
    ll n = (ll) points.size() ; 
    ll ans = 0 ; 
    for(ll i = 0; i < n; i++){
        ll a = xs , b = ys ; 
        ll cur = t ; 
        ll cnt = 0 ;
        for(ll j = i; j < n; j++){
            debug() << imie(points[j]) ;
            ll d = dist(a, b, points[j].first, points[j].second) ;
            debug() << imie(cur) imie(d) ;
            if ( cur - d >= 0 ){
                cnt++ ; 
                a = points[j].first ;
                b = points[j].second ; 
                cur -= d ; 
            }
            else break;
        }
        ans = max(ans, cnt) ; 
    }
    for(ll i = n - 1; i >= 0; i--){
        ll a = xs , b = ys ; 
        ll cur = t ; 
        ll cnt = 0 ;
        for(ll j = i; j >= 0; j--){
            debug() << imie(points[j]) ;
            ll d = dist(a, b, points[j].first, points[j].second) ;
            debug() << imie(cur) imie(d) ;
            if ( cur - d >= 0 ){
                cnt++ ; 
                a = points[j].first ;
                b = points[j].second ; 
                cur -= d ; 
            }
            else break;
        }
        ans = max(ans, cnt) ; 
    }
    cout << ans << endl;
    return 0; 
}