#include <iostream>

#include "Document.h"
#include "DocumentProcessor.h"

#include "SpellcheckProcess.h"
#include "RepaginateProcess.h"
#include "TranslateIntoFrenchProcess.h"

// ���� ó���ڸ� �����ϴ� �Լ�.
DocumentProcessor* Configure()
{
    DocumentProcessor* processor = new DocumentProcessor();
    processor->GetProcesses().emplace_back(new TranslateIntoFrenchProcess());
    processor->GetProcesses().emplace_back(new SpellcheckProcess());
    processor->GetProcesses().emplace_back(new RepaginateProcess());

    return processor;
}

int main()
{
    // ���� ��ü ����.
    Document doc1("Jake Oh", "2025.02.13", "C++ Programming");
    Document doc2("Ian Tim", "2024.01.31", "Hello Iphone");

    // ���� ó���� ��ü ����. (���丮 ����).
    DocumentProcessor* processor = Configure();

    // ���� ó��.
    std::cout << "����1 ó��\n";
    processor->Process(doc1);
    std::cout << "\n";

    std::cout << "����2 ó��\n";
    processor->Process(doc2);

    std::cin.get();
}