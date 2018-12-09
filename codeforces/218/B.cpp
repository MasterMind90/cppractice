#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin >> n >> m ;
    vector<int> v(m) ;
    for(int i=0;i<m;i++){
        cin >> v[i];
    }
    vector<int> t(v);
    int nn = n ;
    int maxSum = 0 ;
    while(nn>0){
        int high = t[0];
        int hindex = 0 ;
        for(int i=0;i<t.size();i++){
            if ( t[i] > high ) {
                high = t[i];
                hindex = i ;
            }
        }
        maxSum += high ;
        t[hindex]-- ;
        nn--;
    }
    int minSum = 0 ;
    while(n>0){
        int low = 999999;
        int lindex = 0 ;
        for(int i=0;i<v.size();i++){
            if ( v[i] == 0 ) continue ;
            if ( v[i] < low ) {
                low = v[i] ;
                lindex = i ;
            }
        }
        minSum += low ;
        v[lindex]--;
        n--;
    }
    cout << maxSum << " " << minSum << endl;


    return 0 ;
}
