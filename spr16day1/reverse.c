/* Class: Computing II
 * De La Rosa, O.
 * Purpose: reverse function definition for c-strings
 * 			It will take a c-string variable and return it reverse in place
 * Date: Jan 21st, 2016
 */

char* reverse(char* givenStr)
{
	int i, j, len = 0;
	char temp;	// To use while swapping character in place

	// Gets length of string
	while(givenStr[len])
		len++;

	j = len - 1;	// Last valid character of the string
	for(i = 0; i < j; i++, j--)	// Copy first char to last position; last char to first position and so on until the end of the sting.
	{
		temp = givenStr[i];
		givenStr[i] = givenStr[j];
		givenStr[j] = temp;
	}

	return givenStr;
}
