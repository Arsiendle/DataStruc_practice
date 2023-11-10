#include <stdio.h>
#include <stdlib.h>

void flipCards(int numCards)
{
    // 初始化顺序表，所有牌都是正面朝上
    int *cards = (int *)malloc(numCards * sizeof(int));
    for (int i = 0; i < numCards; i++)
    {
        cards[i] = 1;
    }

    // 模拟翻牌过程
    for (int base = 2; base <= numCards; base++)
    {
        for (int i = base - 1; i < numCards; i += base)
        {
            cards[i] = 1 - cards[i]; // 翻牌
        }
    }

    // 统计正面朝上的牌的编号
    int *flippedCards = (int *)malloc(numCards * sizeof(int));
    int numFlippedCards = 0;
    for (int i = 0; i < numCards; i++)
    {
        if (cards[i] == 1)
        {
            flippedCards[numFlippedCards++] = i + 1;
        }
    }

    // 输出结果
    printf("正面朝上的纸牌编号：");
    for (int i = 0; i < numFlippedCards; i++)
    {
        printf("%d ", flippedCards[i]);
    }
    printf("\n");

    printf("正面朝上的纸牌张数：%d\n", numFlippedCards);

    // 释放内存
    free(cards);
    free(flippedCards);
}

int main()
{
    int numCards = 52;
    flipCards(numCards);

    return 0;
}