#include "..\Public\Base.h"

CBase::CBase()
{

}

unsigned long CBase::AddRef()
{
	return ++m_dwRefCnt;	
}

unsigned long CBase::Release()
{
	
	int a = m_dwRefCnt;
	

	if (0 == m_dwRefCnt)
	{
		int a = m_dwRefCnt;
		Free();

		delete this;

		return 0;
	}
	else
		return m_dwRefCnt--;
}
