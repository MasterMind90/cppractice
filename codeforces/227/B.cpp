#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n ;
    vector<long long> v(n+1) ;
    for(long long i=1;i<=n;i++){
        int x ;
        cin >> x ;
        v[x]=i ;
    }
    int m ;
    cin >> m ;
    long long pat = 0 , vas = 0 ;
    while(m--){
        int x ;
        cin >> x ;
        vas += v[x] ;
        pat += (n-v[x]+1LL);
    }
    cout << vas << " " << pat << endl;
    return 0 ;
}
