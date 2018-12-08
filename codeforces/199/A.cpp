#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e9 + 1 ;
int main(){
    int n ;
    cin >> n ;
    if ( n == 0 ) {
        cout << 0 << " " << 0 << " " << 0 << endl;
        return 0 ;
    }
    else if ( n == 1 ) {
        cout << 0 << " " << 0 << " " << 1 << endl;
        return 0 ;
    }
    else if ( n == 2 ) {
        cout << 0 << " " << 1 << " " << 1 << endl;
        return 0;
    }
    vector<int> v ;
    v.push_back(0);
    v.push_back(1);
    for(int i=2;;i++){
        v.push_back(v[i-1]+v[i-2]) ;
        if ( v[i] > MAX ) break ;
    }
    for(int i=0;i<v.size();i++){
        if ( v[i] == n ){
            cout << v[i-1] << " " << v[i-3] << " " << v[i-4] << endl;
            return 0;
        }
    }

    return 0 ;
}
