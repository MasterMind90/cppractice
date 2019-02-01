#include <bits/stdc++.h>
using namespace std;

#define ABS(x) ((x)<0 ? -(x) : (x))
#define REP(i,n) for(int i=0, _e(n); i<_e; i++)
#define SET(t,v) memset((t), (v), sizeof(t))
#define ALL(x) x.begin(), x.end()
#define UNIQUE(c) (c).resize( unique( ALL(c) ) - (c).begin() )

#define sz size()
#define pb push_back

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;

#ifdef DEBUG
#define dbg(x) x
#define dbgp(x) cerr << x ;
#else
#define dbg(x) //x
#define dbgp(x) //cerr << x << endl;
#endif


int main(){
    int n ; 
    cin >> n ; 
    vector<long long> v(n) ; 
    REP(i,n){
        cin >> v[i] ; 
    }
    sort(ALL(v)); 
    long long ans = 0 ; 
    for(int i=0,j=n-1;i<n/2;i++,j--){
        ans += (v[i]+v[j]) * (v[i]+v[j]) ; 
    }
    cout << ans << endl;
    return 0;
}
