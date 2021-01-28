#pragma once
#include "CShader.h"
class ENGINE_DLL CColorShader final : public CShader
{
private:
	explicit CColorShader();
	explicit CColorShader(const CColorShader& _rhs);
	virtual ~CColorShader() = default;

private:


public:
	virtual void SetInputLayOut(D3D11_INPUT_ELEMENT_DESC** _ppPolygonLayout, _uint* _pNumOfElement) override;
};

 