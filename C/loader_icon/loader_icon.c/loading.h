#include <stdio.h>
#include <windows.h>
#define TOTAL_FRAMES 4
#define ROTATION_DELAY 40 /* pause time between frames. */

enum frames {
	verticalLine	= 0xB3,
	forwardSlash	= 0x2F,
	backSlash		= 0x5C,
	horizontalLine	= 0xC4
};

void loading(
	const char *msg,
	unsigned long time
);

void loading(const char *msg, unsigned long time)
{
	char* icon[TOTAL_FRAMES] = {
		verticalLine,
		forwardSlash,
		horizontalLine,
		backSlash
	};

	int frame;

	msg != NULL ? printf("%s ", msg) : putchar('\n');

	for (; time-- > 0; ) {
		for (frame = 0; frame < TOTAL_FRAMES; ++frame) {
			printf("%c\b", icon[frame]);
			Sleep(ROTATION_DELAY);
		}
	}
}



