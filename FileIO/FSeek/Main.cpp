#include <iostream>
#include <fstream>

int main()
{
	////텍스트 문자열
	//const char* stringValue = "id: 10 name: seyunjang balance: 1000000";
	//
	////문자열에서 특정 값 가져오기
	//int id = 0;
	//char name[256];
	//int balance = 0;
	//sscanf_s(stringValue, "id: %d name: %s balance:: %d", &id, name, 256, &balance);

	//std::cout << "id: " << id << "\n";
	//std::cout << "name: " << name << "\n";
	//std::cout << "balance: " << balance << "\n";
	//----------------------------------------------------------------------------
	// 데이터 쓰기
	int id = 10;
	const char* name = "ronniejang";
	int balance = 50000000;

	//문자열로 만들기
	//저장할 버퍼
	char data[1024] = {};
	snprintf(data, 1024, "id: %d name: %s balance: %d", id, name, balance);

	//테스트 출력
	//std::cout << data << "\n";
	//----------------------------------------------------------------
	////파일로 생성
	//FILE* file = nullptr;
	//fopen_s(&file, "AccountData.txt", "wb");
	//size_t length = strlen(data);
	//if (file != nullptr)
	//{
	//	//fwrite(data, 1024, 1, file);
	//	fwrite(data, length, 1, file);
	//	fclose(file);
	//}
	//-------------------------------------------------------------------------
	//읽기
	FILE* file = nullptr;
	fopen_s(&file, "Account.txt", "rb");
	if (file != nullptr)
	{
		char total[2048] = {};
		char buffer[1024];
		
		while (!feof(file))
		{
			fgets(buffer, 1024, file);
			//std::cout << buffer;

			//문자열 합치기
			strcat_s(total, buffer);
		}
		std::cout << total;

		//값 가져오기
		int id1 = 0;
		char namebuffer[256] = {};
		int balance1 = 0;

		//%d: decimal, %f: float, %s: string, %c: char
		sscanf_s(total, "id: %d name: %s balance: %d", &id, namebuffer, 256, &balance1);
		
		std::cin.get();
	}
	//-------------------------------------------------------------------------
	//std::ofstream output;
	//std::ifstream input;

	//FILE* file = nullptr;

	//fopen_s(&file, "Test.txt", "rt");

	////예외 처리
	//if (file != nullptr)
	//{
	//	//버퍼
	//	char buffer[256];

	//	//임의 접근
	//	//처음에서 10바이트 이동
	//	fseek(file, 10, SEEK_SET);

	//	while (!feof(file))
	//	{
	//		//데이터 읽기
	//		fgets(buffer, 256, file);

	//		//출력
	//		std::cout << buffer;
	//	}

	//	//파일 닫기
	//	fclose(file);
	//}
}