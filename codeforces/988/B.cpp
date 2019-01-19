#include <bits/stdc++.h>
using namespace std;
int main(){
    int n ;
    cin >> n ;
    vector<pair<int,string> > v(n);
    for(int i=0;i<n;i++){
        string x ;
        cin >> x ;
        v[i].first = x.size() ;
        v[i].second = x ;
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n-1;i++){
        string x = v[i].second ;
        string y = v[i+1].second ;
        bool f = false ;
        for(int i=0;i<=y.size()-x.size();i++){
            string e = y.substr(i,x.size());
            if ( e == x ){
                f = true ;
                break;
            }
        }
        if ( f == false ) {
            cout << "NO" << endl;
            return 0 ;
        }
    }
    cout << "YES" << endl;
    for(auto x : v){
        cout << x.second << endl;
    }
    return 0 ;
}
