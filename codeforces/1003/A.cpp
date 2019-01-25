#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(101,0) ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        v[x]++ ;
    }
    int MAX = *max_element(v.begin(),v.end());
    cout << MAX << endl;
    return 0 ;
}
