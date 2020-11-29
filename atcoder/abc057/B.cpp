#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
using namespace std;
 
 
int main(){
    
    int N,M;
    cin >> N >> M;
 
    vector <pair<long long ,long long > > S(N);
    vector <pair <long long, pair<long long ,long long>>> P(M);
 
    for (long long  i = 0; i < N; i++)
        cin >> S[i].first >> S[i].second;
 
    for (long long j = 0; j < M; j++){
        P[j].first = j+1;
        cin >> P[j].second.first >> P[j].second.second;
    }
 
    for (long long i = 0; i < N; i++){
        long long Mndistance = LLONG_MAX;
        long long  Mnindex = M;
 
        for (long long j = 0; j < M; j++){
 
            long long x1 = S[i].first;
            long long y1 = S[i].second;
            long long x2 = P[j].second.first;
            long long y2 = P[j].second.second;
            long long distance = abs(x1 - x2) + abs(y1 - y2);
 
            if (Mndistance > distance){
                //cout  << " distances:"<< Mndistance << "   " << distance << endl;
                Mndistance = distance;
                //cout << "indexes" << index << " " << P[j].first << endl;
                Mnindex = P[j].first;
 
            }
 
            //if (Mndistance == distance) Mnindex = min(index,P[j].first);
        }
        cout << Mnindex << endl;
    }
 
    
 
    
 
    return 0;
}