#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100

void findMax (int arr[], int n) {

    int max = arr[0];
    for(int i = 0; i < n; i++) {
        if (arr[i]>max) {
            max = arr[i];
        }
    }
    printf("Max is %d", max);
    return ;
}

int main() {
    int n;
    
    printf("Input how many arrays you wanna input: ");
    scanf("%d", &n);

    int arr[size];

    for(int i = 0; i < n; i++) {
        printf("Input %d: ", i+1);
        scanf("%d", arr[i]);
    }

    findMax(arr,n); // ? why do we pass arr and not &arr, 
    // ! when you pass an array to the function, it decays into a pointer to its first element
    return 0;
    


}
