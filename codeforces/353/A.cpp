#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<pair<int,int> > v(n);
    int up = 0 ;
    int down = 0 ;
    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second ;
        up+=v[i].first ;
        down+=v[i].second ;
    }
    if ( up % 2 == 0 && down % 2 == 0 ) {
        cout << 0 << endl;
        return 0 ;
    }
    for(int i=0;i<n;i++){
        if ( (up-v[i].first+v[i].second) % 2 == 0 && (down-v[i].second+v[i].first) % 2 == 0 ) {
            cout << 1 << endl;
            return 0 ;
        }
    }
    cout << -1 << endl;
    return 0 ;
}
