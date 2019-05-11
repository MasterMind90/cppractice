#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    int nax = 1e9 ;
    for(int i=0;i<n;i++){
        int x ;
        cin >> x ;
        int cnt = 0 ;
        while(x%2==0){
            cnt++ ;
            x/=2;
        }
        nax = min(nax,cnt);
    }
    cout << nax << endl;

    return 0;
}
