#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int value;
	struct _node *next;	
}node;
node* CreatList(); //创建链表，返回头节点的地址 
void DeleteList(node *HeadPtr); //释放链表空间，传入头节点地址 
void OutList(node *HeadPtr); //输出列表数值，传入头节点地址 
void SortList(node *HeadPtr); //选择分类节点，传入头节点地址 

int main(void){
	node* HeadPtr;
	HeadPtr = CreatList();
	SortList(HeadPtr);
	printf("The new list is:");
	OutList(HeadPtr);
	printf("\n");
	DeleteList(HeadPtr);
	return 0;
}
node* CreatList(){
	node* HeadPtr = NULL,*CurrentPtr = NULL; //声明头节点与当前节点 
	HeadPtr = (node *)malloc(sizeof(node));
	CurrentPtr = HeadPtr; // 为头节点申请空间后，使得当前结点为头节点 
	int value;
	scanf("%d",&value);	//输入值 
	while (value != -1){
		CurrentPtr->value = value; //为当前结点赋值 
		CurrentPtr->next = (node *)malloc(sizeof(node)); //为当前结点的next申请空间 
		scanf("%d",&value);
		if (value != -1)  //目的是在最后一个节点不会指向下一个 
		CurrentPtr = CurrentPtr->next;
	}
	CurrentPtr->next = NULL; //最后节点的next为空 
	return HeadPtr; //返回头节点地址 
}
void DeleteList(node *HeadPtr){
	node *LastPtr; //声明先前节点 
	while (HeadPtr){
		LastPtr = HeadPtr; //前结点指向当前头结点 
		HeadPtr = HeadPtr->next; //先使得头节点移动为下一个 
		free(LastPtr); //再删除刚才的头节点，也就是目前头节点的上一个节点 
	}
}
void OutList(node *HeadPtr){
	node *CurrentPtr = HeadPtr; //声明当前结点，以防改变头节点指针的值 
	while (CurrentPtr) {
		printf("%d ",CurrentPtr->value);
		CurrentPtr = CurrentPtr->next; //遍历输出 
	}
}
void SortList(node *HeadPtr){
	int min;
	node* MinPtr; //声明最小值，以及最小值所在结点的指针 
	node* NewHeadPtr = HeadPtr; //声明新头结点，防止改变头节点指针的值 
	while (NewHeadPtr) {
		node *CurrentPtr = NewHeadPtr; //使得目前结点指向新头结点 
		min = NewHeadPtr->value;
		MinPtr = NewHeadPtr;
		while (CurrentPtr){
			if (min > CurrentPtr->value){
				min = CurrentPtr->value; 
				MinPtr = CurrentPtr; //遍历搜索最小值，以及储存最小值所在结点的地址 
			}
			CurrentPtr = CurrentPtr->next; //目前结点移向下一个 
		}
		int temp = NewHeadPtr->value;
		NewHeadPtr->value = min;
		MinPtr->value = temp; //利用中间值交换新头结点的值和最小值 
		NewHeadPtr = NewHeadPtr->next; //新头结点移向下一个 
	}
}
