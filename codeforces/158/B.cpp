#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,num;
vector<int> v;

int main(){
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> num;
        v.push_back(num);
    }
    int taxi=0;
    // 1 & 3 :
    int count1=0;
    int count2=0;
    int count3=0;
    int count4=0;
    for(int i=0;i<N;i++){
        if (v[i]==1)count1++;
        else if (v[i]==2)count2++;
        else if (v[i]==3)count3++;
        else if (v[i]==4)count4++;
    }
    int rem1=0;

    taxi+=count4;

    if (count3 > count1){
        taxi+=(count1+(count3-count1));
    }
    else if (count1 > count3){
        taxi+=(count3);
        rem1=count1-count3;
    }
    else if (count1==count3)taxi+=(count3);

    int remainder=0;

    if (rem1>=4){
        if (rem1%4==0)
            taxi+=(rem1/4);
        else{
            taxi+=(rem1/4);
            remainder=rem1%4;
        }
    }
    else remainder=rem1;

    int remainder2=0;

    if (count2%2==0){
        taxi+=(count2/2);
    }
    else {
        taxi+=(count2/2);
        remainder2=count2%2;
    }

    if ( ((remainder+(remainder2*2))>0) && ((remainder+(remainder2*2))<=4))taxi+=1;
    else if (  ((remainder+(remainder2*2))>4)  )taxi+=2;

    cout << taxi << endl;


    return 0;
}
