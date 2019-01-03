#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , m ;
    cin >> n >> m ;
    vector<long long> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    long long increase = 0LL;
    while(m--){
        int t ;
        cin >> t ;
        if ( t == 1 ) {
            long long i , x ;
            cin >> i >> x ;
            i--;
            v[i]=x-increase;
        }
        else if ( t == 2 ){
            long long y ;
            cin >> y ;
            increase += y ;
        }
        else{
            int i ;
            cin >> i ;
            i--;
            cout << v[i]+increase << endl;
        }
    }
    return 0 ;
}
