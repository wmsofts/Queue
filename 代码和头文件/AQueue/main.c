#include "AQueue.c"

int main(){
	AQueue Q;
	int sign = 1;
	int *p = NULL; 
	printf("***˳��洢�ķ��Ͷ���***\n"); 
	InitAQueue(&Q); 				//��ʼ�� 	
	Input(&Q);
	printf("\n");	
		
	if(IsEmptyAQueue(&Q)){ 			//�п� 
		printf("��ǰ���пա�\n"); 
	}
	else printf("��ǰ���зǿա�\n"); 
	printf("���г��ȣ�%d\n",LengthAQueue(&Q));
	if(IsFullAQueue(&Q)){ 			//���� 
		printf("��ǰ��������\n"); 	
		printf("������ʱ������ѭ���������δ���Ķ��顣\n");	//�����鲻���� 
		sign = 0;		
	}
	else printf("��ǰ���з�����\n"); 				
	printf("\n");

	if(sign!=0){
	printf("���ڿ�ʼ������"); 
    TraverseAQueue(&Q);
	} 
    
    printf("\nִ��һ�γ��ӣ�\n"); 
    DeAQueue(&Q); 
    printf("���г��ȣ�%d\n",LengthAQueue(&Q));
	//TraverseAQueue(&Q);
	
	printf("\nִ����գ�\n"); 
	ClearAQueue(&Q);
	if(IsEmptyAQueue(&Q)){ 			//�п� 
		printf("��ǰ���пա�\n"); 
	}
	else printf("��ǰ���зǿա�\n"); 
	printf("���г��ȣ�%d\n",LengthAQueue(&Q));
	
	printf("\n�����������,��Ӻ�ִ������!  ");
	Input(&Q);
	printf("����Ӷ��г��ȣ�%d\n\n",LengthAQueue(&Q));
	printf("�ٴα�����"); 
    TraverseAQueue(&Q);

	
	printf("\nִ�����٣�\n"); 
    DestoryAQueue(&Q);
    printf("������ɡ����³�ʼ����\n"); 
    InitAQueue(&Q); 
    if(IsEmptyAQueue(&Q)){ 			//�п� 
		printf("��ǰ���пա�\n"); 
	}
	else printf("��ǰ���зǿա�\n"); 
	printf("���г��ȣ�%d\n",LengthAQueue(&Q));
	
	printf("\n���Խ�����\n"); 
    
	getch();
	getch();
}
