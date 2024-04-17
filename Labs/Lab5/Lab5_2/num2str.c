
// This function assumes the number is fewer than ten digits long
// The function seperates the individual digits of an integer and returns a string of characters
char* Num2Str(int number)
{
// Allocating memory for a string 10 characters long
    	char *str = malloc(10*sizeof(char));
// This value will keep track of our current position in the string    
	int index = 0;
	int curNum = number;
	while (index < 9)
	{
		// This value tracks the current digit's number place value
		int place = 1;
		// we use this temporary value to retain continuity between iterations
		int temp = curNum;
		// To find the next digit in the string we divide the value by ten
		// until it is less than ten. This isolates a single digit
		while (temp > 9)
		{
			temp /= 10;
			// Multiply the place value by ten for easier arithmetic operations later
			place *= 10;
		}
		// We store the resulting digit of the above loop into the current position of the string
		str[index] = temp + '0';
		// Then increment the index
		index++;
		// Here we remove the digit we just found from the current number to repeat the process
		curNum -= temp * place;
		// If we've reached the ones place, were done so we add the null character to denote the end of the string
		// Since we have dynamically allocated the size of the string the calling program won't know the size of the array
		// This helps us use the string without operating out of bounds or printing unused characters
		if (place == 1)
		{
			str[index] = '\0';
			// The break statement allows us to exit the while loop even if the condition hasn't been met
			break;
		}
	}
// Finally, we return a pointer to the first element of our new string
    return str;
}
