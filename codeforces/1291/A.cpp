#include <bits/stdc++.h>

using namespace std;

int main(){
    int t ;
    cin >> t ;
    while(t--){
        int n ;
        cin >> n ;
        string s ;
        cin >> s ;
        int odd = 0 ;
        for(int i = 0; i < n; i++){
            if ( s[i] % 2 == 1 ) odd++;
        }
        if ( odd < 2 ){
            cout << -1 << endl;
        }
        else{
            int cnt = 0 ;
            for(int i = 0; i < n; i++){
                if ( cnt < 2 && s[i] % 2 == 1 ){
                    cout << s[i] ;
                    cnt++;
                }
            }
            cout << endl;
        }
    }

    return 0 ;
}
