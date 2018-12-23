#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    if ( n == 1 ) {
        cout << 1 << endl;
        return 0 ;
    }
    vector<int> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int MAX = 1 ;
    int len = 2 ;
    for(int i=2;i<n;i++){
        if ( v[i] == (v[i-1]+v[i-2]) ){
            len++;
        }
        else{
            MAX = max(MAX,len);
            len = 2 ;
        }
    }
    MAX = max(MAX,len);
    cout << MAX << endl;
    return 0 ;
}
