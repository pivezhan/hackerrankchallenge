#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lexicographic_sort(const char* a, const char* b) {
    // if (a[0] > b[0]){
    //     return a;
    // }else{
    //     return b;
    // }
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    // if (a[0] < b[0]){
    //     return a;
    // }else{
    //     return b;
    // }
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int lena = 0;
    int repa = 0;
    int lenb = 0;
    int repb = 0;

    for (int i = 0; i < strlen(a); ++i){
        repa = 0;
        for (int j = i; j < strlen(a); ++j){
            if (a[i] == a[j] && repa != 1){
                repa = 1;
            }
        }
        if (repa == 0){
            lena++;
        }
    }
    for (int i = 0; i < strlen(b); ++i){
        repb = 0;
        for (int j = i; j < strlen(b); ++j){
            if (b[i] == b[j] && repb != 1){
                repb = 1;
            }
        }
        if (repb == 0){
            lenb++;
        }
    }
    char *temp;
    int lengths = (strlen(b)>strlen(a)?strlen(b):strlen(a));

    if (lenb > lena){
        temp = (char*)malloc(lengths*sizeof(char));
        *temp = *a;
        *a = *b;
        *b = *temp;
    }
}

int sort_by_length(const char* a, const char* b) {
    char *temp;
    int lengths = (strlen(b)>strlen(a)?strlen(b):strlen(a));


    if (strlen(b) > strlen(a)){
  
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    int *temp;
    temp = (char*)malloc(lengths*sizeof(char)); 
    for (int i = 0; i < len; ++i){
        for (int j = i; j < len; ++j){
            *temp = *a;
            *a = *b;
            *b = *temp;
        }
    }
}


int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = (char*)malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = (char*)realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}