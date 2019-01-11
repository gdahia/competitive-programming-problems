#include <bits/stdc++.h>
#define pb push_back
#define ms(a, b) memset((a), b, sizeof(a))

using namespace std;

int main() {
    string board[10];
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    int cima[8][8], baixo[8][8];
    ms(cima, 0);
    ms(baixo, 0);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] != '.') {
                cima[i][j]++;
                baixo[i][j]++;
            }
        }
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            cima[j][i] += cima[j - 1][i];
        }
        for (int j = 6; j >= 0; j--) {
            baixo[j][i] += baixo[j + 1][i];
        }
    }
    int minA = 0x3f3f3f3f, minB = -0x3f3f3f3f;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 'W' && cima[i][j] <= 1)
                minA = min(minA, i);
            else if (board[i][j] == 'B' && baixo[i][j] <= 1)
                minB = max(minB, i);
        }
    }
    printf("%c\n", minA <= 7 - minB ? 'A' : 'B');
    return 0;
}