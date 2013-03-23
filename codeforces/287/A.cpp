#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define pb push_back

using namespace std;

char a[4][4];

int dots;
int hash;

int check(int x,int y){


    if (a[x][y]=='.')dots++;
    else hash++;

    if (a[x][y+1]=='.')dots++;
    else hash++;

    if (a[x+1][y]=='.')dots++;
    else hash++;

    if (a[x+1][y+1]=='.')dots++;
    else hash++;

    return 1;
}

int main(){
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            cin >> a[i][j];

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            dots=0;
            hash=0;
            check(i,j);
            if (dots>=3 || hash>=3) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
