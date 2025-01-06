//스마트 포인터 사용을 위한 헤더 추가
#include <memory>
#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define new new
#endif

class Resource
{
public:
	Resource()
	{
		std::cout << "생성자 호출\n";
	}

	~Resource()
	{
		std::cout << "소멸자 호출\n";
	}

	void Use()
	{
		std::cout << "자원 사용\n";
	}
private:
};

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(155);

	std::unique_ptr<Resource> resource = std::make_unique<Resource>();
	//Resource* resource = new Resource();

	resource->Use();

	{
		//소유권 이전
		std::unique_ptr<Resource> resource2 = std::move(resource);
		
		//resource->Use(); //move를 확정할 수 없음, 언제 사용이 안될지 모름
		resource2->Use();

		Resource& refResource = *resource2;
	}

	std::cout << "테스트\n";

	//Raw 포인터 get
	//Resource* rawPointer = resource2.get(); //메모리 주소 반환
	//rawPointer->Use();

	//delete rawPointer;
	//_free_dbg(block, _UNKNOWN_BLOCK); => 이러한 중단점 명령 실행이 발생하면, 곧 delete 중복 호출이란 의미
}