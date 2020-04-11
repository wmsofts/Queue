#include "LQueue.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define TURE 1
#define FALSE 0

//��ʼ������
void InitLQueue(LQueue *Q){
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p){
	printf("���󣺳�ʼ������\n");
	return; 
	}
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
}

//�������Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue *Q){
		return ((Q->front == Q->rear)? TRUE: FALSE);
}

//���
Status EnLQueue(LQueue *Q, void *data){
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p)
		return FALSE;
	p->data = (void *)malloc(Q->length);
	memcpy(p->data, data, Q->length);
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}

//����
Status DeLQueue(LQueue *Q) {
	if(IsEmptyLQueue(Q))
		return FALSE;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front->next;
	Q->front->next = p->next;
	if (NULL == Q->front->next)  
		Q->rear = Q->front;
	free(p);
	return TRUE;
}

//�鿴��ͷԪ��
Status GetHeadLQueue(LQueue *Q, void *e) {
	if (IsEmptyLQueue(Q))
		return FALSE;
	memcpy(e, Q->front->next->data, Q->length);//�ڴ濽��
	/*��Q->front->next->data��ָ���ڴ��ַ����ʼλ�ÿ�ʼ
	����Q->length���ֽڵ�Ŀ��e��ָ���ڴ��ַ����ʼλ����.
	��ͷ�����һ���ڵ�ָ���λ�ø����ֽ��� */
	return TRUE;	
}

//���� 
int LengthLQueue(LQueue *Q) {
	int length;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next; 
	return length;
}

//���ٶ���
void DestoryLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q)){
		printf("���󣺶��пգ�\n");
		return;
	}
		return; 
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
}

//��� 
void ClearLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q)){
		printf("���󣺶��пգ�\n");
		return;
	}
	Node *p, *q;
	Q->rear = Q->front;
	p = Q->front->next; 
	while (NULL != p) {
		q = p;
		p = p->next;
		free(q);
	}
	free(p);
}

//����
Status TraverseLQueue(const LQueue *Q) {
	if (IsEmptyLQueue(Q)){
		printf("���󣺶��пգ�\n");
		return FALSE;
	}
		Node* p = (void *)malloc(Q->length); 
		p = Q->front->next; 
		int i = 1;
		while (p != NULL) {
		/*	if (i % 5 == 0) printf("\n");  //�Ż������ʽ���Զ����� */
			LPrint(p->data, Q->length);   //foo����Lprint�����Դ�ӡ��� 
			p = p->next;
			i++;
		}
		printf("\n");
	return TRUE;
}

//��������� 
void LPrint(void *q, int type) {
	//�����ֽ������������������ 
	if (type == sizeof (int))
	printf("%d", *(int *)q);
	if (type == sizeof(double))  
		printf("%lf", *(double *)q);
	if (type == sizeof(char))
		printf("%c", *(char *)q);
	printf("-<");
}
 
 //�û�ѡ�������
void Input (LQueue *Q){
	int amount;
	int t; //�û�ѡ�������������� 
	printf("������������������ͣ�\n");
	printf("1. int����   2. char�ַ���   3. double������\n");
	printf("������������ţ�");
	scanf("%d",&t) ;
	//�û��������봦�� 
	while(t<1 || t>3) 
    {
     	printf("������Ӧ����1��2��3��ѡ��\n���������룺");
      	scanf("%d", &t);
    }
	printf("��Ҫ��Ӷ��ٸ����ݣ�");   //��ʽ�洢�ķ��Ͷ��鲻���� 
	scanf("%d",&amount);
	printf("\nע�⣺int��double���������Կո�ָ���char��������ո�Ҳ���ַ���\n"); 
    printf("������������ݣ�"); 
    switch(t)
    {
     	case 1:{  //int���� 
			int a;
			for(int i = 0;i < amount;i++){
			scanf("%d", &a);
			Q->length = sizeof(int);
			EnLQueue(Q, &a);
			}
		break;
		}
		case 2: {   //�ַ��� 
			char a ;
			getchar();			//������һ�������һ�λس�����Ϊ�س�Ҳ���ַ� 
			for(int i = 0;i < amount;i++){
			scanf("%c", &a);
			Q->length = sizeof(char);
			EnLQueue(Q, &a);
			}
			break;
		}
        case 3:{   //������ 
			double a ;
			for(int i = 0;i < amount;i++){
			scanf("%lf", &a);
			Q->length = sizeof(double);
			EnLQueue(Q, &a);
			}
			break;
		}
	}  
} 
