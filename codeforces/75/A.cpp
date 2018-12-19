#include <bits/stdc++.h>
using namespace std;

int toInt(string x){
    stringstream ss ;
    ss << x ;
    int y ;
    ss >> y ;
    return y ;
}

long long remove(long long a){
    stringstream ss ;
    ss << a ;
    string s ;
    ss >> s ;
    //cout << s << endl;
    string res = "" ;
    for(int i=0;i<s.size();i++){
        if ( s[i] != '0' ) res += s.substr(i,1);
    }
    return toInt(res);
}

int main(){
    long long a , b ;
    cin >> a >> b ;
    long long r = a + b ;
    long long c = remove(r);
    long long h = remove(a)+remove(b);
    if ( c == h ){
        cout << "YES" <<endl;
    }
    else cout << "NO" << endl;
    return 0 ;
}
