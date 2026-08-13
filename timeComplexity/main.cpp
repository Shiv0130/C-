#include <iostream>
#include <stdio.h>

using namespace std;

//int Square(int n){
//printf("%d Bytes\n",sizeof(int));
//printf("%d Bytes\n",sizeof(n));
//return n*n;
//}

int Sum(int a[],int n){
    printf("Array Size %d Bytes\n" , sizeof(a)*n);// Array 4n
    printf("%d Bytes\n",sizeof(int));
    printf("%d Bytes\n",sizeof(n));
    printf("%d Bytes\n",sizeof(i));
    printf("%d Bytes\n",sizeof(s));
    int i,s=0;
    for(i =0;i<n;++i){
        s=s+a[i];
    }
return s;

}

int main()
{
    //int num;
   // printf("Enter a Number:");
    //scanf("%d",&num);
    //int value = Square(num);
   // printf("%d",value);
    //cout << "Hello world!" << endl;
    int size;
    printf("Enter array size:");
    scanf("%d",&size);
    int arr[size];
    for(int i = 0; i<size;++i){
        scanf("%d",&arr[i]);
    }
    int value = Sum(arr,size);
    printf("Sum of Array Values:\n %d",value);

    return 0;
}
