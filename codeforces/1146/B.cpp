#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin >> s ;
    int a = 0 ;
    string ans = "" ;
    for(int i=0;i<s.size();i++){
        if ( s[i] == 'a' ) a++;
        else{
            ans += s.substr(i,1);
        }
    }
    if ( a == s.size() ){
        cout << s << endl;
        return 0 ;
    }
    if ( s[s.size()-1] == 'a' ){
        cout << ":(" << endl;
        return 0 ;
    }
    string first = ans.substr(0,ans.size()/2);
    string second = ans.substr(ans.size()/2);
    if ( first == second && first == s.substr(s.size()-first.size()) ){
        cout << s.substr(0,s.size()-second.size());
    }
    else{
        cout << ":(" << endl;
    }

    return 0 ;
}
