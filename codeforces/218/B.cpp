#include <bits/stdc++.h>
using namespace std;

int main(){
    int n , m ;
    cin >> n >> m ;
    priority_queue<int> q1;
    priority_queue<int,vector<int> ,greater<int> > q2 ;
    for(int i=0;i<m;i++){
        int x ;
        cin >> x ;
        q1.push(x);
        q2.push(x);
    }
    int sum = 0 ;
    for(int i=0;i<n;i++){
        int top = q1.top();q1.pop();
        sum += top;
        q1.push(top-1);
    }
    int sum2 = 0 ;
    for(int i=0;i<n;i++){
        while(q2.top()==0)q2.pop();
        int top = q2.top();q2.pop();
        sum2+=top;
        q2.push(top-1);
    }
    cout << sum << " " << sum2 << endl;
    return 0 ;
}
