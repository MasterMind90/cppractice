#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n ;
    vector<pair<int,int> > v(n);
    pair<int,int> Big;
    int index = 0 ;
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second ;
        if ( i == 0 ){
            Big = make_pair(v[i].first,v[i].second);
        }
        else{
            if ( v[i].first < Big.first ) Big.first = v[i].first;
            if ( v[i].second > Big.second ) Big.second = v[i].second ;
        }
    }
    for(int i=0;i<v.size();i++){
        if ( v[i].first == Big.first && v[i].second == Big.second ){
            cout << i+1 << endl;
            return 0 ;
        }
    }
    cout << -1 << endl;
    return 0 ;
}
