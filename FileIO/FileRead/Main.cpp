#include <iostream>

int main()
{
	//읽어올 저장소
	char buffer[256];

	//파일 스트림 객체 선언
	FILE* file = nullptr;

	//파일 열기
	fopen_s(&file, "Test.txt", "rt");

	//파일 읽기
	if (file != nullptr)
	{
		//버퍼에 내용 읽어들이기
		while (/*true*/!feof(file))
		{
			/*if (fgets(buffer, 5, file) == nullptr)
			{
				break;
			}*/

			fgets(buffer, 5, file);

			//출력
			std::cout << buffer;
		}
		//파일 닫기
		fclose(file);
	}
}