#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    string x ;
    cin >> x ;
    int cnt = 0 ;
    for(int i=0;i<x.size()-2;i++){
        if ( x.substr(i,3) == "xxx" ) cnt++;
    }
    cout << cnt << endl;
    return 0 ;
}
