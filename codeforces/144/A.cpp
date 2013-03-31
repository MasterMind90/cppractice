#include <iostream>
using namespace std;
int n;
int A[100];
int counter;
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    int max=A[0];
    int min=A[0];
    for(int i=0;i<n;i++){
        if (A[i]>max)max=A[i];
        if (A[i]<min)min=A[i];
    }
    bool flag1=true;
    bool flag2=true;
    int index1;
    int index2;
    for(int i=0,j=n-1;i<n && j>=0 ;i++,j--){
        if (A[i]==max && flag1){
            flag1=false;
            index1=i;
        }
        else if (flag1)counter++;

        if (A[j]==min && flag2){
            flag2=false;
            index2=j;
        }
        else if (flag2)counter++;

    }
    if (index2<=index1) cout << counter-1 << endl;
    else cout << counter << endl;
    return 0;
}
