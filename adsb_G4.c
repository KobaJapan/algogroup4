#include <stdio.h>
#include <string.h>

#define maxn 1000
#define maxm 10000

char s[maxm + 5];
short b[maxn + 5][maxm + 5];
int n, m;

void init(char *data)
{
    n = 0;
    FILE *fp;
    char buf[maxm + 5];
    fp = fopen(data, "r");
    fgets(s, maxm + 5, fp);
    m = strlen(s);
    while (fgets(buf, maxm + 5, fp) != NULL)
    {
        n++;
        b[n][0] = s[0] == buf[0] ? 0 : 1;
        for (int i = 1; i < m; ++i)
        {
            b[n][i] = b[n][i - 1] + (s[i] == buf[i] ? 0 : 1);
        }
    }
    fclose(fp);
}

void work(char *range, char *myans)
{
    char str[50];
    FILE *fp;
    fp = fopen(range, "r");

    freopen(myans, "w", stdout);
    fgets(str, 50, fp);
    while (fgets(str, 50, fp) != NULL)
    {
        int st, len;
        int ans = 0;
        sscanf(str, "%d, %d", &st, &len);
        for (int i = 1; i <= n; ++i)
        {
            if (!(b[i][st + len - 1] - b[i][st - 1]))
                ans++;
        }
        printf("%d, %d, %d\n", st, len, ans);
    }
    fclose(fp);
    fclose(stdout);
}

int main(int argc, char *argv[])
{
    init(argv[1]);
    work(argv[2], argv[3]);
    return 0;
}