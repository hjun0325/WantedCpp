#pragma once

// 작성자 : 신지령
// - 경고를 일부러 무시 시켰기 떄문에 문제가 된다면 고쳐야 함.
// @refactor: 경고를 일부러 무시 시켰기 떄문에 문제가 된다면 고쳐야 함.
#pragma warning(disable: 4172)

#include "Core.h"

// 상속 관계에 있는 클래스 간의
// 동적(실행중에) 형변환을 빠르게 하기 위해 사용하는 클래스.
// RunTime-Type-Information.
class ENGINE_API RTTI
{
public:
	virtual const size_t& TypeIdInstance() const = 0;

	virtual bool Is(const size_t id) const
	{
		return false;
	}

	template<typename T>
	T* As()
	{
		if (Is(T::TypeIdClass()))
		{
			return (T*)this;
		}

		return nullptr;
	}

	template<typename T>
	const T* As() const
	{
		if (Is(T::TypeIdClass()))
		{
			return (T*)this;
		}

		return nullptr;
	}
};

//  런타임의 타입 정보를 알고 싶어서, 하는 것, 원래라면 다이나믹 캐스팅으로 업캐스팅이나 다운캐스팅을 해서 타입이 맞는 지 확인. 다이나믹 캐스팅이 느려서 이것을 사용함
// static int나 함수같은 경우, 메모리 중에서 코드 데이터 영역에 들어감, 
#define RTTI_DECLARATIONS(Type, ParentType)												\
public:																					\
	using Super = ParentType;															\
	virtual const size_t& TypeIdInstance() const { return Type::TypeIdClass(); }		\
	static const size_t TypeIdClass()													\
	{																					\
		static int runTimeTypeId = 0;													\
		return reinterpret_cast<size_t>(&runTimeTypeId);								\
	}																					\
	virtual bool Is(const size_t id) const												\
	{																					\
		if (id == TypeIdClass())														\
		{																				\
			return true;																\
		}																				\
		else																			\
		{																				\
			return Super::Is(id);													\
		}																				\
	}