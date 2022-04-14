#include <stdio.h>

void qsort(
	int left,
	int right
);

void swap(
	int i,
	int j
);


int v[] = {58, 23, 10, 6, 20, 1, 4};

int main()
{
	
	int i;

	qsort(0, 6);
	printf("sorted:\n");
	for (i = 0; i < 7; ++i)
		printf("%d ", v[i]);

	putchar('\n');
	getch();

	return 0;
}

/* qsort: sort v[left] ... v[right] into incresing order */
void qsort(int left, int right)
{
	int i, last;

	if (left >= right)		/* do nothing if array contains */
		return;				/* fewer than two elements */

	swap(left, (left + right) / 2);	/* move partition elem */
	last = left;					/* to v[0] */
	for (i = left + 1; i <= right; i++)
		if (v[i] < v[left])
			swap(++last, i);

	swap(left, last);	/* restore partition elem */
	qsort(left, last-1);
	qsort(last+1, right);
}

/* swap: interchange v[i] and v[j] */
void swap(int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}