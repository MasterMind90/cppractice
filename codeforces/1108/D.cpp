#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    string x ;
    cin >> x ;
    int cnt = 0 ;
    string ans = x.substr(0,1);
    for(int i=1;i<x.size();i++){
        if ( i == x.size() - 1 ){
            if ( x[i] == x[i-1] && x[i] == 'B' ) {
                cnt++;
                ans += "G";
            }
            else if ( x[i] == x[i-1] && x[i] == 'G' ) {
                cnt++;
                ans += "B";
            }
            else if ( x[i] == x[i-1] && x[i] == 'R' ) {
                cnt++;
                ans += "B";
            }
            else ans += x.substr(i,1);
            break;
        }
        if ( x[i] == x[i-1] && x[i] == 'B' ){
            cnt++;
            if ( x[i+1] == 'B' ){
                ans += "G" ;
                x[i] = 'G' ;
            }
            else if ( x[i+1] == 'G' ){
                ans += "R" ;
                x[i] = 'R' ;
            }
            else if ( x[i+1] == 'R' ){
                ans += "G" ;
                x[i] = 'G' ;
            }
        }
        else if ( x[i] == x[i-1] && x[i] == 'G' ){
            cnt++;
            if ( x[i+1] == 'G' ){
                ans += "B" ;
                x[i] = 'B' ;
            }
            else if ( x[i+1] == 'B' ){
                ans += "R" ;
                x[i] = 'R' ;
            }
            else if ( x[i+1] == 'R' ){
                ans += "B" ;
                x[i] = 'B' ;
            }
        }
        else if ( x[i] == x[i-1] && x[i] == 'R' ){
            cnt++;
            if ( x[i+1] == 'R' ){
                ans += "B" ;
                x[i] = 'B' ;
            }
            else if ( x[i+1] == 'B' ){
                ans += "G" ;
                x[i] = 'G' ;
            }
            else if ( x[i+1] == 'G' ){
                ans += "B" ;
                x[i] = 'B' ;
            }
        }
        else ans += x.substr(i,1);
    }
    cout << cnt << endl;
    cout << ans << endl;
    return 0 ;
}
