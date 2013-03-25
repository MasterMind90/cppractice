#include <iostream>
using namespace std;
unsigned long long n,sum;
long k,i;
int main(){
    cin >> n >> k;
    sum=1;
    while(k!=1 && sum<n){
        sum+=k-1;
        i++;
        k--;
    }
    if (sum>=n)cout << i << endl;
    else cout << -1 << endl;
    return 0;
}
