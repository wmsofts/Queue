#include "AQueue.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define TURE 1
#define FALSE 0

//��ʼ��
void InitAQueue(AQueue *Q){
	int i;
	for (i = 0; i < MAXQUEUE; i++){
	Q->data[i] = (void *)malloc(Q->length);
	}
	Q->front = 0;
	Q->rear  = 0;
}

//�п� 
Status IsEmptyAQueue(const AQueue *Q) {
	return (Q->front == Q->rear?TRUE: FALSE);
}

//����
Status IsFullAQueue(const AQueue *Q) {
	return (Q->front == (Q->rear + 1) % MAXQUEUE? TRUE: FALSE);
}
 
//���
Status EnAQueue(AQueue *Q, void *data) {  //����data 
	if (IsFullAQueue(Q)) 
		return FALSE;
	Q->rear = (Q->rear+1) % MAXQUEUE;
	memcpy(Q->data[Q->rear], data, Q->length);
	return TRUE;
}

//����
Status DeAQueue(AQueue *Q) {
	if (Q->front == Q->rear)
		return FALSE;
	Q->front = (Q->front + 1) % MAXQUEUE;  //�����Ӧ�� 
	return TRUE;
}

//���ٶ���
void DestoryAQueue(AQueue *Q) {
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);		//�ͷ��ڴ� 
	return;
}

//��ն���
//�ڴ�ռ�û���ͷ� 
void ClearAQueue(AQueue *Q) {
	if (IsEmptyAQueue(Q))
		return;
	Q->front = 0;
	Q->rear = 0;
	return; 
}

//����
int LengthAQueue(AQueue *Q) {
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE; 
} 

//��ͷԪ��
Status GetHeadAQueue(AQueue *Q,void *e) {
	if (IsEmptyAQueue(Q))
		return FALSE;
	int i = Q->front; 
	i = (i + 1) % MAXQUEUE;
	memcpy(e, Q->data[i], Q->length);
	return TRUE;
}

//����
Status TraverseAQueue(const AQueue *Q) { 
	if (Q->front == Q->rear)
		return FALSE;
	int i = Q->front + 1;
	while (i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE ) {
		APrint(Q->data[i], Q->length);	 //foo����Aprint�����Դ�ӡ��� 
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;
}

//���������
void APrint(void *q, int type) {
	if (type == sizeof(double))
		printf("%lf", *(double *)q);
	if (type == sizeof(char))
		printf("%c", *(char *)q);
	if (type == sizeof (int))
		printf("%d", *(int *)q);
	printf("->");
}

//�û�ѡ�������
void Input (AQueue *Q){
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
	printf("��Ҫ��Ӷ��ٸ�����(��� 10 �������������)��"); 
	scanf("%d",&amount);
    printf("������������ݣ�"); 
    switch(t)
    {
     	case 1:{  //int���� 
			int a;
			for(int i = 0;i < amount;i++){
			scanf("%d", &a);
			Q->length = sizeof(int);
			EnAQueue(Q, &a);
			}
		break;
		}
		case 2: {   //�ַ��� 
			char a ;
			getchar();			//������һ�������һ�λس�����Ϊ�س�Ҳ���ַ� 
			for(int i = 0;i < amount;i++){
			scanf("%c", &a);
			Q->length = sizeof(char);
			EnAQueue(Q, &a);
			}
			break;
		}
        case 3:{   //������ 
			double a ;
			for(int i = 0;i < amount;i++){
			scanf("%lf", &a);
			Q->length = sizeof(double);
			EnAQueue(Q, &a);
			}
			break;
		}
	}  
} 
