#include <stdio.h>
#include <stdlib.h>

void flipCards(int numCards)
{
    // ��ʼ��˳��������ƶ������泯��
    int *cards = (int *)malloc(numCards * sizeof(int));
    for (int i = 0; i < numCards; i++)
    {
        cards[i] = 1;
    }

    // ģ�ⷭ�ƹ���
    for (int base = 2; base <= numCards; base++)
    {
        for (int i = base - 1; i < numCards; i += base)
        {
            cards[i] = 1 - cards[i]; // ����
        }
    }

    // ͳ�����泯�ϵ��Ƶı��
    int *flippedCards = (int *)malloc(numCards * sizeof(int));
    int numFlippedCards = 0;
    for (int i = 0; i < numCards; i++)
    {
        if (cards[i] == 1)
        {
            flippedCards[numFlippedCards++] = i + 1;
        }
    }

    // ������
    printf("���泯�ϵ�ֽ�Ʊ�ţ�");
    for (int i = 0; i < numFlippedCards; i++)
    {
        printf("%d ", flippedCards[i]);
    }
    printf("\n");

    printf("���泯�ϵ�ֽ��������%d\n", numFlippedCards);

    // �ͷ��ڴ�
    free(cards);
    free(flippedCards);
}

int main()
{
    int numCards = 52;
    flipCards(numCards);

    return 0;
}