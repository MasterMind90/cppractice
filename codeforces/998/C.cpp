#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n , x , y ;
    cin >> n >> x >> y ;
    string s ;
    cin >> s ;
    long long groups = 0 ;
    for(int i=0;i<s.size();i++){
        if ( s[i] == '0' ){
            int j = i+1;
            while(j<s.size() && s[j]=='0')j++;
            i = j ;
            groups++;
        }
    }
    if ( groups == 0 ) {
        cout << 0 << endl;
    }
    else{
        groups-- ;
        long long ans = groups*min(x,y) + y ;
        cout << ans << endl;

    }


    return 0 ;
}
