
/* Include guard */
#ifndef __utilities_hpp
	#define __utilities_hpp 201506L

	/* Require C++ */
	#ifndef __cplusplus
		#error C++ is required

	/* Require C++ 14 */
	#elif __cplusplus < 201402L
	#error Full C++14 features is required

	/* Everything is OK */
	#else
		#include "__utilities.hpp"

	#endif
#endif