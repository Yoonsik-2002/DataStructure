#include <stdio.h>

typedef struct {
	int id;
	char name[20]; // 문자열을 저장하는 배열 name. c언어에는 문자를 저장하는 자료형(char)은 있지만 문자열을 저장하는 자료형은 따로 있지 않다. 그러므로, 문자열을 저장하기 위해서는 배열을 이용한다. 이때 문자열의 마지막에는 /0이 저장된다. 이는 문자열이 끝을 나타낸다. ex) yoonsik/0
	float score;
}example; // example 타입의 구조체

void over40(example* a, int n); // 함수 원형(함수 선언) 리턴값이 없는 over40 함수
example find_max(example* a, int n); // 함수 원형(함수 선언) exsample 타입의 리턴값이 있는 find_max 함수

void main()
{
	example onep, exmember[20]; // 구조체 타입 example로 선언하였기 때문에 onep, exmember[i] 값을 구조체의 각 멤버변수에 (.) 연산자를 이용하여 배정할 수 있다. 
	int i, n;

	printf("데이터의 개수 입력 : ");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++) {
		printf("데이터를 입력하세요 : ");
		scanf_s("%d %s %f", &exmember[i].id, exmember[i].name, &exmember[i].score);
	}

	// 함수 호출 -
	over40(exmember, n); // 학점 4.0을 넘는 학생의 id와 name을 출력하는 함수 
	onep = find_max(exmember, n); // 학점이 최고로 높은 학생의 id, name, score을 출력하는 함수 | 함수 find_max 에서 리턴한 a[higest_index] 을 받는 example 타입의 변수 onep

	printf("Information of highest score students = %d : %s : %.2lf", onep.id, onep.name, onep.score);
}

// 함수 정의 - 
void over40(example a[], int n) // 배열 exmember[]을 받는 매개변수 배열 a[]
{
	int k;
	for (k = 0; k < n; k++) {
		if (a[k].score > 4.0)
			printf("%d -- %s", a[k].id, a[k].name);
	}
}

example find_max(example a[], int n)  // 배열 exmember[]을 받는 매개변수 배열 a[]
{
	int k, highest_index = 0;
	for (k = 0; k < n; k++) {
		if (a[k].score > a[highest_index].score) 
			k = highest_index;
	}
	return a[highest_index];
}