#include <bits/stdc++.h>
using namespace std;

int main(){
    int b , k ; 
    cin >> b >> k ; 
    vector<int> v(k) ; 
    int sum = 0 ; 
    for(int i=0;i<k;i++){
        cin >> v[i];
        if ( i == k-1 ) {
            if ( v[i]%2 ) sum++;
            else sum+=2;
            continue ; 
        }
        if ( b % 2 == 1 ) {
            if ( v[i]%2 ) sum++;
            else sum+=2;
        }
        else {
            sum += 2 ;
        }
    }
    if ( sum % 2 == 0 ) {
        cout << "even" << endl;
    }
    else cout << "odd" << endl;
    return 0 ; 
}
