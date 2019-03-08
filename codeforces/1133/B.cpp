#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , k ;
    cin >> n >> k ;
    vector<int> v(k,0);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v[x%k]++;
    }
    int cnt = v[0]/2*2; ;
    if ( k % 2 == 0 ) {
        for(int i=1;i<k/2;i++){
            int c = min(v[i],v[k-i]) ;
            cnt+=c*2 ;
        }
        cnt+=v[k/2]/2*2;
    }
    else {
        for(int i=1;i<k/2+1;i++){
            int c = min(v[i],v[k-i]) ;
            cnt+=c*2 ;
        }
    }
    cout << cnt << endl;
    return 0 ;
}
