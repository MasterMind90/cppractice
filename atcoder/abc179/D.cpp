#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
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
// const ll MOD = 1e9 + 7 ;
const ll MOD = 998244353 ;
const ll N = 2e5 + 10 ;
const ll INF = 1e18 + 10 ;

template <typename TYPE>
class FenwickTree
{
    private:
        TYPE * add;
        TYPE * mul;
        size_t length;

        // performs the actual range update
        void range_update_helper(size_t pos, TYPE mulfact, TYPE addfact)
        {
            pos += 1;
            while(pos <= length)
            {
                mul[pos - 1] += mulfact;
                add[pos - 1] += addfact;
                pos += pos & -pos;
            }
        }

    public:
        // constructor with vector
        FenwickTree(std::vector<TYPE>& v)
        {
            length = v.size();
            add = new TYPE[length];
            mul = new TYPE[length];

            // initialize
            for(size_t i = 0; i < length; ++i)
            {
                add[i] = 0;
                mul[i] = 0;
            }

            // point-wise updates
            for(size_t i = 0; i < length; ++i)
            {
                point_update(i, v[i]);
            }
        }

        // constructor with an array v[] of given size input_length
        FenwickTree(TYPE v[], int input_length)
        {
            length = input_length;
            add = new TYPE[length];
            mul = new TYPE[length];

            // initialize
            for(size_t i = 0; i < length; ++i)
            {
                add[i] = 0;
                mul[i] = 0;
            }

            // point-wise updates
            for(size_t i = 0; i < length; ++i)
            {
                point_update(i, v[i]);
            }
        }

        // add value 'val' to position i in a[0..length - 1]
        void point_update(size_t i, TYPE val)
        {
            range_update(i, i, val);
        }

        // add value 'val' to postions a[i..j]
        void range_update(size_t i, size_t j, TYPE val)
        {
            if(i < 0 or j < i or j >= length)
            {
                throw std::invalid_argument("subarray range invalid.");
            }
            else
            {
                range_update_helper(i, val, -val * ((TYPE) i - 1));
                range_update_helper(j, -val, val * j);
            }
        }

        // find sum of range a[i..j] (both inclusive)
        TYPE range_sum(size_t i, size_t j)
        {
            if(i < 0 or j < i or j >= length)
            {
                throw std::invalid_argument("subarray range invalid.");
            }
            else
            {
                if(i > 0)
                {
                    return prefix_sum(j) - prefix_sum(i - 1);
                }
                else
                {
                    return prefix_sum(j);
                }
            }
        }

        // find sum of range a[0..i] (both inclusive)
        TYPE prefix_sum(size_t i)
        {
            TYPE mulfact = 0;
            TYPE addfact = 0;

            size_t startindex = i;
            i += 1;

            while(i > 0)
            {
                addfact += add[i - 1];
                mulfact += mul[i - 1];
                i = i & (i - 1);
            }

            return ((TYPE) startindex) * mulfact + addfact;
        }

        // returns the value of a[i]
        TYPE point_sum(size_t i)
        {
            if(i < 0 or i >= length)
            {
                throw std::invalid_argument("invalid array index.");
            }
            else
            {
                return range_sum(i, i);
            }
        }
};
signed main(){
    fastio
    int n , m ; 
    cin >> n >> m ; 
    vector<pair<int,int> > v(m) ;
    for(int i = 0; i < m; i++){
    	cin >> v[i].first >> v[i].second ;
    }
    // # of ways to reach the i cell 
    vector<int> dp(n, 0) ;
    FenwickTree<int> t(dp) ;
    t.point_update(0, 1) ;
    // dp[0] = 1 ;
    for(int i = 1; i < n; i++){
    	int sum = 0 ; 
    	for(int j = 0; j < m; j++){
    		debug() << imie(v[j]) ;
    		int L = max(0LL, i - v[j].second) ; 
    		int R = i - v[j].first ; 
    		if (R < 0) continue ;
    		debug() << imie(L) imie(R) ;
    		sum += t.range_sum(L, R) ; 
    		sum %= MOD ;
    		debug() << imie(L) imie(R) imie(sum);
    		// for(int k = v[j].first; k <= v[j].second; k++){
    		// 	if ( i - k >= 0 ){
    		// 		dp[i] += dp[i - k] ;
    		// 	}
    		// }
    	}

		t.point_update(i, sum) ;
    }
    // debug() << imie(dp) ;
    debug() << imie(t.point_sum(n - 1)) ;
    cout << t.point_sum(n - 1) << endl;
    return 0; 
}

/*
i = 50 ; 
2 7
*/
