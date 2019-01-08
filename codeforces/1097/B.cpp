#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(int i=0;i<(1<<n);i++){
        int sum = 0 ;
        for(int j=0;j<n;j++){
            if ( (1<<j) & i ){
                sum += v[j];
            }
            else sum -= v[j];
        }
        if ( sum % 360 == 0 ) {
            cout << "yes" << endl;
            return 0 ;
        }
    }
    cout << "no" << endl;
    return 0 ;
}
