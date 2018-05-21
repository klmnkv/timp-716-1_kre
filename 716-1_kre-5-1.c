#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    int value;
    struct node *left;
    struct node *right;
} node;

typedef struct root
{
    node *head;
}root;

root *InicHead(node *h)
{
    root *tmp = malloc(sizeof(root));
    tmp -> head = h;
    return tmp;
}

node *InicNode(int a, int b)
{
    node *tmp = malloc(sizeof(node));
    tmp -> key = a;
    tmp -> value = b;
    tmp -> left = NULL;
    tmp -> right = NULL;
    return tmp;
}

void Add(int a, int b, root *h)
{
    int tmpKey = h -> head -> key;
    node *tmp = h -> head;

    node *list = malloc(sizeof(node));
    list -> key = a;
    list -> value = b;
    list -> left = NULL;
    list -> right = NULL;

    for (;;)
    {
        if (tmpKey > a)
        {
            if (tmp -> left == NULL)
            {
                tmp -> left = list;
                break;
            }
            tmp = tmp -> left;
            tmpKey = tmp -> key;
            continue;
        }

        if (tmpKey < a)
        {
            if (tmp -> right == NULL)
            {
                tmp -> right = list;
                break;
            }
            tmp = tmp -> right;
            tmpKey = tmp -> key;
        }
    }
}

void SearchNode(int a, root *h)
{
    int level = 0;
    int tmpKey = h -> head -> key;
    node *tmp = h -> head;

    for (;;)
    {
        if (tmpKey == a)
        {
            printf("%d ", level);
            printf("%d\n", tmp -> value);
            break;
        }

        if (tmpKey > a)
        {
            tmp = tmp -> left;
            if (tmp == NULL) {printf("%d\n", -1); break;}
            tmpKey = tmp -> key;
            level++;
            continue;
        }

        if (tmpKey < a)
        {
            tmp = tmp -> right;
            if (tmp == NULL) {printf("%d\n", -1); break;}
            tmpKey = tmp -> key;
            level++;
            continue;
        }
    }
}

void DeleteTree(root *h)
{
    node *tmp = NULL;
    node *prev = NULL;

    for (;;)
    {
        prev = NULL;
        tmp = h -> head;

        while (tmp -> left != NULL)
        {
            prev = tmp;
            tmp = tmp -> left;
        }

        while (tmp -> right != NULL)
        {
            prev = tmp;
            tmp = tmp -> right;
        }

        if (prev == NULL)
        {
            free(tmp);
            free(h);
            break;
        }

        if (prev -> left == tmp)
        {
            free(tmp);
            prev -> left = NULL;
            continue;
        }

        if (prev -> right == tmp)
        {
            free(tmp);
            prev -> right = NULL;
            continue;
        }
    }
}

int main()
{
    int kol = 0, a = 0, b = 0, i = 1;
    root *start = NULL;

    scanf("%d", &kol);

    for (i; i <= kol; i++)
    {
        scanf("%d %d", &a, &b);
        if (i == 1) start = InicHead(InicNode(a,b));
        else
        {
            Add(a, b, start);
        }
    }

    for (i = 1; i <= 3; i++)
    {
        scanf("%d", &a);
        SearchNode(a, start);
    }

    DeleteTree(start);
    start = NULL;

    return 0;
}

