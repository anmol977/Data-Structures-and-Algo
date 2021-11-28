#include <iostream>
#include <algorithm>

void counting_sort(int *arr,int n)
{
    int largest = -1;
    for (int i = 0; i != n; i++)
    {
        largest = std::max(arr[i], largest);
    }

    int *freq = new int[largest + 1]{0};

    for (int i = 0; i != n; i++)
    {
        freq[arr[i]]++;
    }

    int j = 0;

    for(int i = 0 ; i <= largest ; i++){
        while(freq[i] > 0 ){
            arr[j] = i;
            freq[i]--;
            j++;
        }
    }
}

int main()
{
    int arr[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, 5, 8};
    int n = (sizeof(arr) / sizeof(int));
    counting_sort(arr,n);
    for(auto i : arr)
        std::cout<<i<<" ";
}