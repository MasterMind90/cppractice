#include <bits/stdc++.h>
using namespace std;
int cnt[100005];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n , m ;
    cin >> n >> m ;
    set<int> s ;
    for(int i=0;i<m;i++){
        int x ;
        cin >> x ;
        cnt[x]++;
        s.insert(x);
        if ( s.size() == n ) {
            cout << 1;
            s.clear();
            for(int j=1;j<=n;j++){
                cnt[j]--;
                if ( cnt[j] > 0 ) s.insert(j);
            }
        }
        else{
            cout << 0 ;
        }
    }
    cout << endl;
    return 0 ;
}
