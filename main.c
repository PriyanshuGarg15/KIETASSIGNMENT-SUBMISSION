
//list is preorder of the tree
#include <stdio.h>
#include <stdlib.h>
struct list_node
{
	struct list_node *prev_node;
	struct list_node *next_node;
	struct tree_node *tree;
};

struct tree_node
{
	//insert data part/
	int value;
	struct tree_node *left;
	struct tree_node *right;
	struct tree_node *parent;
	struct list_node *list;
};


struct list_node *list_start=NULL;
struct tree_node *tree_start=NULL;

struct list_node* list_create()
{
    struct list_node *n;
    n=(struct list_node*)malloc(sizeof(struct list_node));
    return n;
}

struct tree_node* tree_create()
{
    struct tree_node *n;
    n=(struct tree_node*)malloc(sizeof(struct tree_node));
    return n;
}

void insert()
{
	struct tree_node *temp_tree, *t=tree_start, *s;
	struct list_node *temp_list, *lst;
	temp_tree = tree_create();
	temp_list = list_create();
	printf("enter value\n");
	scanf("%d",&temp_tree->value);
	if(tree_start==NULL)
	{
		tree_start=temp_tree;
		list_start=temp_list;
		temp_list->tree = temp_tree;
		temp_tree->list = temp_list;
	}
	else
	{
		while(t!=NULL)
		{
			if(temp_tree->value > t->value)
			{
				s=t;
				t = t->right;
			}
			else
			{
				s=t;
				t = t->left;
			}
		}
		if(temp_tree->value > s->value)
		{
			s->right = temp_tree;
			temp_tree->parent = s;
			lst = s->list;
			temp_tree->list = temp_list;
			temp_list->tree = temp_tree;
			temp_list->next_node = lst->next_node;
			temp_list->prev_node = lst;
			lst->next_node = temp_list;
		}
		else
		{
			s->left = temp_tree;
			temp_tree->parent = s;
			lst = s->list;
			temp_tree->list = temp_list;
			temp_list->tree = temp_tree;
			temp_list->prev_node = lst->prev_node;
			temp_list->next_node = lst;
			lst->prev_node = temp_list;
		}
	}
}
