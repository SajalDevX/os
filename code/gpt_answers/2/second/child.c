#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int n, int key) {
    int l=0, r=n-1;
    while(l<=r) {
        int m=(l+r)/2;
        if(arr[m]==key) return m;
        if(arr[m]<key) l=m+1;
        else r=m-1;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    int n = argc-1;
    int arr[10];
    for(int i=1;i<argc;i++) arr[i-1] = atoi(argv[i]);

    printf("Sorted array received: ");
    for(int i=0;i<n;i++) printf("%d ", arr[i]);

    int key;
    printf("\nEnter number to search: ");
    scanf("%d",&key);

    int pos = binarySearch(arr,n,key);
    if(pos>=0) printf("Found at index %d\n", pos);
    else printf("Not found\n");

    return 0;
}
