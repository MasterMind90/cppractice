#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    map<int,int> m ;
    vector<int> dec ;
    vector<int> inc ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        m[x]++;
        if ( m[x] > 2 ) {
            cout << "NO" << endl;
            return 0 ;
        }
    }
    for(auto p : m){
        if ( p.second == 2 ) {
            dec.push_back(p.first);
        }
        inc.push_back(p.first);
    }
    sort(dec.rbegin(),dec.rend());
    sort(inc.begin(),inc.end());
    cout << "YES" << endl;
    cout << inc.size() << endl;
    for(int i=0;i<inc.size();i++){
        cout << inc[i] << " " ;
    }
    cout << endl;
    cout << dec.size() << endl;
    for(int i=0;i<dec.size();i++){
        cout << dec[i] << " " ;
    }
    cout << endl;
    return 0 ;
}
