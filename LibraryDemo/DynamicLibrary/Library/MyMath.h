#pragma once

#ifdef BUILD_DLL
#define MATH_DLL __declspec(dllexport)
#else
#define MATH_DLL __declspec(dllimport)
#endif

// DLL 라이브러리용 클래스 제작.
// Dynamic Linking Library.
// Dynamic -> Runtime -> 실행 중에.
// __declspec(dllexport) -> 외부 공개용으로 설정 MSCompiler.
// __declspec(dllexport) / __declspec(dllimport).
// 외부 공개용으로 설정하면 .lib 파일이 출력 경로에 생김 -> 외부 공개된게 있으니 탐색할 것이 생겨서.
// .lib는 지도 / .dll은 실제 맵
class MATH_DLL Math
{
public:
	static int Add(int a, int b);
	static int Substract(int a, int b);
	static int Multiply(int a, int b);
	static int Divide(int a, int b);
};