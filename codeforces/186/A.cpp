#include <bits/stdc++.h>
using namespace std;

int main(){
    string x , y ;
    cin >> x >> y ;
    int countX[26] = {0} ;
    int countY[26] = {0} ;
    if ( x.size() != y.size() ){
        cout << "NO" <<endl;
        return 0 ;
    }
    for(int i=0;i<x.size();i++){
        countX[x[i]-'a']++;
        countY[y[i]-'a']++;
    }
    for(int i=0;i<26;i++){
        if ( countX[i] != countY[i] ){
            cout << "NO" << endl;
            return 0 ;
        }
    }
    int mis = 0 ;
    for(int i=0;i<x.size();i++){
        if ( x[i] != y[i] ) mis++;
    }
    if ( mis == 2 ){
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0 ;
}
