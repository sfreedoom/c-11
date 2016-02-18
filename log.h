#ifndef __LOG__H
#define __LOG__H

#ifndef __cplusplus
extern "C" {
#endif

#define LOG(...){\
	fprintf(stderr, "%s: Line %d:\t", __FILE__, __LINE__);	\
	fprintf(stderr, __VA_ARGS__); \
	fprintf(stderr, "\n");\
}

#ifndef __cplusplus
}
#endif

#endif //__LOG__H
