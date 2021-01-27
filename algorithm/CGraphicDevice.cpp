#include "..\Headers\CGraphicDevice.h"

IMPLEMENT_SINGLETON(CGraphicDevice)

HRESULT CGraphicDevice::Ready_GraphicDevice(HWND hWnd, WINMODE eWinMode, const _ushort & dwSizeX, const _ushort & dwSizeY)
{
	HRESULT hr = 0;
	
	_uint iCreateDeviceFlag = 0;

#ifdef _DEBUG
	iCreateDeviceFlag |= D3D11_CREATE_DEVICE_DEBUG;
#endif
	D3D_FEATURE_LEVEL tFeatureLevel;
	::ZeroMemory(&tFeatureLevel, sizeof(D3D_FEATURE_LEVEL));

	hr = D3D11CreateDevice(0, // Default 
		D3D_DRIVER_TYPE_HARDWARE,
		0, // 소프트웨어 사용 X
		iCreateDeviceFlag,
		0, 0,
		D3D11_SDK_VERSION,
		&m_pDevice,
		&tFeatureLevel,
		&m_pDeviceContext);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"D3D11CreateDevice Failed");
	
	// 지원하는 수준 검사
	if (D3D_FEATURE_LEVEL_11_0 != tFeatureLevel)
	{
		TAGMSG_BOX(L"D3D_FEATURE_LEVEL Error", L"Not D3D_FEATURE_LEVEL_11_0");
		return E_FAIL;
	}

	// 4x msaa를 위한 품질 수준을 지원하는지 검사한다.
	_uint iM4xMsaaQuality = 0;
	hr = m_pDevice->CheckMultisampleQualityLevels(DXGI_FORMAT_R8G8B8A8_UNORM, 4, &iM4xMsaaQuality);
	assert(iM4xMsaaQuality > 0);

	DXGI_SWAP_CHAIN_DESC tSwapDesc;
	::ZeroMemory(&tSwapDesc, sizeof(DXGI_SWAP_CHAIN_DESC));

	tSwapDesc.BufferDesc.Width						= dwSizeX;
	tSwapDesc.BufferDesc.Height						= dwSizeY;
	tSwapDesc.BufferDesc.RefreshRate.Numerator		= 60;
	tSwapDesc.BufferDesc.RefreshRate.Denominator	= 1;
	tSwapDesc.BufferDesc.Scaling					= DXGI_MODE_SCALING_UNSPECIFIED;
	tSwapDesc.BufferDesc.ScanlineOrdering			= DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
	tSwapDesc.BufferDesc.Format						= DXGI_FORMAT_R8G8B8A8_UNORM;

	if (m_bEnable4xMsaa)
	{
		tSwapDesc.SampleDesc.Count = 4;
		tSwapDesc.SampleDesc.Quality = iM4xMsaaQuality - 1;
	}
	// MSAA 사용하지않는다.
	else
	{
		tSwapDesc.SampleDesc.Count	 = 1;
		tSwapDesc.SampleDesc.Quality = 0;
	}

	tSwapDesc.Windowed			= eWinMode;
	tSwapDesc.BufferUsage		= DXGI_USAGE_RENDER_TARGET_OUTPUT;
	tSwapDesc.BufferCount		= 1;
	tSwapDesc.Flags				= 0;
	tSwapDesc.OutputWindow		= hWnd;
	tSwapDesc.SwapEffect		= DXGI_SWAP_EFFECT_DISCARD;
	
	IDXGIDevice* pDxDevice = nullptr;
	hr = m_pDevice->QueryInterface(__uuidof(IDXGIDevice), (void**)&pDxDevice);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"QueryInterface Failed");

	IDXGIAdapter* pDxAdapter = nullptr;
	hr = pDxDevice->GetParent(__uuidof(IDXGIAdapter), (void**)&pDxAdapter);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"IDXGIAdapter GetParent Failed");

	// IDXGIFactory 인터페이스를 가져온다.
	IDXGIFactory* pDxFactory = nullptr;
	hr = pDxAdapter->GetParent(__uuidof(IDXGIFactory), (void**)&pDxFactory);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"IDXGIFactory GetParent Failed");

	// 스왑 체인 생성
	hr = pDxFactory->CreateSwapChain(m_pDevice, &tSwapDesc, &m_pSwapChain);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"CreateSwapChain Failed");

	pDxDevice->Release();
	pDxAdapter->Release();
	pDxFactory->Release();

	// 후면 버퍼에 대한 렌더 타겟 뷰 생성
	hr = m_pSwapChain->ResizeBuffers(1, dwSizeX, dwSizeY, DXGI_FORMAT_R8G8B8A8_UNORM, 0);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"ResizeBuffers Failed");
	ID3D11Texture2D* pBackBuffer = nullptr;
	hr = m_pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), reinterpret_cast<void**>(&pBackBuffer));
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"GetBuffer Failed");

	m_pDevice->CreateRenderTargetView(pBackBuffer, NULL, &m_pRenderTargetView);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"CreateRenderTargetView Failed");

	if (0 != pBackBuffer->Release())
		return E_FAIL;


	// 깊이, 스텐실 버퍼 생성
	D3D11_TEXTURE2D_DESC tDepthStencilDesc;
	::ZeroMemory(&tDepthStencilDesc, sizeof(D3D11_TEXTURE2D_DESC));
	tDepthStencilDesc.Width				= dwSizeX;
	tDepthStencilDesc.Height			= dwSizeY;
	tDepthStencilDesc.MipLevels			= 1;
	tDepthStencilDesc.ArraySize			= 1;
	tDepthStencilDesc.Format			= DXGI_FORMAT_D24_UNORM_S8_UINT;
	tDepthStencilDesc.Usage				= D3D11_USAGE_DEFAULT;
	tDepthStencilDesc.BindFlags			= D3D11_BIND_DEPTH_STENCIL;
	tDepthStencilDesc.CPUAccessFlags	= 0; // CPU에서 자원을 접근하지 않는다.
	tDepthStencilDesc.MiscFlags			= 0;
	
	if (m_bEnable4xMsaa)
	{
		tDepthStencilDesc.SampleDesc.Count	 = 4;
		tDepthStencilDesc.SampleDesc.Quality = iM4xMsaaQuality - 1;
	}
	else
	{
		tDepthStencilDesc.SampleDesc.Count	 = 1;
		tDepthStencilDesc.SampleDesc.Quality = 0;
	}

	hr = m_pDevice->CreateTexture2D(&tDepthStencilDesc, 0, &m_pDepthStencilBuffer);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"CreateTexture2D DepthStencilBuffer Failed");

	hr = m_pDevice->CreateDepthStencilView(m_pDepthStencilBuffer, 0, &m_pDepthStencilView);
	FAILED_CHECK_RETURN_MSG(hr, E_FAIL, L"CreateDepthStencilView Failed");

	// 렌더타겟과 깊이 스텐실 버퍼 뷰를 렌더링 파이프라인에 바인딩한다.
	m_pDeviceContext->OMSetRenderTargets(1, &m_pRenderTargetView, m_pDepthStencilView);

	// Set the viewport transform.

	m_tViewPort.TopLeftX = 0;
	m_tViewPort.TopLeftY = 0;
	m_tViewPort.Width = static_cast<float>(dwSizeX);
	m_tViewPort.Height = static_cast<float>(dwSizeY);
	m_tViewPort.MinDepth = 0.f;
	m_tViewPort.MaxDepth = 1.f;

	m_pDeviceContext->RSSetViewports(1, &m_tViewPort);

	return NOERROR;
}

HRESULT CGraphicDevice::Begin_Render()
{
	//후면 버퍼를 지운다.
	m_pDeviceContext->ClearRenderTargetView(m_pRenderTargetView, reinterpret_cast<const _float*>(&m_vColor));

	// 깊이 버퍼를 1.0f로, 스텐실 버퍼를 0으로 지운다.
	m_pDeviceContext->ClearDepthStencilView(m_pDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);

	return NOERROR;
}

HRESULT CGraphicDevice::End_Render()
{
	m_pSwapChain->Present(0, 0);

	return NOERROR;
}

void CGraphicDevice::Free()
{
	if (0 != m_pSwapChain->Release())
	{
		TAGMSG_BOX(L"Release Failed", L"m_pSwapChain->Release() Failed");
		return;
	}

	if (0 != m_pDeviceContext->Release())
	{
		TAGMSG_BOX(L"Release Failed", L"m_pDeviceContext->Release() Failed");
		return;
	}


	if (0 != m_pDevice->Release())
	{
		TAGMSG_BOX(L"Release Failed", L"m_pDevice->Release() Failed");
		return;
	}
}
