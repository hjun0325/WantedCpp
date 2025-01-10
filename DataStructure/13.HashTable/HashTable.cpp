#include <iostream>
#include "HashTable.h"

// �ؽ� �Լ�.
int GenerateHash(std::string keyString)
{
    // ���� ���� ���ڿ� ���� Ȯ��.
    //int length = (int)strlen(keyString);

    // ������ Ű.
    int hash = 0;
    for (int ix = 0;ix < (int)keyString.size();++ix)
    {
        // �ؽ� �Լ� �ٽ� ����.
        hash = hash * 31 + keyString[ix];
    }


    // �ؽ� ���� �ʹ� ũ�� ������ ��ȯ�Ǵ� ��찡 �־ ����� �����.
    return hash < 0 ? -hash : hash;
}

void HashTable::Add(std::string key, std::string value)
{
    // �ε��� ���ϱ�.
    int bucketIndex = GenerateHash(key) % bucketCount;

    // ������ ��ġ�� �ִ� �����̳� ��������.
    auto& position = table[bucketIndex];

    // �ؽ� ���̺��� �ߺ��� ������� ����.
    // �˻�.
    for (int ix = 0;ix < (int)position.size();++ix)
    {
        // Ű ��.
        //if (strcmp(position[ix].key, key) == 0)
        if (position[ix].key == key)
        {
            std::cout << "�̹� ���� Ű�� ����Ǿ� �־� ���� ����.\n";
            return;
        }
    }

    // ������ ����.
    position.push_back(Entry(key, value));

}

void HashTable::Delete(std::string key)
{
    // �ε��� ���ϱ�.
    int bucketIndex = GenerateHash(key) % bucketCount;

    // ������ ��ġ�� �ִ� �����̳� ��������.
    auto& position = table[bucketIndex];

    // �˻�.
    for (int ix = 0;ix < (int)position.size();++ix)
    {
        // Ű ��.
        //if (strcmp(position[ix].key, key) == 0)
        if (position[ix].key == key)
        {
            position.erase(position.begin() + ix);
            std::cout << "Ű: " << key << " �׸��� ����.\n";
            return;
        }
    }

    // �˻� ����.
    std::cout << "������ �׸��� ã�� ���߽��ϴ�.\n";
}

bool HashTable::Find(std::string key, Entry& outValue)
{
    // �ε��� ���ϱ�.
    int bucketIndex = GenerateHash(key) % bucketCount;

    // ������ ��ġ�� �ִ� �����̳� ��������.
    auto& position = table[bucketIndex];

    // ���� ó��.
    if (position.size() == 0)
    {
        std::cout << "�ش� Ű�� �׸��� ã�� ���߽��ϴ�.\n";
        return false;
    }

    // �˻�.
    for (int ix = 0;ix < (int)position.size();++ix)
    {
        // Ű ��. // ���ڿ� �� ���� ������ ���ϸ� �� ����
        //if (strcmp(position[ix].key, key) == 0)
        if (position[ix].key == key)
        {
            // �˻��� ����������, �� ���.
            outValue = position[ix];
            return true;
        }
    }

    std::cout << "�ش� Ű�� �׸��� ã�� ���߽��ϴ�.\n";
    return false;
}

void HashTable::Print()
{
    for (int ix = 0; ix < bucketCount; ++ix)
    {
        // �ǳʶٱ�.
        if (table[ix].size() == 0)
        {
            continue;
        }

        // ���.
        for (auto& entry : table[ix])
        {
            std::cout << "Ű: " << entry.key << "��: " << entry.value << "\n";
        }
    }
}
