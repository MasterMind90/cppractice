#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(7) ;
    for(int i=0;i<7;i++){
        cin >> v[i];
    }
    while(true){
        for(int i=0;i<7;i++){
            if ( v[i] >= n ){
                cout << i + 1 << endl;
                return 0 ;
            }
            n-=v[i];
        }
    }

    return 0 ;
}
