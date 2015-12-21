
/* Include guard */
#ifndef __abbreviation_hpp
	#define __abbreviation_hpp 201505L

	/* Require C++ */
	#ifndef __cplusplus
		#error C++ is required
	
	/* Require C++ 11 */
	#elif __cplusplus < 201103L
		#error Full C++11 features is required
	
	/* Everything is OK */
	#else
		#include "__abbreviation.hpp"

	#endif
#endif