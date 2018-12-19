#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int i ;
    for(i=0;i<n;i++){
        if ( v[i] != i+1 ){
            cout << i+1 << endl;
            return 0 ;
        }
    }
    cout << i+1 << endl;


    return 0;
}
