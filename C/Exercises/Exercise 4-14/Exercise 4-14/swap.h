#define __swap__(Int32, x, y) { \
	Int32 tmp; \
	tmp = x; \
	x = y; \
	y = tmp; \
}

#define _sumswap_(x, y) { \
	x += y; \
	y -= x; \
	x -= y; \
}

#define __xorswap__(x, y) { \
	x ^= y; \
	y ^= x; \
	x ^= y; \
}

#define __print__(x, y)	\
	printf(#x " = %d - " #y " = %d\n", x, y);

