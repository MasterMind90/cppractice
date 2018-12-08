#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    vector<int> v(n) ;
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    int m ;
    cin >> m;
    vector<int> vv(m) ;
    for(int i=0;i<m;i++){
        cin >> vv[i];
    }
    vector<int> ratios ;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if ( vv[i] % v[j] == 0 ){
                ratios.push_back(vv[i]/v[j]);
            }
        }
    }
    int gear = 0 ;
    sort(ratios.begin(),ratios.end());
    if ( ratios.size() > 0 ) {
        int MAX = ratios[ratios.size()-1] ;
        for(int i=ratios.size()-1;i>=0;i--){
            if ( ratios[i] == MAX ) gear++ ;
            else break ;
        }
    }
    cout << gear << endl;
    return 0 ;
}
