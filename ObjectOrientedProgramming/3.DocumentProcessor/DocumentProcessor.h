#pragma once

#include <vector>
#include <functional>
#include "DocumentProcess.h"
#include "IDocumentProcess.h"

// 문서를 처리하는 처리자 클래스.
class DocumentProcessor
{
public:
	// 문서 처리에 사용될 함수 포인터를 추가하는 함수.
	void AddDocumentProcess(std::function<void(const Document&)> process)
	{
		processes.emplace_back(process);
	}

	// 문서 처리 함수.
	void Process(const Document& document)
	{
		for (auto& process : processes)
		{
			process(document);
		}
	}

private:
	// 문서 처리에 사용하는 함수 포인터를 저장하는 배열.
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