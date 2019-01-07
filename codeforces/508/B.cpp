#include <bits/stdc++.h>
using namespace std;
int main(){
    string x ;
    cin >> x ;
    int left = -1 ;
    int right = -1;
    for(int i=0;i<x.size();i++){
        if ( x[i] % 2 == 0 && x[i] < x[x.size()-1] ) {
            swap(x[i],x[x.size()-1]);
            cout << x << endl;
            return 0 ;
        }
    }
    for(int i=x.size()-1;i>=0;i--){
        if ( (x[i]-'0')%2 == 0 ){
            right = i ;
            break;
        }
    }
    if ( right != -1 ){
        swap(x[right],x[x.size()-1]);
        cout << x << endl;
        return 0;
    }
    cout << -1 << endl;
    return 0 ;
}
