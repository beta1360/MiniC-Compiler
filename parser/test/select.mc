void main()
{
    int N, result;
    read(N);

    result = 0;

    switch(N)
    {
    case 1:
        result = N + 1;
        break;
    case 2:
        result = N - 2;
        break;
    case 3:
        result = N * 2;
        break;
    default:
        result = 10;
        break; 
    }

    write(result);
}