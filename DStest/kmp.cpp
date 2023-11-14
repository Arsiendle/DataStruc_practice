#include <stdio.h>

int get_Len(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len - 1;
}

int *get_next(char *pattern)
{
    int *next = new int[pattern[0] + 1];
    next[0] = pattern[0];
    next[1] = 0;
    next[2] = 1;

    int i = 2, j = 0;
    // next[j] 的含义是 : 在子串的第j个字符与主串发生失配时, 则跳到子串的next[j] 位置重新与主串当前位置进行比较。
    while (i < pattern[0])
    {
        if (j == 0 || pattern[i] == pattern[j]) // pattern[i]表示后缀的单个字符，pattern[j]表示前缀的单个字符
            next[++i] = ++j;
        else
            j = next[j]; // 若字符不相同，则j值回溯
    }
    return next;
}

int *get_nextval(char *pattern)
{
    int *nextval = new int[pattern[0] + 1];
    nextval[0] = pattern[0];
    nextval[1] = 0;
    nextval[2] = 1;

    int i = 2, j = 0;
    // nextval[j] 的含义是 : 在子串的第j个字符与主串发生失配时, 则跳到子串的nextval[j] 位置重新与主串当前位置进行比较。
    while (i < pattern[0])
    {
        if (j == 0 || pattern[i] == pattern[j]) // pattern[i]表示后缀的单个字符，pattern[j]表示前缀的单个字符
        {
            if (pattern[++i] != pattern[++j])
            {
                nextval[i] = j;
            }
            else
            {
                nextval[i] = nextval[j];
            }
        }
        else
        {
            j = nextval[j]; // 若字符不相同，则j值回溯
        }
    }
    return nextval;
}

int Index_KMP(char *str, char *pattern)
{
    int i = 1, j = 1;
    int *next = get_nextval(pattern); // 得到next数组

    while (i <= str[0] && j <= pattern[0])
    {
        if (j == 0 || str[i] == pattern[j])
        { // 字符相等则继续
            ++i;
            ++j;
        }
        else
        {
            j = next[j]; // 模式串向右移动，i不变
        }
    }
    if (j > pattern[0])
    {
        return i - pattern[0]; // 匹配成功
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *pattern = new char[255];
    scanf("%s", &pattern[1]);
    pattern[0] = get_Len(pattern);

    char *str = new char[255];
    scanf("%s", &str[1]);
    str[0] = get_Len(str);

    printf("%d\n", Index_KMP(str, pattern));

    return 0;
}