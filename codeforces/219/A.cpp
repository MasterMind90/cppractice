#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ; 
    cin >> n ; 
    string s ; 
    cin >> s ;
    int cnt[26]={0}; 
    for(int i=0;i<s.size();i++){
        cnt[s[i]-'a']++; 
    }
    string ans = "" ; 
    for(int i=0;i<26;i++){
        if (  cnt[i]!=0 && cnt[i] % n != 0 ) {
            cout << -1 << endl; 
            return 0 ; 
        }
        else if ( cnt[i] != 0 && cnt[i] % n == 0 ){
            string s(cnt[i]/n,char(i+'a'));
            ans+=s;
        }
    }
    string res = "" ; 
    for(int i=0;i<n;i++){
        res = res + ans ;  
    }
    cout << res << endl ; 
    return 0 ; 
}