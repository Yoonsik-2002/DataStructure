#include <stdio.h>

typedef struct {
	int id;
	char name[20]; // ���ڿ��� �����ϴ� �迭 name. c���� ���ڸ� �����ϴ� �ڷ���(char)�� ������ ���ڿ��� �����ϴ� �ڷ����� ���� ���� �ʴ�. �׷��Ƿ�, ���ڿ��� �����ϱ� ���ؼ��� �迭�� �̿��Ѵ�. �̶� ���ڿ��� ���������� /0�� ����ȴ�. �̴� ���ڿ��� ���� ��Ÿ����. ex) yoonsik/0
	float score;
}example; // example Ÿ���� ����ü

void over40(example* a, int n); // �Լ� ����(�Լ� ����) ���ϰ��� ���� over40 �Լ�
example find_max(example* a, int n); // �Լ� ����(�Լ� ����) exsample Ÿ���� ���ϰ��� �ִ� find_max �Լ�

void main()
{
	example onep, exmember[20]; // ����ü Ÿ�� example�� �����Ͽ��� ������ onep, exmember[i] ���� ����ü�� �� ��������� (.) �����ڸ� �̿��Ͽ� ������ �� �ִ�. 
	int i, n;

	printf("�������� ���� �Է� : ");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++) {
		printf("�����͸� �Է��ϼ��� : ");
		scanf_s("%d %s %f", &exmember[i].id, exmember[i].name, &exmember[i].score);
	}

	// �Լ� ȣ�� -
	over40(exmember, n); // ���� 4.0�� �Ѵ� �л��� id�� name�� ����ϴ� �Լ� 
	onep = find_max(exmember, n); // ������ �ְ�� ���� �л��� id, name, score�� ����ϴ� �Լ� | �Լ� find_max ���� ������ a[higest_index] �� �޴� example Ÿ���� ���� onep

	printf("Information of highest score students = %d : %s : %.2lf", onep.id, onep.name, onep.score);
}

// �Լ� ���� - 
void over40(example a[], int n) // �迭 exmember[]�� �޴� �Ű����� �迭 a[]
{
	int k;
	for (k = 0; k < n; k++) {
		if (a[k].score > 4.0)
			printf("%d -- %s", a[k].id, a[k].name);
	}
}

example find_max(example a[], int n)  // �迭 exmember[]�� �޴� �Ű����� �迭 a[]
{
	int k, highest_index = 0;
	for (k = 0; k < n; k++) {
		if (a[k].score > a[highest_index].score) 
			k = highest_index;
	}
	return a[highest_index];
}