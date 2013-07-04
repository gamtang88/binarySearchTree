#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode {
	int key;
	struct TreeNode *left, *right;
} TreeNode;
void display(TreeNode *p)
{
	if( p != NULL ) {
		printf("(");
		display(p->left);
		printf("%d", p->key);
		display(p->right);
		printf(")");
	}
}
// �ݺ����� Ž�� �Լ�
TreeNode *search(TreeNode *node, int key) 
{    
	while(node!=NULL){
		if(key==node->key)return node;
		else if(key<node->key) node=node->left;
		else node=node->right;
	}
	return NULL;
} 
// key�� ����Ž��Ʈ�� root�� �����Ѵ�. key�� �̹� root�ȿ� ������ ���Ե��� �ʴ´�.
void insert_node(TreeNode **root, int key) 
{    
	TreeNode *p,*q;
	TreeNode *n;
	p=*root; q=NULL;
	while(p!=NULL){
		if(key==p->key)return;
		q=p;
		if(key<p->key)p=p->left;
		else p=p->right;
	}
	n= (TreeNode*)malloc(sizeof(TreeNode));
	if(n==NULL)return;
	n->key = key;
	n->left=n->right=NULL;
	if(q!=NULL)
		if(key<q->key)q->left=n;
		else q->right=n;
	else *root =n;
}
void delete_node(TreeNode *node, int key)
{ 
	TreeNode *p,*child,*succ,*succ_p,*t;
	p=NULL; t=node;
	while(t!=NULL&&t->key!=key){
		p=t; t=(key<t->key)?t->left:t->right;
	}
	if(t==NULL){
		printf("key is not int the tree");
		return;
	}
	if((t->left==NULL)&&(t->right==NULL)){
		if(p->left==t)p->left=NULL;
		else p->right=NULL;
	}
	else if((t->left==NULL)||(t->right==NULL)){
		child=(t->left!=NULL)?t->left:t->right;
		if(p->left==t)p->left=child;
		else p->right=child;
	}
	else{
		succ = t->right;
		while(succ->left!=NULL){
			succ_p=succ; succ=succ->left;
		}
		if(succ_p->left==succ)succ_p->left=succ->right;
		else succ_p->right=succ->right;
		t->key=succ->key; t=succ;

	}
	free(t);
}
//
void help()
{
	printf("**************\n");
	printf("i: ����\n");
	printf("d: ����\n");
	printf("s: Ž��\n");
	printf("p: ���\n");
	printf("q: ����\n");
	printf("**************\n");
}

// ���� Ž�� Ʈ�� �׽�Ʈ ���α׷� 
void main()
{
	char command;
	int key;
	TreeNode *root=NULL;
	TreeNode *tmp;
	do{
		help();
		command = getchar();   
		switch(command){
		case 'i':
			printf("����:");
			scanf("%d", &key);
			insert_node(&root, key);
			break;
		case 'd':
			printf("����:");
			scanf("%d", &key);
			delete_node(root, key);
			break;
		case 'p':
			display(root);
			printf("\n");
			break;
		case 's':
			printf("����:");
			scanf("%d", &key);
			tmp=search(root, key);
			if( tmp != NULL )
				printf("Ž������:%d\n", tmp->key);
			break;
		}
		fflush(stdin);

	} while(command != 'q');

}