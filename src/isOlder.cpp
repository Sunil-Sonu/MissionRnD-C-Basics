/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int year(char *, char *, int, int, int, int);
int month(int, int);
int day(int, int);
int  m1, m2, d1, d2;
int isOlder(char *dob1, char *dob2) {
	int i = 0, x;
	if ((dob1[2] != '-' || dob1[5] != '-') || (dob2[2] != '-' || dob2[5] != '-'))
	{
		return -1;
	}
	while ((dob1[i] != '\0' || dob2[i] != '\0') && (i <= 9))
	{
		if (i == 2 || i == 5)
		{
			i++;
		}
		else
		{
			if (dob1[i] < 48 || dob2[i] < 48)
				return-1;
			else if (dob1[i] > 57 || dob2[i] > 57)
				return -1;
			else
				i++;
		}
	}
	d1 = (dob1[0] - 48) * 10 + (dob1[1] - 48);
	d2 = (dob2[0] - 48) * 10 + (dob2[1] - 48);
	m1 = (dob1[3] - 48) * 10 + (dob1[4] - 48);
	m2 = (dob2[3] - 48) * 10 + (dob2[4] - 48);
	x = year(dob1, dob2, d1, d2, m1, m2);
	if (x == 0)
	{
		x = month(m1, m2);
		if (x == 0)
		{
			x = day(d1, d2);
		}
	}
	return x;
}
int year(char *dob1, char *dob2, int d1, int d2, int m1, int m2)
{
	int i = 6, y1, y2, x, y;
	y1 = (dob1[8] - 48) * 10 + (dob1[9] - 48);
	y2 = (dob2[8] - 48) * 10 + (dob2[9] - 48);
	if ((y1 % 4 != 0 && d1 >= 29 && m1 == 2) || (y2 % 4 != 0 && d2 >= 29 && m2 == 2))
		return -1;
	while (i <= 9)
	{
		x = (int)(dob1[i] - 48);
		y = (int)(dob2[i] - 48);
		if (x > y)
			return 2;
		else if (x < y)
			return 1;
		else
			i++;
	}
	return 0;
}

int month(int m1, int m2)
{
	if (m1>12 || m2 > 12)
		return -1;

	else if (m1>m2)
		return 2;
	else if (m1 < m2)
		return 1;
	else
		return 0;
}
int day(int d1, int d2)
{
	if (d1 > d2)
		return 2;
	else if (d1 < d2)
		return 1;
	else
		return 0;
}

