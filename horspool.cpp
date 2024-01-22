#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char str[100], ptn[20];
int res, m, n, len, len1, i, j, k, table[1000];

void shift(char p[])
{
    len = strlen(p);
    for (i = 0; i < 1000; i++)
        table[i] = len;
    for (j = 0; j <= len - 2; j++)
        table[p[j]] = len - 1 - j;
}

int horspool(char p[], char t[])
{
    shift(p);
    m = strlen(p);
    n = strlen(t);
    i = m - 1;
    while (i <= n - 1)
    {
        k = 0;
        while (k <= m - 1 && (p[m - 1 - k] == t[i - k]))
            k++;
        if (k == m)
            return i - m + 1;
        else
            i = i + table[t[i]];
    }
    return -1;
}

int main()
{
    cout << "Enter the text: \n";
    cin.getline(str, sizeof(str));

    cout << "Enter the pattern to be found: \n";
    cin.getline(ptn, sizeof(ptn));

    res = horspool(ptn, str);

    if (res == -1)
        cout << "\nPattern not found\n";
    else
        cout << "Pattern found at " << res + 1 << " position \n";

    return 0;
}
