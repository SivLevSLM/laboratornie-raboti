#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int N,Z;
    fin>>N>>Z;

    vector<int> wes(N),cen(N);
    for (int i=0; i<N; i++) fin >> wes[i];
    for (int i=0; i<N; i++) fin >> cen[i];

    vector<vector<int>> moneti(N+1, vector<int>(Z+1, 0));

    for(int i=1; i<=N; i++){
        for (int j=0; j<=Z; j++){
            moneti[i][j] = moneti[i-1][j];
            if (j>=wes[i-1]){
                moneti[i][j] = max(moneti[i][j], moneti[i-1][j-wes[i-1]]+cen[i-1]);

            }
        }
    }
    int j=Z;
    vector<int> veshi;
    for (int i=N; i>=1; i--){
        if (j>=wes[i-1] && moneti[i][j] == moneti[i-1][j-wes[i-1]] + cen[i-1]){
            veshi.push_back(i);
            j-=wes[i-1];
        }
    }

    reverse(veshi.begin(), veshi.end());

    int sumWes=0, sumCen=0;
    for (int i : veshi){
        sumWes+=wes[i-1];
        sumCen+=cen[i-1];
    }

    for (int i : veshi) fout << i << " ";
    fout << "\n" << sumWes << " " << sumCen << "\n";

}
