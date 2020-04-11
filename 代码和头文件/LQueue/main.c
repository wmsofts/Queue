#include "LQueue.c"

int main(){
	LQueue Q;
	int sign = 1;
	int *p = NULL; 
	printf("***链式存储的泛型队列***\n"); 
	InitLQueue(&Q); 				//初始化 	
	Input(&Q);
	printf("\n");	
		
	if(IsEmptyLQueue(&Q)){ 			//判空 
		printf("当前队列空。\n"); 
	}
	else printf("当前队列非空。\n"); 
	printf("队列长度：%d\n",LengthLQueue(&Q));				
	printf("\n");

	if(sign!=0){
	printf("现在开始遍历："); 
    TraverseLQueue(&Q);
	} 
    
    printf("\n执行一次出队！\n"); 
    printf("重新遍历，队头元素已经出队："); 
    DeLQueue(&Q); 
    TraverseLQueue(&Q);
    printf("队列长度：%d\n",LengthLQueue(&Q));
	//TraverseLQueue(&Q);
	
	printf("\n执行清空！\n"); 
	ClearLQueue(&Q);
	if(IsEmptyLQueue(&Q)){ 			//判空 
		printf("当前队列空。\n"); 
	}
	else printf("当前队列非空。\n"); 
	printf("队列长度：%d\n",LengthLQueue(&Q));
	
	printf("\n现在重新入队,入队后将执行销毁!  ");
	Input(&Q);
	printf("已入队队列长度：%d\n\n",LengthLQueue(&Q));
	printf("再次遍历："); 
    TraverseLQueue(&Q);

	
	printf("\n执行销毁！\n"); 
    DestoryLQueue(&Q);
    printf("销毁完成。重新初始化！\n"); 
    InitLQueue(&Q); 
    if(IsEmptyLQueue(&Q)){ 			//判空 
		printf("当前队列空。\n"); 
	}
	else printf("当前队列非空。\n"); 
	printf("队列长度：%d\n",LengthLQueue(&Q));
	
	printf("\n测试结束！\n"); 
    
	getch();
	getch();
}
