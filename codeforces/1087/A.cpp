#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin >> s ;
    int len = s.size() ;
    string ans = "" ;
    if ( len % 2 == 0 ){
        ans += s.substr(len/2-1,2);
        int i = len/2-2;
        int j = len/2+1;
        for(;i>=0;i--,j++){
            ans += s.substr(i,1);
            ans += s.substr(j,1);
        }
    }
    else{
        ans += s.substr(len/2,1);
        int i = len/2-1;
        int j = len/2+1;
        for(;i>=0;i--,j++){
            ans += s.substr(j,1);
            ans += s.substr(i,1);
        }
    }
    cout << ans << endl;
    return 0 ;
}
