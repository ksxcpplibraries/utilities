
/* OPERATORS */

#ifndef __defined_utility_macros_hpp__skip_opruse
	#define ASSIGN_VAL(x, val) (x = val)
	#define INCREASE_BY(x, val) (x += val)
	#define DECREASE_BY(x, val) (x -= val)
	#define MULTIPLE_BY(x, val) (x *= val)
	#define DIVIDE_BY(x, val) (x /= val)
	#define MODULE_BY(x, val) (x %= val)
	#define BE_NEG_INT(x, val) (x ~= val)
	#define BE_AND_INT(x, val) (x &= val)
	#define BE_OR_INT(x, val) (x |= val)
	#define SHL_INT_BY(x, val) (x << val)
	#define SHR_INT_BY(x, val) (x >> val)
	#define MULTIPLE_INT_BY_2EXP(x, val) (x << val)
	#define DIVIDE_INT_BY_2EXP(x, val) (x >> val)
	#define INCREASE_F(x) (++x)
	#define DECREASE_F(x) (--x)
	#define INCREASE_L(x) (x++)
	#define DECREASE_L(x) (x--)
	#define ADD_NUM(a, b) (x + b)
	#define SUBTRACT_NUM(a, b) (a - b)
	#define MULTIPLE_NUM(a, b) (a * b)
	#define DIVIDE_NUM(a, b) (a / b)
	#define MODULO_NUM(a, b) (a % b)
	#define NEG_BOOL(x) (!x)
	#define NOT_BOOL(x) (!x)
	#define AND_BOOL(a, b) (a && b)
	#define OR_BOOL(a, b) (a || b)
	#define XOR_BOOL(a, b) (a != b)
	#define XNOR_BOOL(a, b) (a == b)
	#define COMPARE_LESS(a, b) (a < b)
	#define COMPARE_GREATEREQUAL(a, b) (a >= b)
	#define COMPARE_GREATER(a, b) (a > b)
	#define COMPARE_LESSEQUAL(a, b) (a <= b)
	#define COMPARE_EQUAL(a, b) (a == b)
	#define COMPARE_NOTEQUAL(a, b) (a != b)
	#define NEG_INT(x) (~x)
	#define NOT_INT(x) (~x)
	#define AND_INT(a, b) (a & b)
	#define OR_INT(a, b) (a | b)
	#define XOR_INT(a, b) (a ^ b)
	#define XNOR_INT(a, b) NEG_INT(XOR_INT(a, b))
	#define SHL_INT(a, b) (a << b)
	#define SHR_INT(a, b) (a >> b)
#endif

/* OPERATOR IDENTIFIERS */

#ifndef __defined_utility_macros_hpp__skip_oprid
	#define ASSIGNMENT operator=
	#define INCREASE_BY_OPR operator+=
	#define DECREASE_BY_OPR operator-=
	#define MULTIPLE_BY_OPR operator*=
	#define DIVIDE_BY_OPR operator/=
	#define MODULE_BY_OPR operator%=
	#define BE_NEG_INT_OPR operator~=
	#define BE_AND_INT_OPR operator&=
	#define BE_OR_INT_OPR operator|=
	#define BE_XOR_INT_OPR operator^=
	#define SHL_ASSIGNMENT operator<<=
	#define SHR_ASSIGNMENT operator>>=
	#define INCREMENT operator++
	#define DECREMENT operator--
	#define ADDITION operator+
	#define SUBTRACTION operator-
	#define MULTIMPLICATION operator*
	#define DIVISION operator/
	#define MODULUS operator%
	#define NEG_BOOL_OPR operator!
	#define NOT_BOOL_OPR operator!
	#define LESS_COMPARISION operator<
	#define GREATEREQUAL_COMPARISION operator>=
	#define GREATER_COMPARISON operator>
	#define LESSEQUAL_COMPARISON operator<=
	#define EQUAL_COMPARISON operator==
	#define NOTEQUAL_COMPARISON operator!=
	#define NEG_INT_OPR operator~
	#define NOT_INT_OPR operator~
	#define AND_INT_OPR operator&
	#define OR_INT_OPR operator|
	#define XOR_INT_OPR operator^
	#define SHL_OPR operator<<
	#define SHR_OPR operator>>
	#define FUNCTION_CALL operator()
	#define ARRAY_SUBSCRIPT operator[]
	#define POINTER_ALLOCATION operator*
	#define POINTER_MEMBER_ALLOCATION operator->
#endif

/* ARITHMATICS AND MATHEMATICS */

#ifndef __defined_utility_macros_hpp__skip_arithmath
	#define _ODD 1
	#define ODD(n) (n & _ODD)
	#define INDIV(a, b) (a % b)
	#define SQR(n) (n * n)
	#define EXP_BASE_2(n) (1 << n)
	#define GETEVENL(n) (n - ODD(n))
	#define MAKEEVENL(n) (n -= ODD(n))
	#define GETEVENG(n) (n + ODD(n))
	#define MAKEEVENG(n) (n += ODD(n))
	#define _SIGNINT8 0x80
	#define _SIGNINT16 0x8000
	#define _SIGNINT32 0x80000000
	#define _SIGNINT64 0x8000000000000000
	#define SIGNINT8(n) (n & _SIGNINT8)
	#define SIGNINT16(n) (n & _SIGNINT16)
	#define SIGNINT32(n) (n & _SIGNINT32)
	#define SIGNINT64(n) (n & _SIGNINT64)
	#define ABSINT8(n) (SIGNINT8(n) ? (-n) : n)
	#define ABSINT16(n) (SIGNINT16(n) ? (-n) : n)
	#define ABSINT32(n) (SIGNINT32(n) ? (-n) : n)
	#define ABSINT64(n) (SIGNINT64(n) ? (-n) : n)
#endif

#ifndef __defined_utility_macros_hpp__skip_const
	#define MAXINT8 0x7F
	#define MININT8 0x80
	#define MAXUINT8 0xFF
	#define MINUINT8 0x00
	#define MAXINT16 0x7FFF
	#define MININT16 0x8000
	#define MAXUINT16 0xFFFF
	#define MINUINT16 0x0000
	#define MAXINT32 0x7FFFFFFF
	#define MININT32 0x80000000
	#define MAXUINT32 0xFFFFFFFF
	#define MINUINT32 0x00000000
	#define MAXINT64 0x7FFFFFFFFFFFFFFF
	#define MININT64 0x8000000000000000
	#define MAXUINT64 0xFFFFFFFFFFFFFFFF
	#define MINUINT64 0x0000000000000000
#endif