/*
 *  WIN32 -- msvc patch
 */

#if defined(_MSC_VER)

#if (_MSC_VER < 1900)
#include <stdlib.h> //NULL and _snprintf
#define snprintf _snprintf
#endif //1900

#endif //_MSC_VER
