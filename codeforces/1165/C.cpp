#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    int ans = 0 ;
    for(int i=0;i<s.size();i+=2){
        int cur = i ;
        while(cur + 1 < s.size() && s[cur] == s[cur+1]){
            s.erase(cur,1);
            ans++;
        }
    }
    if ( s.size() % 2 == 0 ){
        cout << ans << endl;
        cout << s << endl;
    }
    else {
        cout << ans+1 << endl;
        cout << s.substr(0,s.size()-1) << endl;
    }
    return 0 ;
}
