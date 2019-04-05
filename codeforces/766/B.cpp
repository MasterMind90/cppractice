#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n ;
    cin >> n ;
    vector<long long> v(n) ;
    for(long long &x : v){
        cin >> x ;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n-1;j++){
            long long val = v[i] + v[j] ;
            if ( val > v[j+1] ){
                cout << "YES" << endl;
                return 0 ;
            }
        }
    }
    cout << "NO" << endl;
    return 0 ;
}




