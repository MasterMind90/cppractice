#include <bits/stdc++.h>
using namespace std;

int main(){
    string x ;
    cin >> x ;
    long long ans = 0 ;
    while(true){
        if ( x.size() <= 1 ) break;
        bool f = false;
        for(int i=0;i<=x.size()-2;i++){
            if ( x[i] == x[i+1] ){
                ans++;
                x.erase(i,2);
                f = true ;
                break;
            }
        }
        if ( !f ) break;
    }
    if ( ans % 2 ){
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
    return 0 ;
}
