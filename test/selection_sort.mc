const int MAX = 7;

void main()
{
    int i, j, k, temp;
    int array[7];

    for(k = 0; k < MAX; ++k)
    {
        array[k] = 7 - k;
    }

    for (i = 0; i < MAX - 1; ++i)
    {
        for (j = i + 1; j < MAX; ++j)
        {
            if(array[i] > array[j])
            {
                temp = array[i];
                array[i] = array[j]; 
                array[j] = temp;
            }
        }
    }

    for(k = 0; k < MAX; ++k)
    {
        write(array[k]);
    }
}
