#include <bits/stdc++.h>
using namespace std;

int main(){
    int n ;
    cin >> n ;
    priority_queue<long long> even,ev,odd,od ;
    for(int i=0;i<n;i++){
        long long x  ;
        cin >> x ;
        if ( x % 2 ) {
            odd.push(x);
            od.push(x);
        }
        else {
            even.push(x);
            ev.push(x);
        }
    }
    while(odd.size()){
        odd.pop();
        if ( even.size() ) even.pop();
        else break;
    }
    long long sum = 0 ;
    while(odd.size()){
        sum+=odd.top();
        odd.pop();
    }
    while(even.size()){
        sum+=even.top();
        even.pop();
    }
    while(ev.size()){
        ev.pop();
        if ( od.size() ) od.pop();
        else break;
    }
    long long sum2 = 0 ;
    while(od.size()){
        sum2+=od.top();
        od.pop();
    }
    while(ev.size()){
        sum2+=ev.top();
        ev.pop();
    }
    cout << min(sum,sum2) << endl;

    return 0 ;
}
