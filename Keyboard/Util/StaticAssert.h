
#ifndef __STATICASSERT_H__
#define __STATICASSERT_H__

template<bool>
struct ComplileTimeChecker{
    ComplileTimeChecker(...);
};
template<> 
struct ComplileTimeChecker<false> {};

namespace EKEY {
    #define ASSERT(expr, msg)                         \
	{                                                 \
		class ERROR_##msg {};                         \
		ERROR_##msg ObjMaker();                       \
		sizeof(ComplileTimeChecker<expr>(ObjMaker())) \
	}
} //ATL

#endif //__VALUE_H__