
#include <vector>
#include <list>
#include <array>
#include <map>
#include <set>
#include <cstddef>
#include <cstdint>
#include <iostream>

namespace shorten {
	
	/* USING NAMESPACE */
	
	using namespace std;
	using namespace shorten;
	
	/* SHORTEN INT */
	
	#ifdef __clang__
	typedef char i8;
	typedef unsigned char ui8;
	typedef short i16;
	typedef unsigned short ui16;
	typedef long i32;
	typedef unsigned long ui32;
	typedef long long i64;
	typedef unsigned long long ui64;
	#else
	typedef int8_t i8;
	typedef uint8_t ui8;
	typedef int16_t i16;
	typedef uint16_t ui16;
	typedef int32_t i32;
	typedef uint32_t ui32;
	typedef int64_t i64;
	typedef uint64_t ui64;
	#endif
	
	/* SHORTEN FLOATING POINT */
	
	typedef float f32;
	typedef double f64;
	
	/* SHORTEN VECTOR */
	
	typedef vector<i8> i8v;
	typedef vector<ui8> ui8v;
	typedef vector<i16> i16v;
	typedef vector<ui16> ui16v;
	typedef vector<i32> i32v;
	typedef vector<ui32> ui32v;
	typedef vector<i64> i64v;
	typedef vector<ui64> ui64v;
	typedef vector<f32> f32v;
	typedef vector<f64> f64v;
	
	/* SHORTEN LIST */
	
	typedef list<i8> i8l;
	typedef list<ui8> ui8l;
	typedef list<i16> i16l;
	typedef list<ui16> ui16l;
	typedef list<i32> i32l;
	typedef list<ui32> ui32l;
	typedef list<i64> i64l;
	typedef list<ui64> ui64l;
	typedef list<f32> f32l;
	typedef list<f64> f64l;	
	
	/* SHORTEN ARRAY */
	
	template <size_t s> using i8a = array<i8, s>;
	template <size_t s> using ui8a = array<ui8, s>;
	template <size_t s> using i16a = array<i16, s>;
	template <size_t s> using ui16a = array<ui16, s>;
	template <size_t s> using i32a = array<i32, s>;
	template <size_t s> using ui32a = array<ui32, s>;
	template <size_t s> using i64a = array<i64, s>;
	template <size_t s> using ui64a = array<ui64, s>;
	template <size_t s> using f32a = array<f32, s>;
	template <size_t s> using f64a = array<f64, s>;
	
	/* SHORTEN MAP */
	
	template <class key_t> using vi8m = map<key_t, i8>;
	template <class key_t> using vui8m = map<key_t, ui8>;
	template <class key_t> using vi16m = map<key_t, i16>;
	template <class key_t> using vui16m = map<key_t, ui16>;
	template <class key_t> using vi32m = map<key_t, i32>;
	template <class key_t> using vui32m = map<key_t, ui32>;
	template <class key_t> using vi64m = map<key_t, i64>;
	template <class key_t> using vui64m = map<key_t, ui64>;
	template <class key_t> using vf32m = map<key_t, f32>;
	template <class key_t> using vf64m = map<key_t, f64>;
	template <class val_t> using ki8m = map<i8, val_t>;
	template <class val_t> using kui8m = map<ui8, val_t>;
	template <class val_t> using ki16m = map<i16, val_t>;
	template <class val_t> using kui16m = map<ui16, val_t>;
	template <class val_t> using ki32m = map<i32, val_t>;
	template <class val_t> using kui32m = map<ui32, val_t>;
	template <class val_t> using ki64m = map<i64, val_t>;
	template <class val_t> using kui64m = map<ui64, val_t>;
	template <class val_t> using kf32m = map<f32, val_t>;
	template <class val_t> using kf64m = map<f64, val_t>;
	
	/* SHORTEN SET */
	
	typedef set<i8> i8s;
	typedef set<ui8> ui8s;
	typedef set<i16> i16s;
	typedef set<ui16> ui16s;
	typedef set<i32> i32s;
	typedef set<ui32> ui32s;
	typedef set<i64> i64s;
	typedef set<ui64> ui64s;
	typedef set<f32> f32s;
	typedef set<f64> f64s;
	
}