#include <bits/stdc++.h>
using namespace std;
long long toInt(string x){
    stringstream ss ;
    ss << x ;
    long long y ;
    ss >> y ;
    return y ;
}
long long p(int x){
    long long r = 1;
    for(int i=0;i<x;i++){
        r*=10;
    }
    return r ;
}
int main(){
    string s ;
    cin >> s ;
    long long x = toInt(s);
    long long digits = s.size() ;
    if ( digits % 2 ) digits++;
    vector<long long> res ;
    for(int mask=0;mask<(1<<digits);mask++){
        int ones = 0 ;
        int zero = 0  ;
        for(int i=0;i<digits;i++){
            if ( mask & (1<<i) ) ones++;
            else zero++;
        }
        long long ans = 0;
        if ( ones == zero ){
            for(int i=0;i<digits;i++){
                if ( mask & (1<<i) ) ans+=(4LL*p(i));
                else ans+=(7LL*p(i));
            }
        }
        res.push_back(ans);
    }
    sort(res.begin(),res.end());
    int index = lower_bound(res.begin(),res.end(),x) - res.begin();
    if ( index == -1 || index == res.size() ){
        digits+=2;
        for(int mask=0;mask<(1<<digits);mask++){
            int ones = 0 ;
            int zero = 0  ;
            for(int i=0;i<digits;i++){
                if ( mask & (1<<i) ) ones++;
                else zero++;
            }
            long long ans = 0;
            if ( ones == zero ){
                for(int i=0;i<digits;i++){
                    if ( mask & (1<<i) ) ans+=(4LL*p(i));
                    else ans+=(7LL*p(i));
                }
            }
            res.push_back(ans);
        }
        sort(res.begin(),res.end());
        int index = lower_bound(res.begin(),res.end(),x) - res.begin();
        cout << res[index] << endl;
    }
    else
        cout << res[index] << endl;
    return 0 ;
}


