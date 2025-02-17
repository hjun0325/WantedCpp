#include <iostream>
#include "Location2D.h"
#include "Queue.h"

// Sleep(밀리 세컨드)
#include <Windows.h>

//// 맵 데이터 선언.
//// 작은 맵.
//const size_t MAZE_SIZE = 6;
//// 0: 이동 가능.
//// 1: 벽. 이동 불가.
//// s: 시작 위치.
//// e: 목표 위치.
//char map[MAZE_SIZE][MAZE_SIZE] =
//{
//	{'1','1','1','1','1','1'},
//	{'s','0','1','0','0','1'},
//	{'1','0','0','0','1','1'},
//	{'1','0','1','0','1','1'},
//	{'1','0','1','0','0','e'},
//	{'1','1','1','1','1','1'}
//};

//const size_t MAZE_SIZE = 6;
//char map[MAZE_SIZE][MAZE_SIZE] =
//{
//	{'1','1','1','1','1','1'},
//	{'s','0','1','0','0','0'},
//	{'1','0','1','0','1','0'},
//	{'1','0','0','0','0','0'},
//	{'1','0','1','1','0','1'},
//	{'1','1','1','e','0','1'}
//};

const size_t MAZE_SIZE = 20;
char map[MAZE_SIZE][MAZE_SIZE] =
{
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '1', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
    {'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
    {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1'},
    {'s', '0', '1', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1'},
    {'1', '0', '1', '0', '0', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '1', '1', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1'},
    {'1', '0', '0', '0', '1', '0', '1', '0', '1', '0', '1', '0', '1', '0', '0', '0', '1'},
    {'1', '1', '1', '1', '1', '0', '1', '0', '1', '1', '1', '0', '1', '1', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
    {'1', '0', '1', '1', '1', '1', '1', '1', '1', '0', '1', '1', '1', '0', '1', '0', '1'},
    {'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', 'e'},
    {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

// 이동하려는 위치가 유효한 위치인지 확인.
bool IsVaildLocation(int row, int column)
{
	// 맵의 범위를 벗어났는지 확인.
	// 벗어 났으면 오류.
	if (row >= MAZE_SIZE || column >= MAZE_SIZE)
	{
		return false;
	}

	if (row < 0 || column < 0)
	{
		return false;
	}

	// 유효성 확인.
	// 이동하려는 위치가 0(이동 가능)이거나 e(목표 위치)라면 이동 가능 반환.
	return map[row][column] == '0' || map[row][column] == 'e';
}

// 화면 지우는 함수.
void ClearScreen()
{
	CONSOLE_CURSOR_INFO info = { };
	info.dwSize = 1;
	info.bVisible = FALSE;

	// 콘솔 제어를 위한 핸들(포인터) 가져오기.
	static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

	// 커서 가리기.
	SetConsoleCursorInfo(handle, &info);

	// 화면 좌표 옮기기.
	SetConsoleCursorPosition(handle, { 0,0 });
}

// 맵 출력 함수.
void PrintLocation(int row, int column, int delay)
{
	// 딜레이.
	Sleep(delay);

	// 화면 지우기.
	ClearScreen();

	for (int ix = 0;ix < MAZE_SIZE;++ix)
	{
		for (int jx = 0;jx < MAZE_SIZE;++jx)
		{
			// 현재 방문 중인 위치를 특정 문자로 출력.
			if (ix == row && jx == column)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
				std::cout << "★ ";
				continue;
			}

			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);

			// 출력.
			std::cout << map[ix][jx] << " ";
		}

		std::cout << "\n";
	}
}

int main()
{
	// 시작 위치 검색.
	int startRow = 0;
	int startColumn = 0;

	// 미로의 시작 지점 검색.
	for (int ix = 0;ix < MAZE_SIZE;++ix)
	{
		for (int jx = 0;jx < MAZE_SIZE;++jx)
		{
			// 출력.
			//std::cout << map[ix][jx] << " ";

			// 시작 지점이라면 위치 저장.
			if (map[ix][jx] == 's')
			{
				startRow = ix;
				startColumn = jx;
			}
		}

		std::cout << "\n";
	}

	// 시작 지점을 탐색하기 위해 큐에 삽입.
	Queue<Location2D> queue;
	queue.Enqueue(Location2D(startRow, startColumn));

	// 미로 탐색.
	while (!queue.IsEmpty())
	{
		// 큐 최상위에 있는 위치 반환
		Location2D current;
		queue.Dequeue(current);

		int row = current.row;
		int column = current.column;
		
		// 탐색한 위치 출력.
		//std::cout << "(" << row << "," << column << ")";
		//std::cout << "(" << column << "," << row << ")";

		PrintLocation(row, column, 10);

		// 도착했는지 확인.
		if (map[row][column] == 'e')
		{
			SetConsoleTextAttribute(
				GetStdHandle(STD_OUTPUT_HANDLE),
				FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
			);
			std::cout << "\n미로 탐색 성공\n";
			std::cin.get();
			return 0;
		}

		// 방문한 곳은 다른 문자로 설정.
		map[row][column] = '.';

		// 상/하/좌/우 위치 중 이동 가능한 위치를 큐에 삽입
		if (IsVaildLocation(row - 1, column))
		{
			queue.Enqueue(Location2D(row - 1, column));
		}
		if (IsVaildLocation(row + 1, column))
		{
			queue.Enqueue(Location2D(row + 1, column));
		}
		if (IsVaildLocation(row, column - 1))
		{
			queue.Enqueue(Location2D(row, column - 1));
		}
		if (IsVaildLocation(row, column + 1))
		{
			queue.Enqueue(Location2D(row, column + 1));
		}
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	std::cout << "미로 탐색 실패\n";
	std::cin.get();
}