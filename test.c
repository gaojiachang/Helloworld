#include <stdlib.h>
#include <stdio.h>
typedef struct _node {
    char s[2];
    struct _node * next;
}node;
void f(node *a);
int main(){
    node *a;
    a = (node *)malloc(sizeof(node));
    if (a) printf("1");
    else printf("0");

    return 0;
}
void f(node *a){
    free(a);
    a = NULL;
}