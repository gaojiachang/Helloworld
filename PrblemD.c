#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int value;
	struct _node *next;	
}node;
node* CreatList(); //创建链表，返回头节点的地址 
void DeleteList(node *HeadPtr); //释放链表空间，传入头节点地址
node* SwapList(node *HeadPtr); //交换链表中的两段，传入头结点地址，函数中输入范围
void OutList(node *HeadPtr); //输出列表数值，传入头节点地址 

int main(void){
	node *HeadPtr;
	HeadPtr = CreatList();
	HeadPtr = SwapList(HeadPtr);
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
node* SwapList(node *HeadPtr){
	int s1,t1,s2,t2;
	scanf("%d %d %d %d",&s1,&t1,&s2,&t2);
	node *s1ptr = HeadPtr,*s2ptr = HeadPtr,*t1ptr = HeadPtr,*t2ptr = HeadPtr;
	for (int i=1;i<s1;i++) s1ptr = s1ptr->next;
	for (int i=1;i<t1;i++) t1ptr = t1ptr->next;
	for (int i=1;i<s2;i++) s2ptr = s2ptr->next;
	for (int i=1;i<t2;i++) t2ptr = t2ptr->next; //声明并找到s1,s2,t1,t2的地址
	node *Befores1Ptr = HeadPtr,*Befores2Ptr = HeadPtr,*Nextt1Ptr = HeadPtr,*Nextt2Ptr = HeadPtr;
	for (int i=1;i<s2-1;i++) Befores2Ptr = Befores2Ptr->next;
	if (s1!=1) 
	for(int i=1;i<s1-1;i++) Befores1Ptr = Befores1Ptr->next;
	for (int i=1;i<t1+1;i++) Nextt1Ptr = Nextt1Ptr->next;
	if (t2ptr->next!=NULL) 
	for(int i=1;i<t2+1;i++) Nextt2Ptr = Nextt2Ptr->next;//声明并找到s1、s2前,t1、t2后的地址
	if (t1 == s2-1) {
		if (s1==1) {
			HeadPtr = s2ptr;
			if (t2ptr->next==NULL){
				t1ptr->next = NULL;
			} else {
				t1ptr->next = Nextt2Ptr;
			}
		} else {
			Befores1Ptr->next = s2ptr;
			if (t2ptr->next==NULL){
				t1ptr->next = NULL;	
			} else {
				t1ptr->next = Nextt2Ptr;
			}
		}
		t2ptr->next = s1ptr;
	} else {
		Befores2Ptr->next = s1ptr;
		if (s1==1) {
			HeadPtr = s2ptr;
			if (t2ptr->next==NULL){
				t1ptr->next = NULL;
			} else {
				t1ptr->next = Nextt2Ptr;
			}
		} else {
			Befores1Ptr->next = s2ptr;
			if (t2ptr->next==NULL){	
				t1ptr->next = NULL;
			} else {
				t1ptr->next = Nextt2Ptr;
			}
		}
		t2ptr->next = Nextt1Ptr;
	}
	//以上代码可能修改HeadPtr的所指，故需要返回；以上代码分类讨论 分别是s1是否为第一个、t2是否为最后一个、s1和t1是否紧挨着！
	return HeadPtr;
}
void OutList(node *HeadPtr){
	node *CurrentPtr = HeadPtr; //声明当前结点，以防改变头节点指针的值 
	while (CurrentPtr) {
		printf("%d ",CurrentPtr->value);
		CurrentPtr = CurrentPtr->next; //遍历输出 
	}
}
