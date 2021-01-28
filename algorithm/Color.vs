cBuffer MatrixBuffer
{
	matrix g_matWorld;
	matrix g_matView;
	matrix g_matProj;
};

struct VS_INPUT
{
	float4 vPosition : POSITION;
	float4 vColor : COLOR;
};

struct PS_INPUT
{
	float4 vPosition : SV_POSITION;
	float4 vColor : COLOR;
};

PS_INPUT VS_MAIN(VS_INPUT Input)
{
	PS_INPUT OutPut = (PS_INPUT)0;

	input.position.w = 1.f;

	OutPut.vPosition = mul(Input.position, g_matWorld);
	OutPut.vPosition = mul(OutPut.vPosition, g_matView);
	OutPut.vPosition = mul(OutPut.vPosition, g_matProj);

	OutPut.vColor = Input.vColor;

	return OutPut;
}