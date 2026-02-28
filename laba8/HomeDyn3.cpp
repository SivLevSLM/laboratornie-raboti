#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include "HomeDyn3.h"

void Solve(std::vector<std::vector<int>>& board, std::vector<std::vector<int>>& dp, std::string& path){
    using namespace std;

    int n = board.size();
    vector<vector<char>> dir(n, vector<char>(n, ' '));

    dp[n - 1][n - 1] = board[n - 1][n - 1];

    for (int j = n - 2; j >= 0; j--) {
        dp[n - 1][j] = dp[n - 1][j + 1] + board[n - 1][j];
        dir[n - 1][j] = 'L';
    }

    for (int i = n - 2; i >= 0; i--) {
        dp[i][n - 1] = dp[i + 1][n - 1] + board[i][n - 1];
        dir[i][n - 1] = 'U';
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {

            if (dp[i + 1][j] > dp[i][j + 1]) {
                dp[i][j] = dp[i + 1][j] + board[i][j];
                dir[i][j] = 'U';
            }
            else {
                dp[i][j] = dp[i][j + 1] + board[i][j];
                dir[i][j] = 'L';
            }
        }
    }

    int i = 0, j = 0;
    while (i != n - 1 || j != n - 1) {

        if (dir[i][j] == 'L') {
            path += 'L';
            j++;
        }
        else {
            path += 'U';
            i++;
        }
    }
}

void HomeDyn3(){
    using namespace std;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream fin("input2.txt");
    if (!fin) {
        cout << "Ошибка открытия входного файла!\n";
        return;
    }

    int N;
    fin >> N;

    vector<vector<int>> board(N, vector<int>(N));
    vector<vector<int>> dp(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            fin >> board[i][j];

    fin.close();

    string path;
    Solve(board, dp, path);

    ofstream fout("output2.txt");

    fout << dp[0][0] << endl;
    fout << path;

    fout.close();

    cout << "Максимальная сумма: " << dp[0][0] << endl;
    cout << "Путь: " << path << endl;
}
