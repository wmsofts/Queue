#include "AQueue.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define TURE 1
#define FALSE 0

//初始化
void InitAQueue(AQueue *Q){
	int i;
	for (i = 0; i < MAXQUEUE; i++){
	Q->data[i] = (void *)malloc(Q->length);
	}
	Q->front = 0;
	Q->rear  = 0;
}

//判空 
Status IsEmptyAQueue(const AQueue *Q) {
	return (Q->front == Q->rear?TRUE: FALSE);
}

//判满
Status IsFullAQueue(const AQueue *Q) {
	return (Q->front == (Q->rear + 1) % MAXQUEUE? TRUE: FALSE);
}
 
//入队
Status EnAQueue(AQueue *Q, void *data) {  //泛型data 
	if (IsFullAQueue(Q)) 
		return FALSE;
	Q->rear = (Q->rear+1) % MAXQUEUE;
	memcpy(Q->data[Q->rear], data, Q->length);
	return TRUE;
}

//出队
Status DeAQueue(AQueue *Q) {
	if (Q->front == Q->rear)
		return FALSE;
	Q->front = (Q->front + 1) % MAXQUEUE;  //求余的应用 
	return TRUE;
}

//销毁队列
void DestoryAQueue(AQueue *Q) {
	int i;
	for (i = 0; i < MAXQUEUE; i++)
		free(Q->data[i]);		//释放内存 
	return;
}

//清空队列
//内存空间没有释放 
void ClearAQueue(AQueue *Q) {
	if (IsEmptyAQueue(Q))
		return;
	Q->front = 0;
	Q->rear = 0;
	return; 
}

//长度
int LengthAQueue(AQueue *Q) {
	return (Q->rear - Q->front + MAXQUEUE) % MAXQUEUE; 
} 

//队头元素
Status GetHeadAQueue(AQueue *Q,void *e) {
	if (IsEmptyAQueue(Q))
		return FALSE;
	int i = Q->front; 
	i = (i + 1) % MAXQUEUE;
	memcpy(e, Q->data[i], Q->length);
	return TRUE;
}

//遍历
Status TraverseAQueue(const AQueue *Q) { 
	if (Q->front == Q->rear)
		return FALSE;
	int i = Q->front + 1;
	while (i <= (MAXQUEUE - Q->front + Q->rear) % MAXQUEUE ) {
		APrint(Q->data[i], Q->length);	 //foo访问Aprint函数以打印输出 
		i = (i + 1) % MAXQUEUE;
	}
	printf("\n");
	return TRUE;
}

//遍历的输出
void APrint(void *q, int type) {
	if (type == sizeof(double))
		printf("%lf", *(double *)q);
	if (type == sizeof(char))
		printf("%c", *(char *)q);
	if (type == sizeof (int))
		printf("%d", *(int *)q);
	printf("->");
}

//用户选择和输入
void Input (AQueue *Q){
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
	printf("您要入队多少个数据(最多 10 个，否则队列满)："); 
	scanf("%d",&amount);
    printf("请输入入队数据："); 
    switch(t)
    {
     	case 1:{  //int整形 
			int a;
			for(int i = 0;i < amount;i++){
			scanf("%d", &a);
			Q->length = sizeof(int);
			EnAQueue(Q, &a);
			}
		break;
		}
		case 2: {   //字符型 
			char a ;
			getchar();			//吸收上一步多出的一次回车，因为回车也是字符 
			for(int i = 0;i < amount;i++){
			scanf("%c", &a);
			Q->length = sizeof(char);
			EnAQueue(Q, &a);
			}
			break;
		}
        case 3:{   //浮点型 
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
