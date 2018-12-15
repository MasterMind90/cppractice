#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n , k ;
    cin >> n >> k ;
    string x ;
    cin >> x ;
    long long A[26]={0};
    for(int i=0;i<x.size();i++){
        A[x[i]-'A']++;
    }
    long long ans = 0LL ;
    while(k>0){
        auto p = max_element(A,A+26);
        if ( *p < k ){
            ans += (*p * *p);
            k-=*p;
            *p=0;

        }
        else{
            ans += (k * k);
            break;
        }
    }
    cout << ans << endl;

    return 0 ;
}
