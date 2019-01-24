#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    string x ;
    cin >> x ;
    string cur = "RGB" ;
    sort(cur.begin(),cur.end());
    int mc = 1e9 ;
    string ans = "" ;
    do{
        int cnt = 0 ;
        for(int i=0;i<x.size();i++){
            if ( cur[i%3] != x[i] ) cnt++;
        }
        if ( cnt < mc ) {
            mc = cnt ;
            ans = cur ;
        }
    }while(next_permutation(cur.begin(),cur.end()));

    cout << mc << endl;
    for(int i=0;i<n;i++){
        cout << ans[i%3] ;
    }
    cout << endl;

    return 0 ;
}
