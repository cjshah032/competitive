void merge(int arr[], int l, int r, int m)  //merging branches (l, m) and (m+1, r)
{
    int L[m-l+1], R[r-m];
    
    //Copying the contents:
    for(int i=0; i<m-l+1; i++)
    L[i] = arr[l+i];
    
    for(int i=0; i<r-m; i++)
    R[i] = arr[i+m+1];
    
    //Merging accordingly
    int n1 = m-l+1;
    int n2 = r-m;
    int i=0, j=0, k=l;
    while (i < n1 && j < n2) { 
        if (L[i] < R[j]) { 
            arr[k] = L[i];
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    
    //Copying remaining elements of both branches (whichever remained)
    while(i < n1){
        arr[k] = L[i];
        i++; k++;
    }
    
    while(j < n2){
        arr[k] = R[j];
        j++; k++;
    }
}

void MergeSort(int arr[], int l, int r)
{
    if(l < r){      //to check if it's not a single element
        int m = l + ((r-l)/2);
    
        //Divide into smaller branches
        MergeSort(arr, l, m);
        MergeSort(arr, m+1, r);
        
        //Merge branches    
        merge(arr, l, r, m);   
    }
}