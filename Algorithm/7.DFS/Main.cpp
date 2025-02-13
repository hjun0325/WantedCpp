#include <stack>
#include <vector>
#include <cstring>
#include <iostream>

// �̷� Ž���� ����� ����ü.
struct Location2D
{
	Location2D(int row = 0, int col = 0)
		: row(row), col(col)
	{

	}

	// ��.
	int row;
	// ��.
	int col;
};

// �� �迭.
int mapSize = 0;
std::vector<std::vector<char>> map;
//{
//	{ '1','1','1','1','1','1' },
//	{ 'e','0','1','0','0','1' },
//	{ '1','0','0','0','1','1' },
//	{ '1','0','1','0','1','1' },
//	{ '1','0','1','0','0','x' },
//	{ '1','1','1','1','1','1' }
//};

// �̵� ���� ���� �Ǵ� �Լ�.
bool IsValidLocation(int row, int col)
{
	if (row < 0 || row >= mapSize || col < 0 || col >= mapSize)
	{
		return false;
	}

	return map[row][col] == '0' || map[row][col] == 'x';
}

// ���� ���� �˻� �Լ�.
void FindStartLocation(int& row, int& col)
{
	for (int ix = 0;ix < mapSize;++ix)
	{
		for (int jx = 0;jx < mapSize;++jx)
		{
			// �� ���.
			std::cout << map[ix][jx] << " ";

			// ���� ������ ��Ÿ���� ���� �˻�.
			if (map[ix][jx] == 'e')
			{
				row = ix;
				col = jx;
				//return;
			}
		}

		std::cout << "\n";
	}
}

// �̷� Ż�� �Լ�.
void EscapeMaze()
{
	// �� ũ�� Ȯ��.
	mapSize = (int)map.size();

	// ��ġ ������ ���� ���� ����.
	int row = 0;
	int col = 0;

	// Ž�� ������ ���� ���� ��ġ ã��.
	FindStartLocation(row, col);

	// ���� ����.
	std::stack<Location2D> stack;

	// Ž�� ������ ���� ���� ��ġ ���ÿ� ����
	stack.push(Location2D(row, col));

	// �̷� Ž��.
	while (!stack.empty())
	{
		// ���� ��ġ ��ȯ.
		Location2D current = stack.top();
		stack.pop();

		// Ž�� ��ġ ���.
		std::cout << "(" << current.row << "," << current.col << ") ";

		row = current.row;
		col = current.col;

		// Ż�� ���� Ȯ��.
		if (map[row][col] == 'x')
		{
			std::cout << "\n�̷� Ž�� ����\n";
			return;
		}

		// Ž�� ����.
		// �湮�� ���� ��ġ�� ��湮 ������ ���� ǥ��.
		map[row][col] = '.';

		// ��/��/��/�� ��ġ �� �̵� ������ ��ġ�� ���ÿ� ����.
		if (IsValidLocation(current.row - 1, current.col))
		{
			stack.push(Location2D(current.row - 1, current.col));
		}
		if (IsValidLocation(current.row + 1, current.col))
		{
			stack.push(Location2D(current.row + 1, current.col));
		}
		if (IsValidLocation(current.row, current.col - 1))
		{
			stack.push(Location2D(current.row, current.col - 1));
		}
		if (IsValidLocation(current.row, current.col + 1))
		{
			stack.push(Location2D(current.row, current.col + 1));
		}
	}

	std::cout << "\n�̷� Ž�� ����\n";
}

// �� �ҷ����� �Լ�.
bool ParseMap(const char* path)
{
	// ���� ����.
	FILE* file = nullptr;
	fopen_s(&file, path, "r");
	if (file)
	{
		// ù�� �б�.
		char buffer[256];
		if (!fgets(buffer, 256, file))
		{
			fclose(file);
			return false;
		}

		// �� ũ�� ����.
		sscanf_s(buffer, "size %d", &mapSize);

		// �� ������ ������ ���� �ӽ� �迭 ����.
		std::vector<char> line;
		line.reserve(mapSize);

		// �� ������ �ؼ��� ���� ����.
		while (fgets(buffer, 256, file))
		{
			// ùĭ ó��.
			char* context = nullptr;
			char* splitString = strtok_s(buffer, ",", &context);
			if (splitString)
			{
				line.emplace_back(splitString[0]);
			}

			// ��° ���ʹ� ����.
			while (context)
			{
				splitString = strtok_s(nullptr, ",", &context);
				std::cout << int(*splitString);
				if (!splitString)
				{
					break;
				}


				line.emplace_back(splitString[0]);
			}
			
			// ó���� ���� �����͸� �ʿ� �߰�.
			map.emplace_back(line);
			line.clear();
		}

		fclose(file);
		return true;
	}

	return false;
}

// �� �ҷ����� �Լ�.
bool ParseMap2(const char* path)
{
	// ���� ����.
	FILE* file = nullptr;
	fopen_s(&file, path, "r");
	if (file)
	{
		char buffer[256];

		// ù�� �б�.
		if (!fgets(buffer, 256, file))
		{
			fclose(file);
			return false;
		}

		// �� ũ�� ����.
		sscanf_s(buffer, "size %d", &mapSize);

		// �� ������ ������ ���� �ӽ� �迭 ����.
		std::vector<char> line;
		line.reserve(mapSize);

		char* splitString;
		char* context = nullptr;

		while (true)
		{
			// �� �̻� ���� ���� ���� ���.
			if (fgets(buffer, 256, file) == nullptr)
			{
				break;
			}

			splitString = strtok_s(buffer, ",", &context);
			while (splitString != nullptr)
			{
				line.push_back(*splitString);
				splitString = strtok_s(nullptr, ",", &context);
			}

			/*int length = strlen(buffer);
			for (int ix = 0;ix < length;++ix)
			{
				if (buffer[ix] != ',')
				{
 					line.push_back(buffer[ix]);
				}
			}*/

			// ó���� ���� �����͸� �ʿ� �߰�.
			map.emplace_back(line);
			line.clear();
		}

		fclose(file);
		return true;
	}

	return false;
}

int main()
{
	// �� �ҷ�����.
	if (ParseMap2("../Assets/Map.txt"))
	{
		// �̷� Ž��.
		EscapeMaze();
	}

	std::cin.get();
}