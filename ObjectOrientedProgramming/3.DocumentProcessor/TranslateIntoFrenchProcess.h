#pragma once

#include "IDocumentProcess.h"
#include "DocumentProcess.h"

// 함수 포인터를 활용한 함수형 합성으로 필요 없는 클래스.
class TranslateIntoFrenchProcess : public IDocumentProcess
{
public:
    virtual void Process(const Document& document) override
    {
        DocumentProcess::TranslateIntoFrench(document);
    }
};