
/* standard libraries */
#include <type_traits>
#include <iostream>
// #include <cstdio> //debug

/* from ./ */
#include "defined_utility_macros.hpp"

#ifndef EMPTY_CLASS_MEMBER
	#if defined(__GNUC__) || defined(__GNUG__)
		#define EMPTY_CLASS_MEMBER int __empty_class_member[0]
	#else
		#define EMPTY_CLASS_MEMBER struct __empty_class__ {}
	#endif
#endif

/* main */
namespace util {
	
	using namespace std;
	using namespace util;
	
	/* TYPEDEFS */
	
	template <class type>
	using pointer = type *;
	
	template <class type>
	using reference = type &;
	
	/* FUNCTIONS FORWARD DECLARATIONS */
	
	template <class value_t> inline constexpr value_t sign_int(value_t);
	template <class value_t> inline constexpr value_t abs_int(value_t);
	template <class func_t, class object_t, class ...arg_t> inline constexpr auto call_member_func(func_t, object_t, arg_t...);
	template <class object_t> inline pointer<object_t> constexpr pointer_to(reference<object_t>);
	template <class object_t> inline reference<object_t> constexpr reference_to(pointer<object_t>);
	template <class number_t, class length_t = uint64_t, class printer_t = void(number_t)> void displayBinOf(number_t, length_t = (sizeof(number_t) << 3) - 1, printer_t = [](number_t b){ cout << (b ? '1' : '0'); });
	
	/* CLASSES FORWARD DECLARATIONS */
	
	template <class base_t> struct subclass;
	template <class func_t, class object_t> struct member_func_caller;
	template <class func_t, class object_t> struct bind_member_func;
	template <class func_t, class first_t> struct reduce_func_param;
	template <class value_t = int> struct binary_form;
	template <class value_t = int> reference<ostream> operator<<(reference<ostream>, binary_form<value_t>);
	template <class getter_t, class setter_t> struct accessor;
	
	/* EXTRA UTILITIES FORWARD DECLARATIONS */
	
	namespace varutil {
		
		template <class mtype> struct destination_t {};
		template <class mtype> struct destination_t<pointer<mtype>>;
		
		template <class type>
		using destination = typename destination_t<type>::type;
		
		template <class type>
		using reference = typename destination_t<type>::reference;
		
	}
	
	namespace funcutil {
		
		template <class returning_t, class object_t, class ...arg_t> struct function_t;
		template <class returning_t, class ...arg_t> struct function_t<returning_t, void, arg_t ...>;
		
		template <class ...arg_t>
		using function = typename function_t<arg_t ...>::type;
		
		template <class returning_t = void, class ...arg_t>
		using static_function = function<returning_t, void, arg_t ...>;
		
		template <class returning_t = void, class object_t = void, class ...arg_t>
		using member_function = function<returning_t, object_t, arg_t ...>;
		
	}
	
	template <class ...arg_t>
	using function = funcutil::function<arg_t ...>;
	
	/* FUNCTIONS DEFINITIONS */
	
	template <class value_t>
	inline constexpr value_t sign_int(value_t value) {
		return value & (1 << (8 * sizeof(value_t) - 1));
	}
	
	template <class value_t>
	inline constexpr value_t abs_int(value_t value) {
		return sign_int<value_t>(value) ? (-value) : value;
	}
	
	template <class func_t, class object_t, class ...arg_t>
	inline constexpr auto call_member_func(func_t func, object_t object, arg_t ...arg) {
		return (object .* func)(arg...);
	}
	
	template <class object_t>
	inline constexpr pointer<object_t> pointer_to(reference<object_t> object) {
		return &object;
	}
	
	template <class object_t>
	inline constexpr reference<object_t> reference_to(pointer<object_t> object_p) {
		return *object_p;
	}
	
	template <class number_t, class length_t, class printer_t>
	void displayBinOf(number_t number, length_t length, printer_t printer) {
		for (auto i = 1 << length; i; i >>= 1) {
			printer(number & i);
		}
	}
	
	/* CLASSES DEFINITIONS */
	
	template <class base_t>
	struct subclass {
		
		/* Member classes */
		
		template <class target_t>
		struct _nested_typecast_t {
			typedef target_t type;
		};
		
		template <class target_t>
		struct _nested_typecast_t< subclass<target_t> > : _nested_typecast_t<target_t> {};
		
		/* Data */
		
		struct data_t {
			base_t base;
		} data;
		
