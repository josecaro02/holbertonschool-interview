#include "palindrome.h"

/**
*is_palindrome - Chechks if a number is palindrome
*
*@n: number to to check
*
*Return: 1 if n is palindrome, 0 otherwise
*/

int is_palindrome(unsigned long n)
{
	unsigned long temp, l_digit, reverse_number;

	temp = n;
	reverse_number = 0;
	while (temp > 0)
	{
		l_digit = temp % 10;
		reverse_number = (reverse_number * 10) + l_digit;
		temp = temp / 10;
	}

	if (n == reverse_number)
		return (1);
	return (0);
}
