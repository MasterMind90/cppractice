#include <bits/stdc++.h>
using namespace std;
vector<long long> even;
vector<long long> odd;
int main(){
    int n ;
    cin >> n ;
    vector<long long> v(n);
    even.resize(n);
    odd.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        if ( i > 0 ) {
            even[i] += even[i-1];
            odd[i] += odd[i-1];
        }
        if ( i % 2 == 0 ){
            odd[i] += v[i];
        }
        else even[i] += v[i];
    }
    int cnt = 0 ;
    for(int i=0;i<n;i++){
        long long o = 0 ;
        long long e = 0 ;
        if ( i == 0 ){
            o = odd[n-1] - v[i];
            e = even[n-1] ;
        }
        else{
            o = odd[i-1] + even[n-1] - even[i];
            e = even[i-1] + odd[n-1] - odd[i];
        }
        if ( o == e ){
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0 ;
}
