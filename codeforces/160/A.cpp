#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n,num,sum1,sum2;
vector<int> v;
int A[100],B[100];
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    for(int i=0,j=n-1;i<n && j>=0;i++,j--){
        sum1+=v[i];
        A[i]=sum1;
        sum2+=v[j];
        B[i]=sum2;
    }
    reverse(B,B+n);
    int counter=1;
    for(int i=n-1;i>0;i--){
        if (B[i]<=A[i-1])counter++;
        else break;
    }
    cout << counter << endl;
    return 0;
}
