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
    // next[i]记录着模式串中第i个字符前的最大前缀的长度,即最大前缀的下一位置的索引
    // j记录着最大前缀的长度
    while (i < pattern[0])
    {
        if (j == 0 || pattern[i] == pattern[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
    return next;
}

int Index_KMP(char *str, char *pattern)
{
    int i = 1, j = 1;
    int *next = get_next(pattern); // 得到next数组

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