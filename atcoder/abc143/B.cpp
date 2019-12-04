#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int i = 0; i < n; i++){
        cin >> v[i] ;
    }
    int ans = 0 ;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ans += v[i] * v[j] ;
        }
    }
    cout << ans << endl;

    return 0 ;
}