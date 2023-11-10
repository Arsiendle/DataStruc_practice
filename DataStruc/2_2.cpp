#include <stdio.h>
#include <stdlib.h>

// ˫��ѭ������Ľ�����Ͷ���
typedef int ElemType;
typedef struct DuLNode
{
    ElemType data;         // ��ź��ӵı��
    struct DuLNode *prior; // ǰ��ָ����
    struct DuLNode *next;  // ���ָ����
} CDLNode, *CDLinkList;

void CDLinkList_create(CDLinkList &L, int n)
{
    // ��β�巨����һ������ͷ���ĳ���Ϊn��˫��ѭ������L(LΪ����ͷָ�룩
    CDLinkList p, r;
    L = r = (CDLinkList)malloc(sizeof(CDLNode));
    L->data = 1; // �����������еĵ�1�����
    n--;         // �贴���Ľ������1
    int i = 2;   // �������Ǵӱ��Ϊ2�Ľ�㿪ʼ�����ν��䲢����������
    while (n--)
    {
        p = (CDLinkList)malloc(sizeof(CDLNode));
        p->data = i;
        r->next = p;
        p->prior = r;
        r = p;
        i++;
    }
    r->next = L; // �������β����
    L->prior = r;
}

void Pking_m(CDLinkList &L, CDLinkList &start, int m, CDLinkList &p)
{
    // ��L�е�startλ�ÿ�ʼ˳ʱ�뱨����������m�Ľ��ɾ������ͨ��p���ر�ɾ���ĺ��
    CDLinkList q = start; // qָʾ��ǰ�������Ľ�㣬��start��ָ��㿪ʼ
    int num = 1;
    while (num != m) // ˳ʱ�뱨��
    {
        q = q->next; // ָ��˳ʱ�뷽���ƶ�
        num++;
    }
    printf("%2d�ź��� ��Ȧ\n", q->data);
    p = q->next;        // ͨ��p���ش�ɾ�����ĺ��
    q->prior->next = p; // �޸�ָ�룬ɾ��q��ָʾ�Ľ��
    p->prior = q->prior;
    if (q == L)      // �����ɾ�����ͷ���
        L = q->next; // ��ͷָ���ƶ���ɾ���ĺ��
    free(q);
}

void Pking_k(CDLinkList &L, CDLinkList &start, int k, CDLinkList &p)
{
    // ��L�е�startλ�ÿ�ʼ��ʱ�뱨����������k�Ľ��ɾ������ͨ��p���ر�ɾ����ǰ��
    CDLinkList q = start; // qָʾ��ǰ�������Ľ�㣬��start��ָ��㿪ʼ
    int num = 1;
    while (num != k) // ��ʱ�뱨��
    {
        q = q->prior; // ָ����ʱ�뷽���ƶ�
        num++;
    }
    printf("%2d�ź��� ��Ȧ\n", q->data);
    p = q->prior;      // ͨ��p���ش�ɾ�����q��ǰ��
    p->next = q->next; // �޸�ָ�룬ɾ��q��ָʾ�Ľ��
    q->next->prior = p;
    if (q == L)      // �����ɾ�����ͷ���
        L = q->next; // ��ͷָ���ƶ���ɾ���ĺ��
    free(q);
}

void Pking_Double(CDLinkList &L, int length, int m, int k)
{
    // ģ�����˫��ѡ����Ϸ������LΪ˫��ѭ������lengthΪ����������m��kΪ˳ʱ�����ʱ�뱨��Ҫ��Ȧ����
    CDLinkList p, start = L;
    while (length > 1) // �ظ�˫������ֱ��������ֻʣ��������һ��
    {
        Pking_m(L, start, m, p); // ˳ʱ�뱨��
        length--;
        if (length > 1) // �жϵ�ǰ������ʣ�µĽ�����Ƿ����1
        {
            start = p;
            Pking_k(L, start, k, p); // ��ʱ�뱨��
            start = p;
            length--;
        }
    }
    printf("\n���ѡΪ�������ǣ�%d�ź���\n", L->data);
}

int main()
{
    CDLinkList L = NULL;
    int length, m, k; // lengthΪ�ܺ�������m��kΪ�����򱨵���Ȧ����
    printf("�������ܺ�������");
    scanf("%d", &length);
    CDLinkList_create(L, length); // ��������Ϊlength��˫��ѭ������L

    printf("������˳ʱ�뱨�����ڼ���Ҫ��Ȧ:");
    scanf("%d", &m);
    printf("��������ʱ�뱨�����ڼ���Ҫ��Ȧ:");
    scanf("%d", &k);
    Pking_Double(L, length, m, k); // ����˫��ѡ����Ϸ

    return 0;
}