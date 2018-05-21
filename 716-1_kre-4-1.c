#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int value;
	struct node *next;
	struct node *prev;
} node;

node *head = NULL;
node *tail = NULL;

int isEmpty()
{
	if (head == NULL && tail == NULL)
		return 1;
	return 0;
}

int storm()
{
	if (isEmpty())
	{
		return 0;
	}
	node *crnt = head;
	printf("%d ", crnt->value);
	crnt->next->prev = NULL;
	head = crnt->next;
	free(crnt);
	return 1;
}

void print()
{
	node *crnt = head;
	while (crnt != NULL)
	{
		printf("%d ", crnt->value);
		crnt = crnt->next;
	}
	printf("\n");
}

void check(int value)
{
	if (isEmpty())
	{
		node *tmp = malloc(sizeof(node));
		tmp->value = value;
		head = tmp;
		tail = tmp;
		tmp->next = NULL;
		tmp->prev = NULL;
	}
	else
	{
		node *tmp = malloc(sizeof(node));
		tmp->value = value;
		tmp->next = NULL;
		tmp->prev = tail;
		tail->next = tmp;
		tail = tmp;
	}
}

int main()
{
	int quantity;
	scanf("%d", &quantity);
	for (int i = 0; i<quantity; i++)
	{
		int value;
		scanf("%d", &value);
		check(value);
	}

	print();

	for (int i = 0; i < quantity; i++)
	{
		storm();
		print();
	}

	return 0;
}

