#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ; 
    cin >> n ;
    vector<int> v(n);
    for(int &x: v){
        cin >> x ;
    }
    int len = ceil((int)v.size()/2.0);
    int d = 0 ;
    for(int i=-1000;i<=1000;i++){
        if ( i == 0 ) continue ;
        int pos = 0 ;
        for(int j=0;j<n;j++){
            if ( v[j] == 0 ) continue ; 
            if ( i < 0 && v[j] < 0 ) pos++;
            if ( i > 0 && v[j] > 0 ) pos++;
        }
        if ( pos >= len ) {
            cout << i << endl;
            return 0 ;
        }
    }
    cout << d << endl;
    return 0 ;
}
