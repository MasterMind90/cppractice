#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    string x ;
    cin >> x ;
    int Max = -1e9 ;
    string ms = "" ;
    for(int i=0;i<x.size()-1;i++){
        int cnt = 0 ;
        for(int j=i;j<x.size()-1;j++){
            if ( x[i] == x[j] && x[i+1] == x[j+1] ) cnt++;
        }
        if ( cnt > Max ){
            Max = cnt ;
            ms = x.substr(i,2);
        }
    }
    cout << ms << endl;
    return 0 ;
}
