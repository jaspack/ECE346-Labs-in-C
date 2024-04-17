

char* Num2Str(int number)
{
    char *str = malloc(10);
    int index = 0;
	int curNum = number;
	while (1)
	{

		int place = 1;
		int temp = curNum;
		while (temp > 9)
		{
			temp /= 10;
			place *= 10;
		}
		str[index] = temp + '0';
		index++;
		curNum -= temp * place;
		if (place == 1)
		{
			str[index] = '\0';
			break;
		}
	}
    return str;
}
