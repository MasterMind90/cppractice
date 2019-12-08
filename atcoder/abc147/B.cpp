#include <bits/stdc++.h>

using namespace std;

int main(){
    string s ;
    cin >> s ;
    int n = (int) s.size() ;

    int cnt = 0 ;
    for(int i = 0; i < n / 2; i++){
        if ( s[i] != s[n - i - 1] )cnt++;
    }
    cout << cnt << endl;

    return 0 ;
}
