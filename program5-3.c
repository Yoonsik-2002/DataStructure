/*#include <stdio.h>
#define MAX_STACK_SIZE 10

typedef struct { 
	int key;
	char grade;
} element;
int top = -1;
element stack[MAX_STACK_SIZE];
void push(element data);
element pop();
void main()
{
	element data;
	int i, n, cond = 1;

	while (cond) {
		printf("������ �Է�");
		scanf_s("%d %c", &data.key, &data.grade);
		if (data.key != 0) {
			push(data);
		}
		printf("���ÿ� �����͸� ��� �Է��Ͻðڽ��ϱ�? (1/0) ");
		scanf_s("%d", &cond);
	}

	printf("���ÿ��� �� ���� �����Ͱ� �ʿ��ϼ���?");
	scanf_s("%d", &n);

	printf("���ÿ��� ������ ������: \n");
	for (i = 0; i < n; i++) {
		data = pop();
		printf("%d\t%c\n", data.key, data.grade);
	}
}

void push(element item)
{
	if (top >= MAX_STACK_SIZE - 1)
		printf("STACK is overflow !!!\n");
	else {
		top++;
		stack[top] = item;
	}
}

element pop()
{
	if (top == -1) {
		printf("Stack is empty!!!");
		exit(1);
	}
	else return stack[top--];
}*/