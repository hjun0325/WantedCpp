#pragma once

#include "IDocumentProcess.h"
#include "DocumentProcess.h"
#include <vector>

// ������ ó���ϴ� ó���� Ŭ����.
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