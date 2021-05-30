/* Chart */
#define COLUMN_SIZE 26
#define ROW_SIZE 6
#define CHART[ROW_SIZE][COLUMN_SIZE] = /
	{
		{DOT, LINE},
		{LINE, DOT, DOT, DOT},
		{LINE, DOT, LINE, DOT},
		{LINE, DOT, DOT},
		{DOT},
		{DOT, DOT, LINE, DOT,}
	};


void chart(void);

void chart()
{
	char morse_code[ROW_SIZE][COLUMN_SIZE] = {
		{DOT, LINE},
		{LINE, DOT, DOT, DOT},
		{LINE, DOT, LINE, DOT},
		{LINE, DOT, DOT},
		{DOT},
		{DOT, DOT, LINE, DOT,}
	};

}
