#include <bits/stdc++.h>
using namespace std;
vector<int> subsets ;
vector<string> q ;
void recur(int x){
    if ( x == 0 ) {
        int sum = 0 ;
        for(int i=0;i<q.size();i++){
            if ( q[i] == "+" ) sum++;
            else sum--;
        }
        subsets.push_back(sum);
        return;
    }
    q.push_back("+");
    recur(x-1);
    q.pop_back();
    q.push_back("-");
    recur(x-1);
    q.pop_back();
}

int main(){
    string a , b ;
    cin >> a >> b ;
    int sumA = 0 ;
    for(int i=0;i<a.size();i++){
        if ( a[i] == '+' ) sumA++;
        else sumA--;
    }
    int mark=0;
    int sumB = 0 ;
    for(int i=0;i<b.size();i++){
        if ( b[i] == '+' ) sumB++;
        else if ( b[i] == '-' ) sumB--;
        else mark++;
    }

    if ( mark == 0 ){
        if ( sumA == sumB ){
            cout << fixed << setprecision(9) << 1.0 << endl;
        }
        else cout << fixed << setprecision(9) << 0.0 << endl;
    }
    else{
        recur(mark);
        int correct = 0 ;
        for(int i=0;i<subsets.size();i++){
            if ( sumB + subsets[i] == sumA ) correct++;
        }
        cout << fixed << setprecision(9) << correct/(double)subsets.size() << endl;
    }

    return 0 ;
}
