#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin >> s ;
    for(int i=1;i<s.size();i++){
        if ( s[i] == s[i-1] && i == s.size() - 1 ){
            s[i] = (s[i]-'a'+1)%26 + 'a' ;
        }
        else if ( s[i] == s[i-1] ){
            s[i] = (s[i]-'a'+1)%26 + 'a' ;
            if ( s[i] == s[i+1] ){
                s[i] = (s[i]-'a'+1)%26 + 'a' ;
            }
        }
    }
    cout << s << endl;
    return 0 ;
}
