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
    int t ; 
    cin >> t ; 
    while(t--){
        int n, s, e, d;
        cin >> n >> s >> e >> d;
        int direct = INT_MAX ; 
        if ( abs(e-s)%d == 0 ) direct = abs(e-s)/d;
        
        int toStart = ceil( (s-1)/(double)d) ; 
        int fromStart = INT_MAX ; 
        if ( (e-1)%d == 0 ) fromStart = toStart + (e-1)/d ; 

        int toEnd = ceil( (n-s)/(double)d ) ; 
        int fromEnd = INT_MAX ; 
        if ( (n-e) % d == 0 ) fromEnd = toEnd + (n-e) / d ; 

        int result = min(direct,fromStart) ; 
        result = min(result,fromEnd) ; 
        if ( result == INT_MAX ){
            cout << -1 << endl;
        }
        else cout << result << endl;

    }
    
    return 0;
}
