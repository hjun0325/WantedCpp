#include <iostream>

int main()
{
	//�о�� �����
	char buffer[256];

	//���� ��Ʈ�� ��ü ����
	FILE* file = nullptr;

	//���� ����
	fopen_s(&file, "Test.txt", "rt");

	//���� �б�
	if (file != nullptr)
	{
		//���ۿ� ���� �о���̱�
		while (/*true*/!feof(file))
		{
			/*if (fgets(buffer, 5, file) == nullptr)
			{
				break;
			}*/

			fgets(buffer, 5, file);

			//���
			std::cout << buffer;
		}
		//���� �ݱ�
		fclose(file);
	}
}