#include <bits/stdc++.h>
using namespace std;

int main(){
    int t ;
    cin >> t ;
    while(t--){
        string x ;
        cin >> x ;
        int a[26] = {0} ;
        for(int i=0;i<x.size();i++){
            a[x[i]-'a']++;
        }
        int c = 0 ;
        for(int i=0;i<26;i++){
            if ( a[i] > 0 ) c++;
        }
        if ( c == 1 ) {
            cout << -1 << endl;
            continue ;
        }
        else {
            string ans = "" ;
            for(int i=0;i<26;i++){
                if ( a[i] > 0 ) {
                    string s(a[i],i+'a');
                    ans+=s;
                }
            }
            cout << ans << endl;
        }
    }
    return 0 ;
}
