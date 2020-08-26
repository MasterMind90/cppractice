#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    vector<bool> used(10) ;
    for(char &c : s){
        if ( c == 'L' ){
            for(int i = 0; i < 10; i++){
                if ( not used[i] ){
                    used[i] = true ;
                    break ;
                }
            }
        }
        else if ( c == 'R' ){
            for(int i = 9; i >= 0; i--){
                if ( not used[i] ) {
                    used[i] = true ;
                    break ;
                }
            }
        }
        else{
            used[c - '0'] = false ;
        }
    }
    for(int i = 0; i < 10; i++){
        cout << used[i] ;
    }
    cout << endl;
    return 0 ;
}
