#include <bits/stdc++.h>
using namespace std;
int cnt[2*100001];
int main(){
    int n , k ;
    cin >> n >> k ;
    vector<int> v(n);
    vector<int> order(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
        order[i] = v[i];

    }
    sort(v.begin(),v.end());
    for(int i=0;i<k;i++){
        int x , y ;
        cin >> x >> y ;
        x--,y--;
        if ( order[y] < order[x] )
            cnt[x]++;
        if ( order[x] < order[y] )
            cnt[y]++ ;
    }
    for(int i=0;i<n;i++){
        int x = order[i];
        int index = upper_bound(v.begin(),v.end(),x-1) - v.begin() ;
        cout << index-cnt[i] << " " ;
    }
    cout << endl;
    return 0 ;
}
