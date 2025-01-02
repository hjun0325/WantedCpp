#include<iostream>

//void TestFunction(char string[]) //배열을 넘길때는 주소를 같이넘기든 아니면 보통 포인터로 넘겨야 함?
//{
//	//size_t length = strlen(string);
//	int count = sizeof(string) / sizeof(string[0]);
//	std::cout << "count: " << count << "\n";
//}

//진입점(Entry Point)
int main()
{
	////auto testString = "Hello";
	//const char* testString = "Hello";
	//char charArray[] = "Hello";

	////동적할당
	////long long ->__int64 같은 타입
	//size_t length = strlen("hongjun") + 1; //typedef
	//char* name = new char[length];
	//strcpy_s(name, length, "hongjun");

	////테스트 출력
	//std::cout << testString << "\n";
	//std::cout << charArray << "\n";
	//std::cout << name << "\n";
	//
	//delete[] name;
//------------------------------------------------------
	//동적배열 vector / HashTable
	//검색.
	// 
	//문자
	char charactor = 'a';

	//문자열
	char charArray[] = "hel\0lo";

	//auto rawString = "hello";
	const char* rawString = "Hello c++";
	//const char* rawString = charArray;

	std::cout << rawString << *rawString <<std::endl;

	int length = 0;
	while (1)
	{
		if (rawString[length] == '\0')
		{
			break;
		}
		++length;
	}

	std::cout << length << std::endl;

	//함수로 길이 구하기
	size_t length1 = strlen(rawString);

	std::cout << length1 << std::endl;

	//힙 - 자유메모리 - 책임
	char* heapString = new char[length1 + 1];

	//문자열 복사
	//strcpy_s(heapString, length1 + 1, rawString);

	//메모리 복사
	memcpy(heapString, rawString, sizeof(char) * (length + 1));
	//heapString[length] = '\0';

	//concaternate
	//strcat_s(); //문자열 더하기 성능 면으로 좋은 것은 아님

	std::cout << heapString << std::endl;
	std::cout << charArray[1] << "\n";
	std::cout << *(rawString + 1) << "\n";

	std::cout << sizeof(*rawString) << "\n";

	delete[] heapString;

	//의미는 없음
	std::cin.get();
}