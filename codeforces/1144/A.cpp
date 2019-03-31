#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    while(n--){
        string x ;
        cin >> x ;
        sort(x.begin(),x.end());
        bool ok = true ;
        for(int i=1;i<x.size();i++){
            if ( x[i]-1 != x[i-1] ){
                ok = false ;
                break;
            }
        }
        if ( ok ) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0 ;  
}
