#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k ;
    cin >> n >> k ;
    k--;
    vector<int> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int val = v[k];
    for(int i=k+1;i<n;i++){
        if ( v[i] != val ){
            cout << -1 << endl;
            return 0 ;
        }
    }
    bool f = false ;
    int index = 0 ;
    for(int i=k-1;i>=0;i--){
        if ( v[i] != val ){
            index = i ;
            f = true ;
            break;
        }
    }
    if ( index == 0 && f == false ){
        cout << 0 << endl;
        return 0 ;
    }
    else index++;
    cout << index << endl;

    return 0 ;
}
