#pragma once

#include "IDocumentProcess.h"
#include "DocumentProcess.h"

// �Լ� �����͸� Ȱ���� �Լ��� �ռ����� �ʿ� ���� Ŭ����.
class RepaginateProcess : public IDocumentProcess
{
public:
    virtual void Process(const Document& document) override
    {
        DocumentProcess::Repaginate(document);
    } 
};