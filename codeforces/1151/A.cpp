#include <bits/stdc++.h>
using namespace std;
int cnt(int current,int target){
    int moves = 0 ;
    for(int i=current;;i++){
        if ( i%26 == target ) {
            break;
        }
        moves++;
    }
    int moves2 = 0 ;
    for(int i=current;;i--){
        if ( (i%26+26)%26 == target ) {
            break;
        }
        moves2++;
    }
    return min(moves,moves2);
}
int main(){
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    int nax = 1e9 ;
    for(int i=0;i<n-3;i++){
        int op = 0 ;
        if ( s[i] != 'A' ){
            op += cnt(s[i]-'A','A'-'A');
        }
        if ( s[i+1] != 'C' ){
            op += cnt(s[i+1]-'A','C'-'A');
        }
        if ( s[i+2] != 'T' ){
            op += cnt(s[i+2]-'A','T'-'A');
        }
        if ( s[i+3] != 'G' ){
            op += cnt(s[i+3]-'A','G'-'A');
        }
        nax = min(nax,op);
    }
    cout << nax << endl;

    return 0 ;
}
