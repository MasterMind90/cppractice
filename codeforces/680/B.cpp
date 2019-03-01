#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , a ; 
    cin >> n >> a ;
    vector<int> v(n+2,1) ;
    for(int i=1;i<=n;i++){
        cin >> v[i];
    }
    int cnt = 0 ; 
    if ( v[a] ) cnt++;
    for(int i=a-1,j=a+1;!(i==0&&j==n+1);){
        if ( v[i] && v[j] && i!=0 && j!=n+1) cnt+=2;
        else if ( v[i] && v[j] && i!=0 ) cnt++;
        else if ( v[i] && v[j] && j!=n+1 ) cnt++;
        i--;
        j++;
        if ( i <= 0 ) i = 0;
        if ( j >= n+1 ) j = n+1;
    }
    cout << cnt << endl;
    return 0 ; 
}
