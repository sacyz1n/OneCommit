#include "..\Headers\CShader.h"

CShader::CShader()
{
}

CShader::CShader(const CShader & _rhs)
{
}

HRESULT CShader::LoadShaderFiles(ID3D11Device * _pDevice, const _tchar * _szVertexShaderFilePath, const _tchar * _szPixelShaderFilePath)
{
	ID3D10Blob* pErrorMsg = nullptr;

	// 정점 쉐이더 컴파일
	ID3D10Blob* pVertexShaderBuffer = nullptr;
	if (FAILED(D3DX11CompileFromFileW(_szVertexShaderFilePath, NULL, NULL, "VS_MAIN", "vs_5_0", 0, 0, 0, &pVertexShaderBuffer, &pErrorMsg, 0)))
	{
		if (pErrorMsg)
			PrintShaderErrorMsg(pErrorMsg, _szVertexShaderFilePath);
		// 컴파일 오류가 아니면 파일을 못찾는 경우
		else
			TAGMSG_BOX(L"파일을 찾을 수 없습니다.", _szVertexShaderFilePath);

		return E_FAIL;
	}


	// 픽셀 쉐이더 컴파일
	ID3D10Blob* pPixelShaderBuffer = nullptr;
	if (FAILED(D3DX11CompileFromFileW(_szPixelShaderFilePath, NULL, NULL, "PS_MAIN", "ps_5_0", 0, 0, 0, &pPixelShaderBuffer, &pErrorMsg, 0)))
	{
		if (pErrorMsg)
			PrintShaderErrorMsg(pErrorMsg, _szVertexShaderFilePath);
		// 컴파일 오류가 아니면 파일을 못찾는 경우
		else
			TAGMSG_BOX(L"파일을 찾을 수 없습니다.", _szVertexShaderFilePath);

		return E_FAIL;
	}

	// 버퍼에서 정점 쉐이더 생성
	if (FAILED(_pDevice->CreateVertexShader(pVertexShaderBuffer->GetBufferPointer(),
											pVertexShaderBuffer->GetBufferSize(),
											NULL, &m_pVertexShader)))
	{
		return E_FAIL;
	}

	// 버퍼에서 픽셀 쉐이더 생성
	if (FAILED(_pDevice->CreatePixelShader(pPixelShaderBuffer->GetBufferPointer(),
										   pPixelShaderBuffer->GetBufferSize(),
										   NULL, &m_pPixelShader)))
	{
		return E_FAIL;
	}

	// 정점 입력 레이아웃 구조체를 설정한다.
	D3D11_INPUT_ELEMENT_DESC* pInputDesc = nullptr;
	_uint iNumOfElement = 0;
	SetInputLayOut(&pInputDesc, &iNumOfElement);

	if (FAILED(_pDevice->CreateInputLayout(pInputDesc, iNumOfElement, pVertexShaderBuffer->GetBufferPointer(),
		pVertexShaderBuffer->GetBufferSize(), &m_pInputLayout)))
	{
		TAGMSG_BOX(_szVertexShaderFilePath, L"Failed Create InputLayOut");
		return E_FAIL;
	}

	if (iNumOfElement == 1)
		Safe_Delete(pInputDesc);
	else
		Safe_Delete_Array(pInputDesc);

	Safe_Release(pVertexShaderBuffer);
	Safe_Release(pPixelShaderBuffer);

	D3D11_BUFFER_DESC tMatrixBufferDesc;
	tMatrixBufferDesc.Usage = D3D11_USAGE_DYNAMIC;
	tMatrixBufferDesc.ByteWidth = sizeof(CShader::MatrixBufferType);
	tMatrixBufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	tMatrixBufferDesc.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
	tMatrixBufferDesc.MiscFlags = 0;
	tMatrixBufferDesc.StructureByteStride = 0;

	if (FAILED(_pDevice->CreateBuffer(&tMatrixBufferDesc, NULL, &m_pMatrixBuffer)))
	{
		TAGMSG_BOX(L"System Error!", L"Failed Create Constant Matrix Buffer");
		return E_FAIL;
	}

	return S_OK;
}

void CShader::Render(ID3D11DeviceContext * _pDeviceContext, const int & _iIndexCnt)
{
	// 정점 입력 레이아웃 설정
	_pDeviceContext->IASetInputLayout(m_pInputLayout);

	// 정점쉐이더, 픽셀쉐이더 설정
	_pDeviceContext->VSSetShader(m_pVertexShader, NULL, 0);
	_pDeviceContext->PSSetShader(m_pPixelShader, NULL, 0);

	// 렌더링
	_pDeviceContext->DrawIndexed(_iIndexCnt, 0, 0);

}

void CShader::PrintShaderErrorMsg(ID3D10Blob * _pErrorMsg, const _tchar * _szShaderFilePath)
{
	OutputDebugStringA(reinterpret_cast<const char*>(_pErrorMsg->GetBufferPointer()));

	Safe_Release(_pErrorMsg);

	TAGMSG_BOX(L"Shader Error!", _szShaderFilePath);
}

void CShader::Free()
{
	Safe_Release(m_pMatrixBuffer);
	Safe_Release(m_pInputLayout);
	Safe_Release(m_pPixelShader);
	Safe_Release(m_pVertexShader);
}
