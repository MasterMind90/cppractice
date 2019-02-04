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
    long long n , k , m ; 
    cin >> n >> k >> m ; 
    vector<long long> v(n); 
    long long sum = 0 ; 
    for(int i=0;i<n;i++){
        cin >> v[i] ; 
        sum += v[i];
    }
    sort(v.begin(),v.end());

    double avg = (sum+min(m,n*k))/(double) n  ; 

    for(int i=0;i<min(n-1,m);i++){
        sum -= v[i];
        int j = i + 1 ; 
        avg = max(avg,( sum+min(m-j,k*(n-j)) )/(double)(n-j) );
    }
    cout << fixed << setprecision(12) << avg << endl;
    return 0;
}
