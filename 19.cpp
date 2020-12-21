#include <iostream>

void merge(int* a, int left, int right, int center, long long* counter)
{
    int volume = right - left + 1;
    int* b = new int [volume];

    int i = left, j = center + 1;
    int k = 0;

    while(i <= center && j <= right)
    {
        b[k] = std::min(a[i], a[j]);

        if (std::min(a[i], a[j]) == a[i])
            i++;
        else
        {
            j++;

            (*counter) += (center - i + 1);
        }

        k++;
    }
    if (i > center)
        while (j <= right)
        {
            b[k] = a[j];
            j++; k++;
        }
    else
        while (i <= center)
        {
            b[k] = a[i];
            i++; k++;
        }

    for (int i = left, k = 0; i <= right; i++, k++)
        a[i] = b[k];

    delete [] b;
}

void sort(int* a, int left, int right, long long* counter)
{
    if (left < right)
    {
        int center = left + (right - left) / 2;

        sort(a, left, center, counter);
        sort(a, center + 1, right, counter);

        merge(a, left, right, center, counter);
    }
}

int main()
{
    long long numOfInvs = 0;
    int length = 0;

    std::cout << std::endl;
    std::cin >> length;

    int* a = new int[length];

    for (int i = 0; i < length; i++)
        std::cin >> a[i];

    sort(a, 0, length - 1, &numOfInvs);
    std::cout << numOfInvs;

    return 0;
}