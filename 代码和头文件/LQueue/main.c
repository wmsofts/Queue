#include "LQueue.c"

int main(){
	LQueue Q;
	int sign = 1;
	int *p = NULL; 
	printf("***��ʽ�洢�ķ��Ͷ���***\n"); 
	InitLQueue(&Q); 				//��ʼ�� 	
	Input(&Q);
	printf("\n");	
		
	if(IsEmptyLQueue(&Q)){ 			//�п� 
		printf("��ǰ���пա�\n"); 
	}
	else printf("��ǰ���зǿա�\n"); 
	printf("���г��ȣ�%d\n",LengthLQueue(&Q));				
	printf("\n");

	if(sign!=0){
	printf("���ڿ�ʼ������"); 
    TraverseLQueue(&Q);
	} 
    
    printf("\nִ��һ�γ��ӣ�\n"); 
    printf("���±�������ͷԪ���Ѿ����ӣ�"); 
    DeLQueue(&Q); 
    TraverseLQueue(&Q);
    printf("���г��ȣ�%d\n",LengthLQueue(&Q));
	//TraverseLQueue(&Q);
	
	printf("\nִ����գ�\n"); 
	ClearLQueue(&Q);
	if(IsEmptyLQueue(&Q)){ 			//�п� 
		printf("��ǰ���пա�\n"); 
	}
	else printf("��ǰ���зǿա�\n"); 
	printf("���г��ȣ�%d\n",LengthLQueue(&Q));
	
	printf("\n�����������,��Ӻ�ִ������!  ");
	Input(&Q);
	printf("����Ӷ��г��ȣ�%d\n\n",LengthLQueue(&Q));
	printf("�ٴα�����"); 
    TraverseLQueue(&Q);

	
	printf("\nִ�����٣�\n"); 
    DestoryLQueue(&Q);
    printf("������ɡ����³�ʼ����\n"); 
    InitLQueue(&Q); 
    if(IsEmptyLQueue(&Q)){ 			//�п� 
		printf("��ǰ���пա�\n"); 
	}
	else printf("��ǰ���зǿա�\n"); 
	printf("���г��ȣ�%d\n",LengthLQueue(&Q));
	
	printf("\n���Խ�����\n"); 
    
	getch();
	getch();
}
