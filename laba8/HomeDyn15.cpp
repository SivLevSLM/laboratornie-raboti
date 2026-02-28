#include <iostream>
#include <iomanip>
#include "HomeDyn15.h"

void HomeDyn15(){
    using namespace std;
    int K, N;

    cout << "Введите основание системы счисления K (2..10): ";
    cin >> K;

    while (K < 2 || K > 10) {
        cout << "Ошибка! K должно быть от 2 до 10. Повторите ввод: ";
        cin >> K;
    }

    cout << "Введите количество разрядов N (2..19, N + K < 26): ";
    cin >> N;

    while (N <= 1 || N >= 20 || N + K >= 26) {

        if (N <= 1 || N >= 20)
            cout << "Ошибка! N должно быть от 2 до 19. Повторите ввод: ";
        else
            cout << "Ошибка! Должно выполняться N + K < 26. Повторите ввод: ";

        cin >> N;
    }

    double end0 = K - 1;
    double end1 = 0;
    double end2 = 0;
    double end3 = 0;

    for (int len = 2; len <= N; len++) {

        double newEnd0 = (end0 + end1 + end2 + end3) * (K - 1);
        double newEnd1 = end0;
        double newEnd2 = end1;
        double newEnd3 = end2;

        end0 = newEnd0;
        end1 = newEnd1;
        end2 = newEnd2;
        end3 = newEnd3;
    }

    double result = end0 + end1 + end2 + end3;

    cout << "\nРезультат:\n";
    cout << "Количество " << N << "-разрядных " << K << "-ичных чисел\n";
    cout << "без более чем трёх нулей подряд: ";

    cout << fixed << setprecision(0) << result << endl;
}
