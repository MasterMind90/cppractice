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
    string s , t ; 
    cin >> s >> t ; 
    if ( s.size() != t.size() ){
        cout << "No" << endl;
        return 0 ; 
    }
    for(int i=0;i<s.size();i++){
        bool flag = false ; 
        if ( s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ) {
            if ( t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u' ) {
                flag = true ; 
            }
            if (!flag){
                cout << "No" << endl;
                return 0 ; 
            }
        }
        else{
            if ( t[i] == 'a' || t[i] == 'e' || t[i] == 'i' || t[i] == 'o' || t[i] == 'u' ) {
                flag = true ; 
            }
            if ( flag ){
                cout << "No" << endl;
                return 0 ; 
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
