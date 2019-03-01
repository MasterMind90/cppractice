#include <bits/stdc++.h>
using namespace std;
int sum(string x){
    int ans = 0 ; 
    for(int i=0;i<x.size();i++){
        ans += x[i] - '0';
    }
    return ans;
}
string toString(int x){
    stringstream ss ;
    ss << x ; 
    string s ; 
    ss >> s ; 
    return s ; 
}
int main(){
    string s ;
    cin >> s ; 
    int cnt = 0 ;
    while( s.size() > 1 ){
        cnt++;
        int x = sum(s);
        s = toString(x);
    }
    cout << cnt << endl;
    return 0;
}
