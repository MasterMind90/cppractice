#include <bits/stdc++.h>
using namespace std;

int main(){
    string x ;
    cin >> x ;
    vector<int> v(x.size());
    v[0]=0;
    //cout << v[0] << " " ;
    for(int i=1;i<v.size();i++){
        if ( x[i] == x[i-1] ) v[i]=v[i-1]+1;
        else v[i]=v[i-1];
        //cout << v[i] << " " ;
    }
    int m ;
    cin >> m ;
    while(m--){
        int l , r ;
        cin >> l >> r ;
        l--,r--;
        cout << v[r]-v[l] << endl;
    }
    return 0 ;
}
