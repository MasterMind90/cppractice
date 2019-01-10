#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n ;
    cin >> n ;
    vector<long long> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    long long m ;
    cin >> m ;
    while(m--){
        long long x , y ;
        cin >> x >> y ;
        x--;
        long long Max = max(v[0],v[x]) ;
        cout << Max << endl;
        v[0]=(Max+y) ;
        v[x]=(Max+y) ;
    }
    return 0 ;
}
