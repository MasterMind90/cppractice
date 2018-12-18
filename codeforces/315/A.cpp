#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> a(n) , b(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i] ;
    }
    int ans = 0 ;
    for(int i=0;i<n;i++){
        bool f = false ;
        for(int j=0;j<n;j++){
            if ( i == j ) continue ;
            if ( a[i] == b[j] ) {
                f = true ;
                break ;
            }
        }
        if ( f ) {
            ans++;
        }
    }
    cout << n-ans << endl;
    return 0 ;
}
