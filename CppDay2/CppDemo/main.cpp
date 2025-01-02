#include<iostream>//확장자가 없는 파일임

int main()
{
	std::cout << "Hello"; //<< 연산자 오버로딩

	//문자열
	char name[20];
	const char* testString = "JUN";
	int length = strlen(testString);
	//자료형의 문자열은 없음
	//컴퓨터는 시작주소와 크기로만 계산함
	//문자열은 크기를 모름? -> 그래서 strlen()함수는 배열에 마지막에 붙는 '\0'을 찾음
	//"abc\0def"하면 strlen 함수는 abc까지만 읽음
	char* testString = new char[200];
	delete[] testString; //실수해도 요즘 컴파일러는 알아서 바꿔줌

	//cpp는 실행파일을 만들고 나면 호환이 안됨
}