#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    int a[10] ;
    for(int i=1;i<=9;i++){
        cin >> a[i] ;
    }
    for(int i=0;i<s.size();i++){
        if ( a[s[i]-'0'] > s[i]-'0' ){
            //cout << s[i] << " : " << a[s[i]-'0'] << endl;
            for(int j=i;j<s.size();j++){
                if ( a[s[j]-'0'] < s[j] - '0' ){
                    break;
                }
                s[j] = a[s[j]-'0'] + '0';
            }
            break;
        }
    }
    cout << s << endl;
    return 0 ;
}
