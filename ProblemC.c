#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
	int value;
	struct _node *next;	
}node;
node* CreatList(); //创建链表，返回头节点的地址 
void DeleteList(node *HeadPtr); //释放链表空间，传入头节点地址 
int MatchList(node *MomPtr,node *SonPtr); //Son匹配Mom，匹配返回1，不匹配返回0 
int main(){
	node *SonPtr = NULL,*MomPtr = NULL;
	MomPtr = CreatList();
	SonPtr = CreatList();
	if (MatchList(MomPtr,SonPtr)) {
		printf("ListB is the sub sequence of ListA.");
	} else {
		printf("ListB is not the sub sequence of ListA.");
	} //根据返回值输出不同结果 
	DeleteList(MomPtr);
	DeleteList(SonPtr);
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
int MatchList(node *MomPtr,node *SonPtr){
	node *NewMomPtr = MomPtr;
	node *NewSonPtr = SonPtr; //防止改变MomPtr，SonPtr，以声明本地指针 
	node *TempPtr;
	while (NewMomPtr){
		if (NewMomPtr->value == NewSonPtr->value) {   //寻找与SonPtr第一个值相等的第一个MomPtr值 
			TempPtr = NewMomPtr; //储存当前NewMomPtr的位置 
			while (NewSonPtr && NewMomPtr && NewMomPtr->value == NewSonPtr->value){
				NewMomPtr = NewMomPtr->next;
				NewSonPtr = NewSonPtr->next; //Mom和Son都移向下一个 
			}
			if (!NewSonPtr) return 1; //SonPtr到NULL了  
			if (!NewSonPtr) return 0; //MomPtr到NULL了 
 			NewSonPtr = SonPtr; //更新NewSonPtr 
 			NewMomPtr = TempPtr->next; //更新NewMomPtr 
		} else {
			NewMomPtr = NewMomPtr->next; //此处不相等，MomPtr移向下一个 
		} 
	}
	return 0;
}
