#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int MIN = 1e5;
    int t = 0 ;
    for(int i=1;i<=1000;i++){
        int sum = 0 ;
        for(int j=0;j<n;j++){
            if ( abs(v[j]-i) <= 1 ) continue ;
            if ( v[j] > i ) sum+=(v[j]-(i+1));
            else sum+=(abs(i-1-v[j]));
        }
        if ( sum < MIN ) {
            t = i ;
            MIN = sum ;
        }
    }
    cout << t << " " << MIN << endl;

    return 0 ;
}
