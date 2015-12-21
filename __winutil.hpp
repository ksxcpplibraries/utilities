
/* APIs */
#include <windows.h>

/* main */
namespace winutil {
	enum ConsoleColor {
		FG_BLUE = 1 << 0, FG_GREEN = 1 << 1, FG_RED = 1 << 2, FG_INSTENSITY = 1 << 3,
		BG_BLUE = 1 << 4, BG_GREEN = 1 << 5, BG_RED = 1 << 6, BG_INSTENSITY = 1 << 7
	};
}