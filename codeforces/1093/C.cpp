#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n ;
    vector<long long> b(n/2+1);
    b[0] = 0 ;
    for(int i=1;i<=n/2;i++){
        cin >> b[i];
    }
    vector<long long> a(n+1);
    int c1 = 2 ;
    int c2 = n-1 ;
    a[1] = 0 ;
    a[n] = b[1];
    for(int i=2;i<=n/2;i++){
        if ( b[i] <= a[c2+1] ){
            a[c1] = a[c1-1] ;
            a[c2] = b[i]-a[c1];
        }
        else if ( b[i] > a[c2+1] ){
            a[c2] = a[c2+1];
            a[c1] = b[i]-a[c2];
            if ( a[c1] < a[c1-1] ){
                long long diff = a[c1-1] - a[c1];
                a[c1] = a[c1-1];
                a[c2] -= diff ;
            }
        }
        c1++;
        c2--;
    }
    for(int i=1;i<=n;i++){
        cout << a[i] << " " ;
    }
    cout << endl;

    return 0 ;
}