		/* Constructors */
		
		inline subclass() {}
		
		inline subclass(base_t base) {
			data.base = base;
		}
		
		subclass(const subclass &value) {
			data = value.data;
		}
		
		template <class ...arg_t>
		inline subclass(arg_t ...arg) {
			data.base = base_t(arg...);
		}
		
		/* Operators */
		
		virtual inline operator base_t&() {
			return data.base;
		}
		
		template <class target_t, class = enable_if_t< is_same<target_t, typename _nested_typecast_t<base_t>::type >::value> >
		inline operator target_t&() {
			return data.base;
		}
		
		template <class ...arg_t>
		inline auto operator()(arg_t ...arg) {
			return data.base(arg...);
		}
		
		template <class param_t>
		inline auto operator[](param_t param) {
			return data.base[param];
		}
		
		template <class result_t>
		inline result_t operator!() {
			return !data.base;
		}
		
		template <class result_t>
		inline result_t operator~() {
			return ~data.base;
		}
		
		template <class result_t>
		inline result_t operator+() {
			return +data.base;
		}
		
		template <class result_t>
		inline result_t operator-() {
			return -data.base;
		}
		
		template <class param_t>
		inline operator+(param_t param) {
			return data.base + param;
		}
		
		template <class param_t>
		inline operator-(param_t param) {
			return data.base - param;
		}
		
		template <class param_t>
		inline auto operator=(param_t param) {
			return data.base = param;
		}
		
		template <class param_t>
		inline auto operator&(param_t param) {
			return data.base & param;
		}
		
		template <class param_t>
		inline auto operator|(param_t param) {
			return data.base | param;
		}
		
		template <class param_t>
		inline auto operator^(param_t param) {
			return data.base ^ param;
		}
		
		template <class param_t>
		inline auto operator<(param_t param) {
			return data.base < param;
		}
		
		template <class param_t>
		inline auto operator>(param_t param) {
			return data.base > param;
		}
		
		virtual inline base_t operator->() {
			return data.base;
		}
		
		template <class result_t>
		inline result_t operator++() {
			return ++data.base;
		}
		
		template <class result_t>
		inline result_t operator--() {
			return --data.base;
		}
		
		template <class param_t>
		inline auto operator++(param_t) {
			return data.base++;
		}
		
		template <class param_t>
		inline auto operator--(param_t) {
			return data.base--;
		}
		
		template <class param_t>
		inline auto operator<<(param_t param) {
			return data.base << param;
		}
		
		template <class param_t>
		inline auto operator>>(param_t param) {
			return data.base >> param;
		}
		
		template <class param_t>
		inline auto operator==(param_t param) {
			return data.base == param;
		}
		
		template <class param_t>
		inline auto operator!=(param_t param) {
			return data.base != param;
		}
		
		template <class param_t>
		inline auto operator<=(param_t param) {
			return data.base <= param;
		}
		
		template <class param_t>
		inline auto operator>=(param_t param) {
			return data.base >= param;
		}
		
		template <class param_t>
		inline auto operator+=(param_t param) {
			return data.base += param;
		}
		
		template <class param_t>
		inline auto operator-=(param_t param) {
			return data.base -= param;
		}
		
		template <class param_t>
		inline auto operator*=(param_t param) {
			return data.base *= param;
		}
		
		template <class param_t>
		inline auto operator/=(param_t param) {
			return data.base /= param;
		}
		
		template <class param_t>
		inline auto operator%=(param_t param) {
			return data.base %= param;
		}
		
		template <class param_t>
		inline auto operator&=(param_t param) {
			return data.base &= param;
		}
		
		template <class param_t>
		inline auto operator|=(param_t param) {
			return data.base |= param;
		}
		
		template <class param_t>
		inline auto operator^=(param_t param) {
			return data.base ^= param;
		}
		
		template <class param_t>
		inline auto operator<<=(param_t param) {
			return data.base <<= param;
		}
		
		template <class param_t>
		inline auto operator>>=(param_t param) {
			return data.base >>= param;
		}
		
	};
	
	template <class func_t, class object_t>
	struct member_func_caller {
		
		/* Data */
		
		func_t func;
		
		/* Constructors */
		
		inline member_func_caller() {}
		
		inline member_func_caller(func_t func) {
			member_func_caller::func = func;
		}
		
		/* Functions */
		
