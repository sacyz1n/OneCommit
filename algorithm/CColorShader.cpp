#include "..\Headers\CColorShader.h"

void CColorShader::SetInputLayOut(D3D11_INPUT_ELEMENT_DESC ** _ppPolygonLayout, _uint * _pNumOfElement)
{
	*_pNumOfElement = 2;
	*_ppPolygonLayout = new D3D11_INPUT_ELEMENT_DESC[*_pNumOfElement];

	D3D11_INPUT_ELEMENT_DESC* pDesc = (*_ppPolygonLayout);

	pDesc[0].SemanticName			= "POSITION";
	pDesc[0].SemanticIndex			= 0;
	pDesc[0].Format					= DXGI_FORMAT_R32G32B32A32_FLOAT;
	pDesc[0].InputSlot				= 0;
	pDesc[0].AlignedByteOffset		= 0;
	pDesc[0].InputSlotClass			= D3D11_INPUT_PER_VERTEX_DATA;
	pDesc[0].InstanceDataStepRate	= 0;

	pDesc[1].SemanticName = "COLOR";
	pDesc[1].SemanticIndex = 0;
	pDesc[1].Format = DXGI_FORMAT_R32G32B32A32_FLOAT;
	pDesc[1].InputSlot = 0;
	pDesc[1].AlignedByteOffset = D3D11_APPEND_ALIGNED_ELEMENT;
	pDesc[1].InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	pDesc[1].InstanceDataStepRate = 0;
}
