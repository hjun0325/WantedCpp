#pragma once

// �ۼ��� : ������
// - ����� �Ϻη� ���� ���ױ� ������ ������ �ȴٸ� ���ľ� ��.
// @refactor: ����� �Ϻη� ���� ���ױ� ������ ������ �ȴٸ� ���ľ� ��.
#pragma warning(disable: 4172)

#include "Core.h"

// ��� ���迡 �ִ� Ŭ���� ����
// ����(�����߿�) ����ȯ�� ������ �ϱ� ���� ����ϴ� Ŭ����.
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

//  ��Ÿ���� Ÿ�� ������ �˰� �;, �ϴ� ��, ������� ���̳��� ĳ�������� ��ĳ�����̳� �ٿ�ĳ������ �ؼ� Ÿ���� �´� �� Ȯ��. ���̳��� ĳ������ ������ �̰��� �����
// static int�� �Լ����� ���, �޸� �߿��� �ڵ� ������ ������ ��, 
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