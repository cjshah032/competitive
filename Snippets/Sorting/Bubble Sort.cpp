void BubbleSort(int arr[], int n)   //Sorts arr[n] and prints sorted array
{
    bool sorted = true;
    for(int i=n-1; i>=0; i--)
    {
        sorted = true;
        for(int j=0; j<i; j++)
        {
            if(arr[j] > arr[j+1])
            swap(arr[j], arr[j+1]);
            sorted = false;
        }
        if(sorted == true)  //if the array is already sorted before this
        break;              //iteration, it will break the loop.
    }
    
    for(int i=0; i<n; i++)
    cout<<arr[i]<<" ";
}