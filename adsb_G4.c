#include <stdio.h>
#include <string.h>

#define maxn 1000
#define maxm 10000

char s[maxn + 5][maxm + 5];
int b[maxn + 5][maxm + 5];
int n, m;

void init(char *data)
{
    n = 0;
    char str[maxm + 5];
    freopen(data, "r", stdin);
    while (scanf("%s", str) == 1)
    {
        strcpy(s[++n], str);
    }
    fclose(stdin);
    m = strlen(s[1]);
    for (int i = 2; i <= n; ++i)
    {
        b[i][0] = s[1][0] == s[i][0] ? 0 : 1;
        for (int j = 1; j < m; ++j)
        {
            b[i][j] = b[i][j - 1] + (s[1][j] == s[i][j] ? 0 : 1);
        }
    }
}

void work(char *range, char *myans)
{
    char str[maxm + 5];
    freopen(range, "r", stdin);
    freopen(myans, "w", stdout);
    scanf("%s", str);
    while (scanf("%s", str) == 1)
    {
        int st, len;
        int ans = 0;
        sscanf(str, "%d, %d", &st, &len);
        scanf("%d", &len);
        for (int i = 2; i <= n; ++i)
        {
            if (!(b[i][st + len - 1] - b[i][st - 1]))
                ans++;
        }
        printf("%d, %d, %d\n", st, len, ans);
    }
    fclose(stdin);
    fclose(stdout);
}

int main(int argc, char *argv[])
{
    init(argv[1]);
    work(argv[2], argv[3]);
    return 0;
}