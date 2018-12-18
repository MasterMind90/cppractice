#include <bits/stdc++.h>
using namespace std;
int a, b , n ;
string toString(int x){
    stringstream ss ;
    ss << x ;
    string res ;
    ss >> res ;
    return res ;
}
int toInt(string x){
    stringstream ss ;
    ss << x ;
    int res ;
    ss >> res ;
    return res ;
}
string check(int i){
    int x = toInt(toString(a)+toString(i)) ;
    if ( x % b == 0 ) return toString(x);
    return "false";
}
int main(){

    cin >> a >> b >> n ;
    for(int i=0;i<10;i++){
        string res = check(i) ;
        if ( res != "false" ){
            string s(n-1,'0');
            cout << res+s << endl;
            return 0 ;
        }
    }
    cout << -1 << endl;
    return 0 ;
}
