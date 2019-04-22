#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n ;
    cin >> n ;
    string s ;
    cin >> s ;
    vector<bool> mark(n+1) ;
    vector<int> petya , vasya ;
    for(int i=0;i<n;i++){
        if ( s[i] == '8' ) petya.push_back(i);
        else vasya.push_back(i);
        mark[i] = true ;
    }
    int turn = 0 ;
    int cntV = 0 ;
    int cntP = 0 ;
    for(int i=0;i<n-11;i++){
        if ( turn & 1 ){
            if ( cntP < petya.size() ){
                mark[petya[cntP++]] = false;
            }
            else break;
        }
        else{
            if ( cntV < vasya.size() ){
                mark[vasya[cntV++]] = false;
            }
            else{
                cout << "YES" << endl;
                return 0 ;
            }
        }
        turn++;
    }
    for(int i=0;i<n;i++){
        if ( mark[i] ){
            if ( s[i] == '8' ){
                cout << "YES" << endl;
                return 0 ;
            }
            else {
                cout << "NO" << endl;
                return 0 ;
            }
        }
    }
    return 0 ;
}
