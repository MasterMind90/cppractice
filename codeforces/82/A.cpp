#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main(){
    long long n;
    while(cin >> n){
    long long level = 1;
    long long sum=5;
    long long k=0;
    long long i=1;
    while(n>(sum+=(k))){
        level=pow(2,i++);
        if (k==0)k=5;
        k*=2;
    }
    sum-=(k);
    long long res;
    if (n<=5)
        res = n;
    else res = n-sum;
    res = ceil((double)res/level);
    if (res==1) cout << "Sheldon" << endl;
    else if (res==2) cout << "Leonard" << endl;
    else if (res==3) cout << "Penny" << endl;
    else if (res==4) cout << "Rajesh" << endl;
    else cout << "Howard" << endl;
    }
    return 0;
}