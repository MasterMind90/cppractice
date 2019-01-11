#include <bits/stdc++.h>
using namespace std;

int main(){

    string x ;
    cin >> x ;
    int firstBracket = -1 ;
    int firstColon = -1;
    int lastBracket = -1 ;
    int lastColon = -1 ;
    for(int i=0;i<x.size();i++){
        if ( x[i] == '[' ){
            firstBracket = i ;
            break;
        }
    }
    for(int i=firstBracket+1;i<x.size();i++){
        if ( x[i] == ':' ){
            firstColon = i ;
            break ;
        }
    }
    for(int i=x.size()-1;i>=0;i--){
        if ( x[i] == ']' ){
            lastBracket = i ;
            break ;
        }
    }
    for(int i=lastBracket-1;i>=0;i--){
        if ( x[i] == ':' ){
            lastColon = i ;
            break ;
        }
    }
    if ( firstBracket == -1 || firstColon == -1 || lastColon == -1 || lastBracket == -1 ) {
        cout << -1 << endl;
        return 0 ;
    }
    if ( (firstBracket < firstColon) && (firstColon < lastColon) && (lastColon < lastBracket) ) {
        int ans = 0 ;
        for(int i=firstColon+1;i<lastColon;i++){
            if ( x[i] == '|' ) ans++;
        }
        cout << (4+ans) << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0 ;
}

