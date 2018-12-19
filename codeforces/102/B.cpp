#include <bits/stdc++.h>
using namespace std;
string toString(int x){
    stringstream ss ;
    ss << x ;
    string y ;
    ss >> y ;
    return y ;
}
int toInt(string x){
    stringstream ss ;
    ss << x ;
    int y ;
    ss >> y ;
    return y ;
}
int sumDigit(string x){
    int ans = 0 ;
    for(int i=0;i<x.size();i++){
        ans += (x[i]-'0');
    }
    return ans ;
}
int main(){
    string x ;
    cin >> x ;
    if ( x.size() == 1 ) {
        cout << 0 << endl;
        return 0 ;
    }
    int res = 0 ;
    while(true){
        int c = sumDigit(x);
        x = toString(c);
        res++;

        if ( x.size() == 1 ){
            break;
        }
    }
    cout << res << endl;

    return 0 ;
}
