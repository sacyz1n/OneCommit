#pragma once

#include "Base.h"

BEGIN(Engine)
class CGraphicDevice final : public CBase
{
	// SingleTone
	DECLARE_SINGLETON(CGraphicDevice)

private:
	explicit CGraphicDevice() = default;
	virtual ~CGraphicDevice() = default;

public:
	enum WINMODE { MODE_FULL, MODE_WIN, MODE_END };

public:
	HRESULT			Ready_GraphicDevice(HWND hWnd, WINMODE eWinMode, const _ushort& dwSizeX, const _ushort& dwSizeY);
	ID3D11Device*	Get_Device() { return m_pDevice; }
	HRESULT			Begin_Render();
	HRESULT			End_Render();

private:
	ID3D11Device*			m_pDevice				= nullptr;
	ID3D11DeviceContext*	m_pDeviceContext		= nullptr;
	IDXGISwapChain*			m_pSwapChain			= nullptr;
	ID3D11Texture2D*		m_pDepthStencilBuffer	= nullptr;
	ID3D11RenderTargetView* m_pRenderTargetView		= nullptr;
	ID3D11DepthStencilView* m_pDepthStencilView		= nullptr;
	D3D11_VIEWPORT			m_tViewPort;

	XMVECTORF32				m_vColor = { 0.f, 0.f, 1.f, 1.f };

	_bool					m_bEnable4xMsaa = false;


public:
	virtual void Free() override;
};

END