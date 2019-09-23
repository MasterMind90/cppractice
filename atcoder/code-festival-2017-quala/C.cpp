#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
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
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set; 

int main(){
    fastio
    int n , m ;
    cin >> n >> m ;
    vector<int> cnt(26) ; 
    for(int i = 0; i < n; i++){
        string s ; 
        cin >> s ; 
        for(char &c : s){
            cnt[c - 'a']++;
        }
    }
    debug() << imie(cnt) ;
    if ( n % 2 == 0 && m % 2 == 0 ){
        for(int &c : cnt){
                if (c && c % 4 != 0)
                    return cout << "No" << endl, 0;
        }
    }
    else if ( (n & 1) && (m & 1) ){
        int four = (n - 1) * (m - 1) / 4;
        int twos = (n - 1) / 2 + (m - 1) / 2 ;
        int one = 1 ;
        for(int i = 0; i < 26; i++){
            int c = min(four, cnt[i] / 4);
            four -= c ; 
            cnt[i] -= c * 4 ;
            c = min(twos, cnt[i] / 2);
            twos -= c ; 
            cnt[i] -= c * 2;
            if ( cnt[i] == 1 ) one--;
        }
        if ( four != 0 || twos != 0 || one != 0 ){
            return cout << "No" << endl , 0 ; 
        }
    }
    else if ( n & 1 ){
        int four = (n - 1) * m / 4;
        int twos = m / 2 ;
        debug() << imie(four) ;
        debug() << imie(twos) ;
        for(int i = 0; i < 26; i++){
            int c = min(four, cnt[i] / 4);
            four -= c ; 
            cnt[i] -= c * 4 ;
            c = min(twos, cnt[i] / 2);
            twos -= c ; 
            cnt[i] -= c * 2;
        }
        if ( four != 0 || twos != 0 ){
            return cout << "No" << endl , 0 ; 
        }
    }
    else {
        int four = n * (m - 1) / 4;
        int twos = n / 2 ;
        for(int i = 0; i < 26; i++){
            int c = min(four, cnt[i] / 4);
            four -= c ; 
            cnt[i] -= c * 4 ;
            c = min(twos, cnt[i] / 2);
            twos -= c ; 
            cnt[i] -= c * 2;
        }
        if ( four != 0 || twos != 0 ){
            return cout << "No" << endl , 0 ; 
        }
    }
    cout << "Yes" << endl;
    return 0 ;
}