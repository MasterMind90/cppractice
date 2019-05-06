#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m , k ;
    cin >> n >> m >> k ;
    vector<int> v(k);
    for(int i=0;i<k;i++){
        cin >> v[i] ;
    }
    int ans = 0 ;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int item ;
            cin >> item ;
            for(int i=0;i<k;i++){
                if ( item == v[i] ){
                    ans += i+1;
                    v.erase(v.begin()+i);
                    v.insert(v.begin(),item);
                    break;
                }
            }
        }
    }
    cout << ans << endl;


    return 0 ;
}
