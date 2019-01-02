#include <bits/stdc++.h>
using namespace std;
int main(){
    int n , k ;
    cin >> n >> k ;
    vector<int> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if ( v[i] < 0 && k > 0 ) {
            v[i]*=-1;
            k--;
        }
    }
    sort(v.begin(),v.end());
    long long sum = 0ll ;
    for(int i=0;i<n;i++){
        sum += (long long) v[i];
    }
    if ( (k > 0) && (k % 2 == 1) ) {
        sum -= 2*v[0];
    }
    cout << sum << endl;
    return 0 ;
}
