#include <iostream>

class CTextBlock {
public:
    CTextBlock(char* a)
    {
        this->pText = a;
    }
    char& operator[](std::size_t position) const
    {
        return pText[position];
    } //상수성 위반 가능성 있음 

    char* pText;
};

class MyClass {
public:
    const int value;  // 객체마다 다른 런타임 상수
    MyClass(int v) : value(v) {}  // 생성자를 통해 설정

    static const int a;
    static const int b = 2;
    static const bool s = true;
    int arr[b];
    static const float pi;
};

const float MyClass::pi = 3.14f;
const int MyClass::a = 1;
const int c = 3;

int main()
{
    //std::cout << myClass1.value << myClass2.value;
    int arr[c];
    arr[1] = 1;
    std::cout << arr[1];
    const int* ptr = &MyClass::a;
    std::cout << ptr << std::endl;
    std::cout << &MyClass::b;
    char* str = new char[6]; // "Hello" + '\0' 저장 공간 확보
    char a = 'a';
    const CTextBlock cctb(&a); //상수 객체를 선언한다.
    char* pc = &cctb[0]; //상수 버전의 operator[]를 호출하여 cctb의
    //내부 데이터에 대한 포인터를 얻는다.
    *pc = 'j'; //cctb는 이제 "jello"하는 값을 갖는다.
    std::cout << *(cctb.pText);
}