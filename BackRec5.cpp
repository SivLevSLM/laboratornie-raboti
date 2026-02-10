#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

void findAns(const vector<vector<int>>& moneti, int k, int s, const vector<int>& wes, vector<int>& veshi) {
    if (k == 0 || s == 0)
        return;
    if (moneti[k][s] == moneti[k-1][s]) {    
        findAns(moneti, k-1, s, wes, veshi);
    } else {
        veshi.push_back(k); 
        findAns(moneti, k-1, s - wes[k-1], wes, veshi);
    }
}

int main() {
    cout<<"Программа берёт значения из файла input.txt";
    ifstream fin("input.txt");

    int N, Z;
    fin >>N>>Z;

    vector<int> wes(N), cen(N);
    for (int i = 0; i < N; i++) fin >> wes[i];  
    for (int i = 0; i < N; i++) fin >> cen[i];

    vector<vector<int>> moneti(N+1, vector<int>(Z+1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= Z; j++) {
            moneti[i][j] = moneti[i-1][j];
            if (j >= wes[i-1]) {
                moneti[i][j] = max(moneti[i][j], moneti[i-1][j-wes[i-1]] + cen[i-1]);
            }
        }
    }
    vector<int> veshi;
    findAns(moneti, N, Z, wes, veshi);
    reverse(veshi.begin(), veshi.end());

    int sumWes = 0, sumCen = 0;
    for (int i : veshi) {
        sumWes += wes[i-1];
        sumCen += cen[i-1];
    }

    for (int i : veshi) cout << i << " ";
    cout << "\n" << sumWes << " " << sumCen << "\n";

    return 0;
}
