/*
   数组中的n个数，进行n-1趟次比较
   每次比较的时候最大的数都沉落与最下面，然后接下来会少处理一个数，因为最后一个数已经确定下来
*/
void BubbleSort(int *arr,int n) {
     int i,j;
     for (i = 0;i < n - 1;i++) {
        for (j = 0;j < n-2-i;j++) {
            if (arr[j] > arr[j+1]) {
                int temp;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
           }
        }
     }
}
