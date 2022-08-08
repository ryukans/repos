#include <stdio.h>


enum Table_char_set {
	VerticalRightMid  = 0xb9,
	VerticalLine	  = 0xba,
	UpRightAngle	  = 0xbb,
	DownRightAngle	  = 0xbc,
	VertivalLeftMid	  = 0xcc,
	HorizontalLine	  = 0xcd,
	DownLeftAngle	  = 0xc8,
	UpLeftAngle		  = 0xc9,
	HorizontalDownMid = 0xca,
	HorizontalUpMid   = 0xcb,
	CrossSign		  = 0xce
};

typedef unsigned char flag;

void drawtableX(
	unsigned length,
	flag direction
);

void drewtableY(
	unsigned length,
	flag dir,
	unsigned line
);


void drawtableX(unsigned len, flag dir)
{
	if (dir) {
		putchar(UpLeftAngle);
		while (len--)
			putchar(HorizontalLine);
		putchar(UpRightAngle);
		putchar('\n');
	}
	else if (!dir) {
		putchar(DownLeftAngle);
		while (len--)
			putchar(HorizontalLine);
		putchar(DownRightAngle);
		putchar('\n');
	}
	else
		printf("Error -- bad direction\n 0 Down - 1 Up\n");
}


void drawtableY(unsigned len, flag dir, unsigned line)
{
	while (len--) {
		if (line > 0) {
			if (!(len%line)) {
				if (dir) {
					putchar(VerticalRightMid);
					putchar('\n');
				}
				else if (!dir) {
					putchar(VertivalLeftMid);
					putchar('\n');
				}
				else
					printf("Error -- bad direction\n 0 Left - 1 Right\n");
			}
		}
		putchar(VerticalLine);
		putchar('\n');
	}
}

