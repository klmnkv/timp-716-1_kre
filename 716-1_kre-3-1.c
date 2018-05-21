
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node { // наша структура двусвязного списка 
	int value; 
	struct node *next;
	struct node *prev;
} node;
typedef node* list; 

int init(list *root) { // иницализация списка 
	*root = NULL; 
	return 1;
}

int destroy(list *root) { // удаление списка 
	
	while (*root != NULL) { // до тех пор, пока *root не пустой 
		*root = (*root)->next; // освобождать последовательно до тех пор, пока не дойдет до последней ячейки
		free(root); // освободить значение
	}
	return 1;
}


int isEmpty(list root) { // проверка элемента на пустоту 
	if (root) return 1;
	else return 0;
}

list find(list root, int value) { // поиск элемента 
		while (root != NULL){ // будет проверять до тез пор, пока root не пустое 
		if (root->value == value) return root; //как только root укажет на значение, возвращаем root 
		root = root->next; 
	}
	return NULL;
}

int deleteElement(list *root) {
	
	if (*root != NULL){ //проверка на пустоту 

		if (((*root)->prev != NULL) && ((*root)->next == NULL)) { // если предыдущая ячеейка не пустая, а следующая пустая
			(*root)->prev->next = NULL; 
		}
		if (((*root)->prev == NULL) && ((*root)->next != NULL)) { // если предыдущая ячейка пустая, а сладующая не пустая
			(*root)->next->prev = NULL;
			(*root) = (*root)->next;
		}
		if (((*root)->prev != NULL) && ((*root)->next != NULL)) { // если обе ячейки не пустые
			(*root)->prev->next = (*root)->next;
			(*root)->next->prev = (*root)->prev;
		}
		free(*root);
	}
	return 1;
}


int append(list *root, int value) // добавление элемента после текущего 
{
	if ((*root) == NULL){ // если *root пустой 
		list app = (list)malloc(sizeof(node)); // веделение памяти
		app->value = value; 
		app->next = NULL;
		app->prev = NULL;
		*root = app;
		return 1;
	}
	if ((*root)->next != NULL){ // если следующая ячейка не пустая 
		list app = (list)malloc(sizeof(node)); // выделение памяти 
		app->next = (*root)->next; 
		app->value = value;
		app->prev = *root;
		(*root)->next->prev = app;
		(*root)->next = app;
		return 1;
	}
	else{ //иначе если предыдущая ячейка не пустая
		list app = (list)malloc(sizeof(node)); // выделение памяти
		app->value = value;
		app->next = NULL;
		app->prev = *root;
		(*root)->next = app;
		return 1;
	}
}

int prepend(list *root, int value) // добавление элемента перед текущем 
{
	if ((*root) == NULL){ // аналогично (после текущего) 
		list pre = (list)malloc(sizeof(node));
		pre->next = NULL;
		pre->value = value;
		pre->prev = NULL;
		*root = pre;
		return 1;
	}
	if ((*root)->prev != NULL){
		list pre = (list)malloc(sizeof(node));
		pre->value = value;
		pre->prev = (*root)->prev;
		pre->next = *root;
		(*root)->prev->next = pre;
		(*root)->prev = pre;
		return 1;
	}
	else{
		list pre = (list)malloc(sizeof(node));
		pre->prev = NULL;
		pre->value = value;
		pre->next = *root;
		(*root)->prev = pre;
		(*root) = (*root)->prev;
		return 1;
	}
}

int print(list *root) // вывод элементов в прямом порядке через пробел
{
	list vivod = *root;
	while (vivod != NULL){
		printf("%d ", vivod->value);
		vivod = vivod->next;
	}
	printf("\n");
	return 1;
}

int main() {
	list head;
	init(&head);
	int i, x, n, k, m, a, b, c, d;
	//task 1
	scanf("%d", &n); // количество элементов
	//task2
	if (n > 0)	{ // считает элементы в прямом порядке
		scanf("%d", &x);
		append(&head, x);
	}
	list ewq = head;
	for (i = 1; i < n; i++){
		scanf("%d", &x);
		append(&ewq, x);
		ewq = ewq->next;
	}
	print(&head);
	//task 3
	scanf("%d", &k);
	if (k > n) printf("Think better \n"); // проверка на адекватность 
	else{
		if (k == 1) deleteElement(&head); // если выбран первый индекс, то удаляем голову 
		else{ // иначе, ищем искомый индекс, начиная с головы
			list ewq = head;
			for (i = 1; i < k; i++){
				ewq = ewq->next;
			}
			deleteElement(&ewq);
		}
	}
	print(&head);
	//task 4
	scanf("%d", &m);
	list del = find(head, m); // ищем значние 
	if (del == head) deleteElement(&head); // если искомое значние равно голове, то удаляем её 
	else deleteElement(&del); // иначе удаляем искомое значение 
	print(&head);
	//task 5
	scanf("%d%d", &a, &b);
	if (a > n) printf("seriously? \n"); // праверка на адекватность v.2
	else // 
	{
		list ewq = head;
		for (i = 1; i < a; i++){ // прогоняем 
			ewq = ewq->next;
		}
		append(&ewq, b);
	}
	print(&head); // выводим
	//task 6
	scanf("%d%d", &c, &d);
	if (c > n) printf("realy? \n"); // проверка на адекватность 
	if (c == 1) prepend(&head, d); // если элемент первый (голова) перед ним вставляем 
	else { // иначе прогоняем по каждому 
		list ewq = head;
		for (i = 1; i < c; i++){
			ewq = ewq->next;
		}
		prepend(&ewq, d); // вставляем 
	}
	print(&head); // выводим 
	return 0;
}



