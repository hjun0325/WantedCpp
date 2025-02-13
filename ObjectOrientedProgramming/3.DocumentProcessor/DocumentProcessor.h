#pragma once

#include <vector>
#include <functional>
#include "DocumentProcess.h"
#include "IDocumentProcess.h"

// ������ ó���ϴ� ó���� Ŭ����.
class DocumentProcessor
{
public:
	// ���� ó���� ���� �Լ� �����͸� �߰��ϴ� �Լ�.
	void AddDocumentProcess(std::function<void(const Document&)> process)
	{
		processes.emplace_back(process);
	}

	// ���� ó�� �Լ�.
	void Process(const Document& document)
	{
		for (auto& process : processes)
		{
			process(document);
		}
	}

private:
	// ���� ó���� ����ϴ� �Լ� �����͸� �����ϴ� �迭.
	std::vector<std::function<void(const Document&)>> processes;

//public:
//    std::vector<IDocumentProcess*>& GetProcesses() { return processes; }
//
//    void Process(const Document& doc)
//    {
//        for (IDocumentProcess* process : GetProcesses())
//        {
//            process->Process(doc);
//        }
//    }
//
//private:
//    std::vector<IDocumentProcess*> processes;
};