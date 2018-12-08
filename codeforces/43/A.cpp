#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    map<string,int> m ;
    while(n--){
        string s ;
        cin >> s ;
        m[s]++;
    }
    int c = 0 ;
    string ans = "" ;
    for(auto &p : m){
        if ( p.second > c ){
            c = p.second ;
            ans = p.first;
        }
    }
    cout << ans << endl;

    return 0 ;
}
