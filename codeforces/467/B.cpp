#include <bits/stdc++.h>
using namespace std;
int n , m , k ;
string res = "" ;
string recur(int x){
    if ( x == 0 ) return res;
    if ( x % 2 == 1 ) return recur(x/2)+"1";
    else return recur(x/2)+"0";
}
string bin(int x){
    res = "" ;
    res = recur(x);
    return res ;
}

int main(){
    cin >> n >> m >> k ;
    vector<int> v(m+1);
    for(int i=0;i<m+1;i++){
        cin >> v[i];
    }
    string fedor = bin(v[m]);
    int ans = 0 ;
    for(int i=0;i<m;i++){
        string op = bin(v[i]);
        string tmp = fedor ;
        int opLen = op.size() ;
        int tmpLen = tmp.size() ;
        if ( opLen > tmpLen ){
            for(int i=0;i<opLen-tmpLen;i++){
                tmp = "0" + tmp ;
            }
        }
        else if ( tmpLen > opLen ) {
            for(int i=0;i<tmpLen - opLen;i++){
                op = "0" + op ;
            }
        }
        int diff = 0 ;
        for(int i=0;i<tmp.size();i++){
            if ( op[i] != tmp[i] ) diff++ ;
        }
        if ( diff <= k ) ans++;
    }
    cout << ans << endl;
    return 0 ;
}
