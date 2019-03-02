#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ; 
    cin >> n ;
    string colors = "ROYGBIV" ;
    for(int i=8;i<=n;i++){
        colors += colors.substr(colors.size()-4,1);
    }
    cout << colors << endl;
    return 0 ;
}
