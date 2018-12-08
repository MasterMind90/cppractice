#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin >> n >> m ;
    vector<int> v(n);
    int sum = 0 ;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    for(int x : v){
        if ( x < 0 && m ) {
            sum += -1*x;
            m--;
        }
    }
    cout << sum << endl;
    return 0 ;
}
