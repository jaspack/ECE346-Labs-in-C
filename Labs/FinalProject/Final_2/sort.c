


void BubbleSort(int* startingAddress)
{
	int listSize = startingAddress[0];
	int sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		for (int i = 2; i < listSize + 1; i++)
		{
			if (startingAddress[i] < startingAddress[i - 1])
			{
				int temp = startingAddress[i];
				startingAddress[i] = startingAddress[i - 1];
				startingAddress[i - 1] = temp;
				sorted = 0;
			}
		}
	}
}