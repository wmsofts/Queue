#include "AQueue.c"

int main(){
	AQueue Q;
	int sign = 1;
	int *p = NULL; 
	printf("***顺序存储的泛型队列***\n"); 
	InitAQueue(&Q); 				//初始化 	
	Input(&Q);
	printf("\n");	
		
	if(IsEmptyAQueue(&Q)){ 			//判空 
		printf("当前队列空。\n"); 
	}
	else printf("当前队列非空。\n"); 
	printf("队列长度：%d\n",LengthAQueue(&Q));
	if(IsFullAQueue(&Q)){ 			//判满 
		printf("当前队列满。\n"); 	
		printf("队列满时遍历将循环。请遍历未满的队伍。\n");	//满队伍不遍历 
		sign = 0;		
	}
	else printf("当前队列非满。\n"); 				
	printf("\n");

	if(sign!=0){
	printf("现在开始遍历："); 
    TraverseAQueue(&Q);
	} 
    
    printf("\n执行一次出队！\n"); 
    DeAQueue(&Q); 
    printf("队列长度：%d\n",LengthAQueue(&Q));
	//TraverseAQueue(&Q);
	
	printf("\n执行清空！\n"); 
	ClearAQueue(&Q);
	if(IsEmptyAQueue(&Q)){ 			//判空 
		printf("当前队列空。\n"); 
	}
	else printf("当前队列非空。\n"); 
	printf("队列长度：%d\n",LengthAQueue(&Q));
	
	printf("\n现在重新入队,入队后将执行销毁!  ");
	Input(&Q);
	printf("已入队队列长度：%d\n\n",LengthAQueue(&Q));
	printf("再次遍历："); 
    TraverseAQueue(&Q);

	
	printf("\n执行销毁！\n"); 
    DestoryAQueue(&Q);
    printf("销毁完成。重新初始化！\n"); 
    InitAQueue(&Q); 
    if(IsEmptyAQueue(&Q)){ 			//判空 
		printf("当前队列空。\n"); 
	}
	else printf("当前队列非空。\n"); 
	printf("队列长度：%d\n",LengthAQueue(&Q));
	
	printf("\n测试结束！\n"); 
    
	getch();
	getch();
}
