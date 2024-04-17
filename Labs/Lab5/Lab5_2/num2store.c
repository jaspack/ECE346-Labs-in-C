

char* Num2Store(int number)
{
    char *str = malloc(10);
    var temp = number;
    int index = 0;
    while (index < 9)
    {
        int place = 0;
        int working =1;
        while (working)
        {
            if ((temp /10) > 9) 
            {
                temp /= 10;
                place++;
            }
            else
            {
                str[index] = ( temp + '0');
                index++;
                working = 0;
            } 
        }
        if (place != 0)
        {
            int ten = 10;
            ten ^= place;
            temp *= ten;
            temp = number - temp;
        }
        else
        {
            str[index] = '\0';
            return str;
        }
    }
}
