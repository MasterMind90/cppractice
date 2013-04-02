#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int A[1000];
int counter;
int check(int x,int index);
int main(){
    cin >> n;
    cin >> A[0];
    for(int i=1;i<n;i++){
        cin >> A[i];
        if (check(A[i],i))counter++;
    }
    cout << counter << endl;
    return 0;
}
int check(int x,int index){
    int max = *max_element(A,A+index);
    int min = *min_element(A,A+index);
    if (x>max)return 1;
    if (x<min)return 1;
    return 0;
}
