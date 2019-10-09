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
using ll = long long ;
const int INF = 1e9 + 10 ;
vector<int> v ;
vector<int> T ;
int n ;
int N ;

void build(int node, int start, int end, int type){
    if ( start == end ){
        debug() << imie(v[start]);
        T[node] = v[start] ;
    }
    else{
        int mid = (start + end) / 2 ;
        build(2 * node, start, mid, !type) ;
        build(2 * node + 1, mid + 1, end, !type) ;
        if ( type ){
            T[node] = T[2 * node] ^ T[2 * node + 1] ;
        }
        else T[node] = T[2 * node] | T[2 * node + 1] ;
    }
}

void update(int node, int start, int end,int idx, int val,int type){
    if ( start == end ){
        T[node] = val ;
    }
    else{
        int mid = (start + end) / 2 ;
        if ( idx >= start && idx <= mid ){
            update(2 * node, start, mid, idx, val, !type) ;
        }
        else update(2 * node + 1, mid + 1, end, idx, val, !type ) ;
        if ( type ){
            T[node] = T[2 * node] ^ T[2 * node + 1] ;
        }
        else T[node] = T[2 * node] | T[2 * node + 1] ;
    }
}

int main(){
    int q ;
    cin >> n >> q ;
    N = 1 << n ;
    v.resize(N);
    for(int i = 0; i < N; i++){
        cin >> v[i] ;
    }
    T.resize(4 * N);
    int type = n % 2 == 0 ? 1 : 0 ;
    debug() << imie(type) ;
    build(1, 0, N - 1, type) ;
    debug() << imie(T) ;
    while(q--){
        int idx, val ;
        cin >> idx >> val ;
        idx--;
        update(1, 0, N - 1, idx, val, type);
        debug() << imie(T) ;
        cout << T[1] << endl;
    }
    return 0 ;
}
