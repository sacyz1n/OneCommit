#include "CPacketBuffer.h"

USING(NetWork)

CPacketBuffer::CPacketBuffer()
	: m_pStartPoint(m_cPacketBuffer + PACKET_BUFFER_EXCEPT_SIZE)
	, m_pEndPoint(m_pStartPoint + MAX_PACKET_BUFFER_SIZE)
	, m_pWritePoint(m_pStartPoint)
	, m_pReadPoint(m_pStartPoint)
{
}

CPacketBuffer::~CPacketBuffer()
{
}

char * CPacketBuffer::GetStartBuf()
{
	return m_pStartPoint;
}

char * CPacketBuffer::GetWriterBuf()
{
	return m_pWritePoint;
}

char ** CPacketBuffer::GetReadBuf()
{
	return &m_pReadPoint;
}

char * CPacketBuffer::GetEndBuf()
{
	return m_pEndPoint;
}

int CPacketBuffer::GetCurPacketLen()
{
	if (m_pWritePoint == m_pReadPoint)
		return 0;

	int iCurPacketSize = m_pWritePoint - m_pReadPoint;

	// ���� ��ġ�� �б� ��ġ���� ���� ���
	return (iCurPacketSize < 0 ? MAX_PACKET_BUFFER_SIZE + iCurPacketSize : iCurPacketSize);
}

void CPacketBuffer::FixReadBuf()
{
	if (m_pEndPoint == m_pReadPoint)
	{
		m_pReadPoint = m_pStartPoint;
		return;
	}

	unsigned short wReadableSize = m_pEndPoint - m_pReadPoint;

	// �״�� �ٷ� ���� �� �ִ� �б������ ��ġ ���
	if (wReadableSize >= 2)
	{
		unsigned short wPacketSize = *reinterpret_cast<unsigned short*>(m_pReadPoint);

		// ��Ŷ ���̰� ���� �� �ִ� ũ�⺸�� Ŭ ���
		if (wPacketSize <= wReadableSize)
			return;
	}

	// ����ó���� ���۷� �����Ѵ�.
	memcpy(m_pStartPoint - wReadableSize, m_pReadPoint, wReadableSize);
	m_pReadPoint = m_pStartPoint - wReadableSize;
}

void CPacketBuffer::AddPacketLen(const int & _iPacketLen)
{
	m_pWritePoint += _iPacketLen;

	if (m_pWritePoint == m_pEndPoint)
		m_pWritePoint = m_pStartPoint;
}

void CPacketBuffer::TestPrint()
{
	printf("Write Buffer : %p \n", m_pWritePoint);
	printf("Read Buffer : %p \n", m_pReadPoint);
	printf("Start Buffer : %p \n", m_pStartPoint);
	printf("End Buffer : %p \n", m_pEndPoint);
	printf("EndPoint - ReadPoint : %d \n", m_pEndPoint - m_pReadPoint);
	printf("Cur PacketLen : %d \n", GetCurPacketLen());
}
