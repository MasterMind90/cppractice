#include <bits/stdc++.h>
using namespace std;
int n , m , k ;
bool hole[1000005] ;

int main(){
    cin >> n >> m >> k ;
    for(int i=0;i<m;i++){
        int x ;
        cin >> x ;
        hole[x] = true ;
    }
    if ( hole[1] ) {
        cout << 1 << endl;
        return 0 ;
    }
    int cur = 1 ;
    for(int i=0;i<k;i++){
        int x , y ;
        cin >> x >> y ;
        if ( x == cur ){
            cur = y ;
        }
        else if ( y == cur ){
            cur = x ;
        }
        if ( hole[cur] ){
            cout << cur << endl;
            return 0 ;
        }
    }
    cout << cur << endl;


    return 0 ;
}
