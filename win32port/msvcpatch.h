/*
 *  WIN32 -- msvc patch
 */

#if defined(_MSC_VER)

#if (_MSC_VER < 1900)
#include <stdlib.h> //NULL and _snprintf
#define snprintf _snprintf
#endif //1900

#pragma warning(disable:4800) // forcing value to bool true or false.
#pragma warning(disable:4996) // 'xxx': The POSIX name for this item is deprecated.

#endif //_MSC_VER
