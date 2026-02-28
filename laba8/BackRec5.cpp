#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <Windows.h>
#include "BackRec5.h"

void findAns(const std::vector<std::vector<int>>& dp, int k, int s, const std::vector<int>& wes, std::vector<int>& veshi) {
    using namespace std;

    if (k == 0 || s == 0)
        return;
    if (dp[k][s] == dp[k-1][s]) {    
        findAns(dp, k-1, s, wes, veshi);
    } else {
        veshi.push_back(k); 
        findAns(dp, k-1, s - wes[k-1], wes, veshi);
    }
}

int BackRec5() {
    using namespace std;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout<<"Программа берёт значения из файла input.txt\n";
    ifstream fin("input.txt");

    int N, Z;
    fin >>N>>Z;

    vector<int> wes(N), cen(N);
    for (int i = 0; i < N; i++) fin >> wes[i];  
    for (int i = 0; i < N; i++) fin >> cen[i];

    vector<vector<int>> dp(N+1, vector<int>(Z+1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= Z; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= wes[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-wes[i-1]] + cen[i-1]);
            }
        }
    }
    vector<int> veshi;
    findAns(dp, N, Z, wes, veshi);
    reverse(veshi.begin(), veshi.end());

    int sumWes = 0, sumCen = 0;
    for (int i : veshi) {
        sumWes += wes[i-1];
        sumCen += cen[i-1];
    }
    cout << "Артефакты: ";
    for (int i : veshi) cout << i << " ";
    cout << "\nСуммарный вес: " << sumWes << "\nОбщая ценность артефактов: " << sumCen << "\n";

    return 0;
}