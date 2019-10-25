#ifndef __STDBOOLCOMPAT_H__
#define __STDBOOLCOMPAT_H__

#if defined(_MSC_VER) || defined(__MINGW32__)

#ifdef __cplusplus
#error "Only include this file if compiling in AnsiC mode"
#endif

#define _Bool signed char
#define bool _Bool
#define false 0
#define true  1
#define __bool_true_false_are_defined 1

#endif /* _MSC_VER */

#endif /* __STDBOOLCOMPAT_H__ */
