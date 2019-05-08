#include <bits/stdc++.h>
using namespace std;

int main(){
    string s ;
    cin >> s ;
    int cnt[26] = {0} ;
    for(char c : s){
        cnt[c-'a']++;
    }
    for(int x : cnt){
        if ( x&1 ){
            cout << "No" << endl;
            return 0 ;
        }
    }
    cout << "Yes" << endl;
    return 0 ;
}
