#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<long long> v(n);
    long long MIN = 1e18;
    int minIndex = 0 ;
    for(int i=0;i<n;i++){
        cin >> v[i];
        if ( v[i] < MIN ){
            MIN = v[i];
            minIndex = i ;
        }
    }
    int c = 0 ;
    for(int i=0;i<n;i++){
        if ( v[i] == MIN ) c++;
    }
    if ( c == 1 ) {
        cout << minIndex+1 << endl;
    }
    else cout << "Still Rozdil" << endl;
    return 0;
}
