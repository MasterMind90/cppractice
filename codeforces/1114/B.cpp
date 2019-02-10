#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m , k ; 
    cin >> n >> m >> k ; 
    vector<long long> v(n);
    vector<long long> a(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        a[i] = v[i];
    }
    sort(v.rbegin(),v.rend());
    multiset<long long> ma;
    long long sum = 0 ; 
    for(int i=0;i<m*k;i++){
        sum += v[i];
        ma.insert(v[i]);
    }
    int cnt = 0 ; 
    cout << sum << endl;
    for(int i=0;i<n;i++){
        auto it = ma.find(a[i]);
        if ( it != ma.end() ){
            if (cnt == m){
                cout << i << " " ; 
                cnt = 0 ; 
            }
            cnt++;
            ma.erase(it);
        }
    }
    return 0 ; 
}
