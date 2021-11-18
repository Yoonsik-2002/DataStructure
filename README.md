# DataStructure

**기초지식**

- main 함수란? : C/C++ 프로그램의 시작점으로, 모든 프로그램은 하나의 시작점만 가지고 있어야 하므로 main 함수는 언제나 *하나만* 존재해야 한다. 만약, mian 함수가 없다면 프로그램을 시작할 수 없다.

- void의 의미 : 리턴(return)값이 없는 자료형을 뜻한다. C언어 기본 구조에서 return은 함수 종료 후 값을 돌려주는 역할을 한다. 
- main 함수의 표준적인 사용방법
  - 매개변수가 없는 main 함수
    
    void로 함수의 매개변수가 없음을 명시한다.
    
    ```C
    int main (void) {
      return 0;
    }
    ```
  
  - void main() 함수와 int main() 함수
  
    컴파일러 입장에서는 개발자가 void main 함수를 사용하여 컴파일 할 때나 int main 함수를 사용하여 컴파일 할 때나  내부적으로 다르게 처리하는게 없다. 
    
    즉 void main 이라고 적으면 컴파일러는 int main 함수를 적은 것과 동일하게 처리한다. 
    
    void main 함수는 함수 맨 마지막에 return 0 을 하지 않아도 된다는 점에서 main 함수보다 편리하다는 장점이 있다. 하지만, 컴파일러가 지원하지 않는 경우도 있기 때문에 int main 사용을 권장한다. 
    
    ```C
    void main()
    {
    
    }
    ```
    
    ```C
    int main()
    {
    
      return 0;
    }
    ```
    
- 지역변수 

   **한 지역 내에서만** 사용할 수 있는 변수이다. 여기서 지역이란, 중괄호에 의해 만들어지는 영역을 뜻한다. main 함수 내의 변수들도 다 지역변수이다.

  따라서 main 함수 내의 변수들은 다른 함수 내에서 사용할 수 없다.

  main 함수에서 사용하던 변수를 다른 함수에서도 쓰려면 전달인자로 넘겨주거나, 전역변수로 선언한 후 사용해야 한다.
  
  [예시코드]
  
  ```C
  #include <stdio.h>
  int functionTest()
  {
    int temp = 5;
    temp += result;
    
    return temp;
  }
  
  int main()
  {
    int result = 10;
    printf("result 결과 : %d", functionTest());
    
    return 0;
  }
  ```
  
  위 코드를 실행해 보면, functionTest 함수 내부에 result가 선언되어 있지 않았다며 에러가 발생한다. 위와 같이 main 함수에서 선언된 변수는 functionTest 같은 다른 함수에서는 사용할 수 없다. 반대의 경우도 마찬가지.
  
  지역변수들은 해당 지역을 벗어나면 소멸하게 된다.
  
- 전역변수

  전역변수는 지역변수와 반대로 **어느 지역에서나 사용할 수 있는 변수** 이다. 괄호 안에 쓴 변수가 지역변수였다면, 괄호 밖에 쓴 변수는 전역변수이다. 전역변수로 선언하면 main 함수이든, functionTest 함수이든 변수 사용이 가능하다.
  
  이 전역변수 는 프로그램의 시작과 동시에 메모리 공간에 할당되어서 프로그램이 종료될 때 까지 존재한다. 또한 지역변수와는 다르게 별도의 값으로 초기화하지 않으면 0으로 초기화 된다.
  
  [예시코드]
  
  ```C
  #include <stdio.h>
  
  int global = 10;
  
  void globalTest()
  {
    global += 5;
    printf("함수에서 전역 변수 : %d\n", global);
  }
  
  int main()
  {
    int result = 10;
    printf("전역변수 : %d\n", global);
    printf("지역변수 : %d\n", result);
    
    globalTest();
    
    return 0;
  }
  ```
  
  위와 같이 전역변수는 main 에서도, globalTest 와 같은 함수에서도 접근과 사용이 가능하다. 하지만 전역변수를 많이 사용하게 되면, 코드가 길어질 수록 어떤 함수에서 전역변수의 값을 바꾸는지 알기 어려워지기 때문에 추후에 프로그램을 유지보수 하는데 어려움이 있을 수 있다.
  
  되도록이면 전역변수의 사용은 줄이고, 지역변수를 사용하는 것이 좋다.  또한 지역변수와 전역변수 중에 이름이 같은 변수가 있는 경우에는 지역변수를 우선적으로 접근한다.
  
**3.2 구조체**

구조체는 우리 일상의 레코드 데이터를 위하여 마련된 C 프로그램의 자료구조로, 다양한 자료형(type)의 연관된 자료를 묶어 새로운 자료형을 만들어 준다. 

- 구조체의 선언
  - 기본적인 형태 
  
    ```c
    struct member {
      int id;
      char name[20];
      float score;
    };
    ```
    
    키워드 struct를 이용하여 member를 구조체 태그 이름으로 정하여 중괄호 사이에 연관된 자료를 선언하면  **struct member** 라는 새로운 타입이 생기게 된다.
    
  - 형 정의문(typedef)을 이용한 구조체의 선언
    
    ```c
    typedef struct member {
      int id;
      char name[20];
      float score;
    } example;
    ```
    
    typedef 는 타입을 정의하는 역할을 한다. 다음 선언문에 의하여 struct member 타입은 example로도 정의되어 둘 다 같은 구조체 타입으로 사용할 수 있게 된다.
    
    이 경우, example을 구조체 타입명으로 사용한다면 구조체 태그이름 member는 생략할 수 있다.
    
    - 이때, 멤버변수 id, name, score은 필드가 되고 이 필드에 할당되는 데이터가 레코드가 된다.
    
    - 레코드는 멤버 연산자(.)를 통해 멤버변수에 배정된다.
    
  - 구조체를 프로그램에서 변수로 사용
  
    ```c
    example onep, exmember[20];
    ```
    
    위의 선언에 의하여 1개의 레코드를 저장할 수 있는 변수 onep와 20개의 레코드를 저장할 수 있는 example 타입의 배열 exmember을 생성
    
  - 구조체의 각 멤버변수에 값을 배정하는 배정문
    
    ```c
    onep.id = 0130;
    strcpy(onep.name, "CHO YOON SIK");
    onep.score = 4.5;
    ```
  
  - 구조체배열 exmember안의 데이터중 성적이 4.0 이상인 학생의 id를 출력하는 문장

    ```c
    for (k = 0; k < 20; k++) {
      if (exmember[k].score >=  4.0)
        printf("%d\n", exmember[k].id);
    }
    ```
    
    
 
