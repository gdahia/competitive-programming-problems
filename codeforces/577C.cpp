# include <bits/stdc++.h>
 
using namespace std;
 
vector <int> primo;
 
int crivo (int i) {
    int ult = primo.size() - 1, flag = 0;
    if ( i <= ult )
        return(primo[i]);
    for (int k = primo[ult] + 2; ; k += 2) {
        flag = 0;
        for (int j = 1; j <= ult && !flag; j++) {
            if ( !(k % primo[j]) )
                flag = 1;
        }
        if (!flag) {
            primo.push_back(k);
            if (primo.size() - 1 == i) return(k);
        }
    }
}
 
int main() {
    int n;
    primo.push_back(2);
    primo.push_back(3);
    scanf("%d", &n);
    int total = n;
    vector <int> res;
    total--;
    for (int i = 0; total && i < n; i++) {
        int atual = crivo(i);
        if (atual <= n) {
            int tam = res.size();
            for (int j = 0; j < tam; j++)
                if (res[j]*atual <= n)
                    total--;
            int pot = atual;
            while (pot <= n) {
                    res.push_back(pot);
                    total--;
                    pot *= atual;
            }
        }
    }
    int tam = res.size();
    printf("%d\n", tam);
    for (int i = 0; i < tam; i++)
        printf("%d%s", res[i], i == tam - 1 ? "\n" : " ");
    return 0;
}