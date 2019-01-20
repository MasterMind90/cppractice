#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    string x ;
    cin >> x ;
    for(int i=2;i<=n;i++){
        if ( n % i == 0 ) {
            string s = x.substr(0,i);
            reverse(s.begin(),s.end());
            x.erase(0,i);
            x = s+x;
        }
    }
    cout << x << endl;

    return 0 ;
}
