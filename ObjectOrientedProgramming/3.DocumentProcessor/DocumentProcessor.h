#pragma once

#include "IDocumentProcess.h"
#include "DocumentProcess.h"
#include <vector>

// 문서를 처리하는 처리자 클래스.
class DocumentProcessor
{
public:
    std::vector<IDocumentProcess*>& GetProcesses() { return processes; }

    void Process(const Document& doc)
    {
        for (IDocumentProcess* process : GetProcesses())
        {
            process->Process(doc);
        }
    }

private:
    std::vector<IDocumentProcess*> processes;
};