#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    int cur = 0 ;
    for(int i=0;i<s.size();i++){
        if ( s[i] == '+' ){
            cur++;
        }
        else {
            if ( cur ) cur--;
        }
    }
    cout << cur << endl;

    return 0 ;
}
