#pragma once

#include <vector>
#include "Pair.h"
#include <string>

class HashTable
{
	// 별칭 선언.
	using Entry = Pair<std::string, std::string>;

public:
	// 명시적으로 기본 생성자로 선언.
	HashTable() = default;
	
	// 명시적으로 기본 소멸자로 선언.
	~HashTable() = default;

	void Add(std::string key, std::string value);
	void Delete(std::string key);
	bool Find(std::string key, Entry& outValue);
	void Print();

private:
	// 내장 저장소 크기 (소수(Prime Nuber)를 사용하는 것이 유리).
	static const int bucketCount = 19;

	//링크드 리스트도 많이 씀.
	//std::vector<Pair<const char*, const char*>> table[bucketCount];
	std::vector<Entry> table[bucketCount];
};