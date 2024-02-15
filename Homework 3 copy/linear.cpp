bool anyFalse(const double a[], int n)
{
    bool temp;
    if (n <= 0)
        temp = false;
    else
    {
        temp = somePredicate(*a);
        if (!temp)
            temp = anyFalse(a+1 , n-1);
    }

    return temp;
}

int countFalse(const double a[], int n)
{
    if (n <= 0)
        return 0;
    int count = 0;
    if (somePredicate(*a))
        count++;
    count += countFalse(a+1, n-1);
    return count;
}

int firstFalse(const double a[], int n)
{
   if (n <= 0)
       return -1;
   if (somePredicate(*a))
   {
       int next = firstFalse(a + 1, n - 1);
       if (next == -1)
           return -1;
       else
           return next + 1;
   }
   else
       return 0;
}

int locateMinimum(const double a[], int n)
{
    if (n <= 0)
        return -1;
    if(n == 1)
        return 0;

    int temp = locateMinimum(a + 1, n - 1);
    if (*a <= *(a + temp + 1))
        return 0;
    else
        return temp + 1;
}

bool includes(const double a1[], int n1, const double a2[], int n2)
{
   if (n1 <= 0)
       return false;
   if (n2 <= 0)
       return true;
   if (*a1 == *a2)
       return includes(a1 + 1, n1 - 1, a2 + 1, n2 - 1);
   return includes(a1 + 1, n1 - 1, a2, n2);
}

