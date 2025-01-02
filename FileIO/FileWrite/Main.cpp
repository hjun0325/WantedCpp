#include <iostream>

int main()
{
	//파일에 추가할 문자열
	const char* message = "C 표준 라이브러리로 생성한 텍스트";

	//파일 스트림 객체 선언
	FILE* file = nullptr;

	//파일 열기
	fopen_s(&file, "Test.txt", "wt");

	//파일 쓰기
	if (file != nullptr)
	{
		//원하는 값 쓰기
		fputs(message, file);
		
		//파일 닫기
		fclose(file);
	}
}