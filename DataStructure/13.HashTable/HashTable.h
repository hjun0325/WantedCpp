#pragma once

#include <vector>
#include "Pair.h"
#include <string>

class HashTable
{
	// ��Ī ����.
	using Entry = Pair<std::string, std::string>;

public:
	// ��������� �⺻ �����ڷ� ����.
	HashTable() = default;
	
	// ��������� �⺻ �Ҹ��ڷ� ����.
	~HashTable() = default;

	void Add(std::string key, std::string value);
	void Delete(std::string key);
	bool Find(std::string key, Entry& outValue);
	void Print();

private:
	// ���� ����� ũ�� (�Ҽ�(Prime Nuber)�� ����ϴ� ���� ����).
	static const int bucketCount = 19;

	//��ũ�� ����Ʈ�� ���� ��.
	//std::vector<Pair<const char*, const char*>> table[bucketCount];
	std::vector<Entry> table[bucketCount];
};