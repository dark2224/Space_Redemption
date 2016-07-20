#ifndef Functor_h__
#define Functor_h__

#include <tchar.h>

class CTag_Finder
{
public:
	explicit CTag_Finder(const TCHAR* pTagName) : m_pTagName(pTagName) {}
	~CTag_Finder(void) {}

	template<typename T>
	bool operator () (T& Pair)
	{
		int iResult = lstrcmp(Pair.first, m_pTagName);

		if (0 == iResult)
			return true;
		return false;
	}
private:
	const TCHAR*				m_pTagName;
};

#endif // Functor_h__