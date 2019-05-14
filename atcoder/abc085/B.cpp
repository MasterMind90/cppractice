#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int &x : v){
        cin >> x ;
    }
    sort(v.rbegin(),v.rend());
    int cnt = 1 ;
    int cur = v[0];
    for(int i=1;i<n;i++){
        if ( v[i] < cur ){
            cur = v[i] ;
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0 ;
}
