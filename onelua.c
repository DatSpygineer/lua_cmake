/*
** Lua core, libraries, and interpreter in a single file.
** Compiling just this file generates a complete Lua stand-alone
** program:
**
** $ gcc -O2 -std=c99 -o lua onelua.c -lm
**
** or
**
** $ gcc -O2 -std=c89 -DLUA_USE_C89 -o lua onelua.c -lm
**
*/

/* default is to build the full interpreter */
#ifndef MAKE_LIB
#ifndef MAKE_LUAC
#ifndef MAKE_LUA
#define MAKE_LUA
#endif
#endif
#endif


/*
** Choose suitable platform-specific features. Default is no
** platform-specific features. Some of these options may need extra
** libraries such as -ldl -lreadline -lncurses
*/
#if 0
#define LUA_USE_LINUX
#define LUA_USE_MACOSX
#define LUA_USE_POSIX
#define LUA_ANSI
#endif


/* no need to change anything below this line ----------------------------- */

#include "core/lprefix.h"

#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <float.h>
#include <limits.h>
#include <locale.h>
#include <math.h>
#include <setjmp.h>
#include <signal.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/* setup for luaconf.h */
#define LUA_CORE
#define LUA_LIB
#define ltable_c
#define lvm_c
#include "core/luaconf.h"

/* do not export internal symbols */
#undef LUAI_FUNC
#undef LUAI_DDEC
#undef LUAI_DDEF
#define LUAI_FUNC	static
#define LUAI_DDEC(def)	/* empty */
#define LUAI_DDEF	static

/* core -- used by all */
#include "core/lzio.c"
#include "core/lctype.c"
#include "core/lopcodes.c"
#include "core/lmem.c"
#include "core/lundump.c"
#include "core/ldump.c"
#include "core/lstate.c"
#include "core/lgc.c"
#include "core/llex.c"
#include "core/lcode.c"
#include "core/lparser.c"
#include "core/ldebug.c"
#include "core/lfunc.c"
#include "core/lobject.c"
#include "core/ltm.c"
#include "core/lstring.c"
#include "core/ltable.c"
#include "core/ldo.c"
#include "core/lvm.c"
#include "core/lapi.c"

/* auxiliary library -- used by all */
#include "core/lauxlib.c"

/* standard library  -- not used by luac */
#ifndef MAKE_LUAC
#include "core/lbaselib.c"
#include "core/lcorolib.c"
#include "core/ldblib.c"
#include "core/liolib.c"
#include "core/lmathlib.c"
#include "core/loadlib.c"
#include "core/loslib.c"
#include "core/lstrlib.c"
#include "core/ltablib.c"
#include "core/lutf8lib.c"
#include "core/linit.c"
#endif

/* lua */
#ifdef MAKE_LUA
#include "lua.c"
#endif

/* luac */
#ifdef MAKE_LUAC
#include "luac.c"
#endif
