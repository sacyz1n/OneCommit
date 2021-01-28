#pragma once

#include "CComponent.h"

BEGIN(Engine)
class ENGINE_DLL CShader abstract : public Engine::CComponent
{
protected:
	explicit CShader();
	explicit CShader(const CShader& _rhs);
	virtual ~CShader() = default;

private:
	struct MatrixBufferType
	{
		_matrix matWorld;
		_matrix matView;
		_matrix matProj;
	};

public:
	HRESULT LoadShaderFiles(ID3D11Device* _pDevice, const _tchar* _szVertexShaderFilePath, const _tchar* _szPixelShaderFilePath);
	void	Render(ID3D11DeviceContext* _pDeviceContext, const int& _iIndexCnt);

protected:
	virtual void SetInputLayOut(D3D11_INPUT_ELEMENT_DESC** _ppPolygonLayout, _uint* _pNumOfElement) = 0;

private:
	void PrintShaderErrorMsg(ID3D10Blob* _pErrorMsg, const _tchar* _szShaderFilePath);

private:
	ID3D11VertexShader* m_pVertexShader = nullptr;
	ID3D11PixelShader*  m_pPixelShader = nullptr;
	ID3D11InputLayout*  m_pInputLayout = nullptr;
	ID3D11Buffer*		m_pMatrixBuffer = nullptr;

private:
	virtual void Free() override;
};

END