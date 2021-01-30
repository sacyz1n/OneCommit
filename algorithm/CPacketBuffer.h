#pragma once

#include "Include.h"

BEGIN(NetWork)
class CPacketBuffer
{
public:
	explicit CPacketBuffer();
	~CPacketBuffer();

public:
	char* GetStartBuf();
	char* GetWriterBuf();
	char** GetReadBuf();
	char* GetEndBuf();
	int   GetCurPacketLen();
	void  FixReadBuf();
	void  AddPacketLen(const int& _iPacketLen);

	void TestPrint();

private:
	char			 m_cPacketBuffer[MAX_PACKET_BUFFER_SIZE + PACKET_BUFFER_EXCEPT_SIZE];
	char*			 m_pStartPoint = nullptr;
	char*			 m_pEndPoint = nullptr;
	char*			 m_pWritePoint = nullptr;
	char*			 m_pReadPoint = nullptr;
};
END