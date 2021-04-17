void merge_sort(int array[], int n){
    if(n < 2) return;
    int len1 = n / 2;
    int len2 = n - len1;
    int *array1 = array;
    int *array2 = array + len1;
    merge_sort(array1 , len1);
    merge_sort(array2 , len2);

    int *tmp = new int[n];
    int len = 0;
    int pos1 = 0, pos2 = 0;
    while( len < n ){
        if( pos2 == len2 || ( pos1 < len1 && array1[pos1] <= array2[pos2] ) )
            tmp[len++] = array1[pos1++];
        else
            tmp[len++] = array2[pos2++];
    }
    for( int i=0; i<n; i++)
        array[i] = tmp[i];
    delete[] tmp;
}