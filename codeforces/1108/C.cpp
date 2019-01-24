#include <bits/stdc++.h>
using namespace std;

int main(){
    string s[6] = {"RGB","RBG","GBR","GRB","BGR","BRG"};
    int n ;
    cin >> n ;
    string x ;
    cin >> x ;
    int len = n/3 ;
    if ( n % 3 != 0 ) len++;
    int mc = 1e9 ;
    string ans = "" ;
    for(int i=0;i<6;i++){
        string tmp = "" ;
        for(int j=0;j<len;j++){
            tmp += s[i];
        }
        int cnt = 0 ;
        for(int i=0;i<x.size();i++){
            if ( x[i] != tmp[i] ) cnt++;
        }
        if ( cnt < mc ) {
            mc = cnt ;
            ans = tmp;
        }
    }
    cout << mc << endl;
    if ( n % 3 == 1 ){
        cout << ans.substr(0,ans.size()-2);
    }
    else if ( n % 3 == 2 ){
        cout << ans.substr(0,ans.size()-1) ;
    }
    else {
        cout << ans ;
    }
    cout << endl ;

    return 0 ;
}
