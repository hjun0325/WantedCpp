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
    } //����� ���� ���ɼ� ���� 

    char* pText;
};

class MyClass {
public:
    const int value;  // ��ü���� �ٸ� ��Ÿ�� ���
    MyClass(int v) : value(v) {}  // �����ڸ� ���� ����

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
    char* str = new char[6]; // "Hello" + '\0' ���� ���� Ȯ��
    char a = 'a';
    const CTextBlock cctb(&a); //��� ��ü�� �����Ѵ�.
    char* pc = &cctb[0]; //��� ������ operator[]�� ȣ���Ͽ� cctb��
    //���� �����Ϳ� ���� �����͸� ��´�.
    *pc = 'j'; //cctb�� ���� "jello"�ϴ� ���� ���´�.
    std::cout << *(cctb.pText);
}