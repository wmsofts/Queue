#include "LQueue.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define TURE 1
#define FALSE 0

//初始化队列
void InitLQueue(LQueue *Q){
	Node *p = (Node *)malloc(sizeof(Node));
	if (NULL == p){
	printf("错误：初始化错误！\n");
	return; 
	}
	p->next = NULL;
	Q->front = p;
	Q->rear = p;
}

//检查队列是否为空
Status IsEmptyLQueue(const LQueue *Q){
		return ((Q->front == Q->rear)? TRUE: FALSE);
}

//入队
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

//出队
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

//查看队头元素
Status GetHeadLQueue(LQueue *Q, void *e) {
	if (IsEmptyLQueue(Q))
		return FALSE;
	memcpy(e, Q->front->next->data, Q->length);//内存拷贝
	/*从Q->front->next->data所指的内存地址的起始位置开始
	拷贝Q->length个字节到目标e所指的内存地址的起始位置中.
	在头结点下一个节点指向的位置赋予字节数 */
	return TRUE;	
}

//长度 
int LengthLQueue(LQueue *Q) {
	int length;
	Node *p = (Node *)malloc(sizeof(Node));
	p = Q->front;
	for (length = 0; p != Q->rear; length++)
		p = p->next; 
	return length;
}

//销毁队列
void DestoryLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q)){
		printf("错误：队列空！\n");
		return;
	}
		return; 
	ClearLQueue(Q);
	free(Q->front);
	free(Q->rear);
}

//清空 
void ClearLQueue(LQueue *Q) {
	if (IsEmptyLQueue(Q)){
		printf("错误：队列空！\n");
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

//遍历
Status TraverseLQueue(const LQueue *Q) {
	if (IsEmptyLQueue(Q)){
		printf("错误：队列空！\n");
		return FALSE;
	}
		Node* p = (void *)malloc(Q->length); 
		p = Q->front->next; 
		int i = 1;
		while (p != NULL) {
		/*	if (i % 5 == 0) printf("\n");  //优化输出格式，自动换行 */
			LPrint(p->data, Q->length);   //foo访问Lprint函数以打印输出 
			p = p->next;
			i++;
		}
		printf("\n");
	return TRUE;
}

//遍历的输出 
void LPrint(void *q, int type) {
	//根据字节数来输出多类型数据 
	if (type == sizeof (int))
	printf("%d", *(int *)q);
	if (type == sizeof(double))  
		printf("%lf", *(double *)q);
	if (type == sizeof(char))
		printf("%c", *(char *)q);
	printf("-<");
}
 
 //用户选择和输入
void Input (LQueue *Q){
	int amount;
	int t; //用户选择的入队数据类型 
	printf("您想入队哪种数据类型？\n");
	printf("1. int整型   2. char字符型   3. double浮点型\n");
	printf("请输入数字序号：");
	scanf("%d",&t) ;
	//用户错误输入处理 
	while(t<1 || t>3) 
    {
     	printf("错误：您应输入1，2或3以选择！\n请重新输入：");
      	scanf("%d", &t);
    }
	printf("您要入队多少个数据：");   //链式存储的泛型队伍不判满 
	scanf("%d",&amount);
	printf("\n注意：int和double类型输入以空格分隔，char类型输入空格也是字符。\n"); 
    printf("请输入入队数据："); 
    switch(t)
    {
     	case 1:{  //int整形 
			int a;
			for(int i = 0;i < amount;i++){
			scanf("%d", &a);
			Q->length = sizeof(int);
			EnLQueue(Q, &a);
			}
		break;
		}
		case 2: {   //字符型 
			char a ;
			getchar();			//吸收上一步多出的一次回车，因为回车也是字符 
			for(int i = 0;i < amount;i++){
			scanf("%c", &a);
			Q->length = sizeof(char);
			EnLQueue(Q, &a);
			}
			break;
		}
        case 3:{   //浮点型 
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
