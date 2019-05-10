#include <bits/stdc++.h>
using namespace std;

long long power(long long a,long long x){
    long long ans = 1 ;
    for(long long i=0;i<x;i++){
        ans *= a ;
    }
    return ans ;
}

int main(){
    string s ;
    cin >> s ;
    int len = (int) s.size() ;
    vector<long long> v(len+len-1);
    for(long long i=0,j=0;i<len;i++,j+=2){
        v[j] = s[i]-'0';
        if ( j+1 != v.size() )
            v[j+1] = 0 ;
    }
    long long n = len - 1 ;
    long long total = 0 ;
    for(long long mask=0;mask<(1LL<<n);mask++){
        vector<long long> tmp(v.begin(),v.end());
        long long cur = 1 ;
        for(long long i=0;i<n;i++){
            if ( (1LL<<i) & mask ){
                tmp[cur] = -1;
            }
            cur+=2;
        }
        vector<long long> ans ;
        long long res = 0 ;
        long long cnt = 0 ;
        for(long long i=tmp.size()-1;i>=0;i--){
            if ( tmp[i] == 0 ) continue ;
            if ( tmp[i] == -1 ){
                //cout << res << endl;
                ans.push_back(res);
                res = 0 ;
                cnt = 0 ;
                continue ;
            }
            res += tmp[i]*power(10,cnt++);
        }
        ans.push_back(res);
        for(long long x : ans){
            total += x ;
        }
    }
    cout << total << endl;
    return 0 ;
}
