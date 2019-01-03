#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n ;
    cin >> n ;
    vector<ll> v1,v2 ;
    ll s1 = 0LL , s2 = 0LL ;
    int cnt = 1;
    for(long long i=n;i>=1;){
        if ( i == 1 ) {
            if ( s1 >= s2 ) {v2.push_back(1);s2++;}
            else {v1.push_back(1);s1++;}
            break;
        }
        if ( cnt % 2 == 1 ){
            v1.push_back(i);
            v2.push_back(i-1);
            s1+=i;
            s2+=(i-1);
        }
        else{
            v1.push_back(i-1);
            v2.push_back(i);
            s1+=(i-1);
            s2+=i;
        }
        i-=2;
        cnt++;
    }
    if ( s1 >= s2 ){
        cout << s1 - s2 << endl;
    }
    else cout << s2 - s1 << endl;
    cout << v1.size() << " " ;
    for(int x : v1){
        cout << x << " " ;
    }
    cout << endl;
    return 0 ;
}
