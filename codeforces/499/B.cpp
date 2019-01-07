#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin >> n >> m ;
    map<string,string> M;
    while(m--){
        string x, y ;
        cin >> x >> y ;
        M[x] = y;
    }
    while(n--){
        string x ;
        cin >> x ;
        string y = M[x];
        if ( y.size() < x.size() ){
            cout << y << " " ;
        }
        else{
            cout << x << " " ;
        }
    }
    cout << endl;
    return 0 ;
}