		template <class ...arg_t>
		static inline auto call(func_t func, object_t object, arg_t ...arg) {
			return call_member_func(func, object, arg...);
		}
		
		template <class ...arg_t>
		inline auto callfunc(object_t object, arg_t ...arg) {
			return call(func, object, arg...);
		}
		
		/* Operators */
		
		template <class ...arg_t>
		inline auto operator()(object_t object, arg_t ...arg) {
			return callfunc(object, arg...);
		}
		
		inline operator func_t&() {
			return func;
		}
	};
	
	template <class func_t, class object_t>
	struct bind_member_func {
		
		/* Member classes */
		
		typedef member_func_caller<func_t, object_t> nfunc_t;
		
		/* Data */
		
		nfunc_t nfunc;
		pointer<object_t> object_p;
		
		/* Constructors */
		
		inline bind_member_func() {}
		
		inline bind_member_func(func_t func) {
			nfunc = nfunc_t(func);
		}
		
		inline bind_member_func(pointer<object_t> object_p) {
			bind_member_func::object_p = object_p;
		}
		
		inline bind_member_func(func_t func , pointer<object_t> object_p) {
			nfunc = nfunc_t(func);
			bind_member_func::object_p = object_p;
		}
		
		/* Functions */
		
		template <class ...arg_t>
		inline auto callfunc(arg_t ...arg) {
			return nfunc(*object_p, arg...);
		}
		
		/* Operators */
		
		template <class ...arg_t>
		inline auto operator()(arg_t ...arg) {
			return callfunc(arg...);
		}
		
	};
	
	template <class func_t, class first_t>
	struct reduce_func_param {
		
		/* Data */
		
		func_t func;
		first_t first;
		
		/* Constructors */
		
		inline reduce_func_param () {}
		
		inline reduce_func_param (func_t func) {
			reduce_func_param::func = func;
		}
		
		inline reduce_func_param (first_t first) {
			reduce_func_param::first = first;
		}
		
		inline reduce_func_param (func_t func, first_t first) {
			reduce_func_param::func = func;
			reduce_func_param::first = first;
		}
		
		/* Operators */
		
		template <class ...arg_t>
		inline auto operator()(arg_t ...arg) {
			return func(first, arg...);
		}
		
	};
	
	template <class value_t>
	struct binary_form {
		
		/* Data */
		
		value_t value;
		
		/* Constructors */
		
		inline binary_form() {}
		inline binary_form(value_t value) {
			binary_form::value = value;
		}
		
		/* Operators */
		
		inline operator value_t&() {
			return value;
		}
		
	};
	
	template <class value_t>
	inline reference<ostream> operator<<(reference<ostream> stream, binary_form<value_t> bin) {
		displayBinOf(bin);
		return stream;
	}
	
	template <class getter_t, class setter_t>
	struct accessor {
		
		EMPTY_CLASS_MEMBER;
		
		template <getter_t get, setter_t set>
		struct type {
			
			EMPTY_CLASS_MEMBER;
			
			template <class target_t>
			inline operator target_t() {
				return get();
			}
			
			template <class source_t>
			inline auto operator =(source_t source) {
				return set(source);
			}
			
		};
		
	};
	
	/* EXTRA UTILITIES DEFINITIONS */
	
	namespace varutil {
		
		template <class mtype>
		struct destination_t<pointer<mtype>> {
			typedef mtype type;
			typedef util::reference<mtype> reference;
		};
		
	}
	
	namespace funcutil {
		
		template <class returning_t, class object_t, class ...arg_t>
		struct function_t {
			
			typedef returning_t (object_t:: *type)(arg_t ...);
			typedef type pointer;
			//typedef varutil::reference<type> reference; // there's no reference to a member function, sorry!
			
			inline returning_t call(type func, object_t object, arg_t ...arg) {
				return (object .* func)(arg ...);
			}
			
			template <type func>
			inline returning_t tcall(object_t object, arg_t ...arg) {
				return (object .* func)(arg ...);
			}
			
		};
		
		template <class returning_t, class ...arg_t>
		struct function_t<returning_t, void, arg_t ...> {
			
			typedef returning_t type(arg_t ...);
			typedef util::pointer<type> pointer;
			typedef util::reference<type> reference;
			
			inline returning_t call(type func, arg_t ...arg) {
				return func(arg ...);
			}
			
			template <type func>
			inline returning_t tcall(arg_t ...arg) {
				return func(arg ...);
			}
			
		};
		
	}
	
}