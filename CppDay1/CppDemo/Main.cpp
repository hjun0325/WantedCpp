//전처리(Pre-Process)
//파일에 들어가서 파일을 열어주고 이 전처리 코드를 없앤다
#include<iostream> 
#include"Log.h"

//void Log(const char* message);
//매크로->치환
//#define Square(x) ((x)*(x))
#define FORCEINLINE __forceinline //getter, setter에서 자주 씀
FORCEINLINE int Square(int x) //좀 더 강하게 인라인 호출, 속도가 빨라지는 대신에 텍스트 용량을 먹음
{
	return x * x;
}


//진입점(Entry Point)
int main()
{
	//출력
	//std::cout << "Hello World\n";
	//Log("Hello World");

	std::cout << Square(10) << "\n";

	//의미 없읍 바로 종료되지 말라고 추가
	std::cin.get();
}