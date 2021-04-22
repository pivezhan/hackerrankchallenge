/////https://www.hackerrank.com/challenges/sorting-array-of-strings/problem

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <fstream>
int lexicographic_sort(const char* a, const char* b) {
    int length = (strlen(b) < strlen(a))?strlen(b):strlen(a);
    for (int i = 0; i < length; ++i){
        if ((a[i] < b[i])){
            return 0;
        }else if(a[i] == b[i]){
            if ((i == length -1) && (strlen(a) > strlen(b))){
                return 1;
            }else{
                continue;
            }
        }
        else{
            return 1;
        }
    }
/// if in any of the above conditions two strings are similar
// fo < foo
        return 0;
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    int length = (strlen(b) < strlen(a))?strlen(b):strlen(a);
    for (int i = 0; i < length; ++i){
        if ((a[i] > b[i])){
            return 0;
        // }else if((a[i] == b[i]) && (i == length - 1) &&  (strlen(a) ==  length) && (strlen(a) !=  strlen(b))){
        //     return 1;
        }else if(a[i] == b[i]){
            continue;
        }
        else{
            return 1;
        }
    }
/// if in any of the above conditions two strings are similar
// fo < foo
    if (length == strlen(a) && a[length-1] == b[length-1] && strlen(a) != strlen(b)){
        return 1;
    }else{
        return 0;
    }
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int lena = 0;
    int repa = 0;
    int lenb = 0;
    int repb = 0;

    for (int i = 0; i < strlen(a); ++i){
        repa = 0;
        for (int j = i + 1; j < strlen(a); ++j){
            if (a[i] == a[j] && repa != 1){
                repa = 1;
            }
        }
        if (repa == 0){
            lena++;
        }
        repa = 0;
    }
    for (int i = 0; i < strlen(b); ++i){
        repb = 0;
        for (int j = i + 1; j < strlen(b); ++j){
            if (b[i] == b[j] && repb != 1){
                repb = 1;
            }
        }
        if (repb == 0){
            lenb++;
        }
        repb = 0;
    }
    if (lena > lenb){
        return 1;
    }else if(lena == lenb){
        return lexicographic_sort(a, b);
    }else{
        return 0;
    }
}

int sort_by_length(const char* a, const char* b) {
    long int al = strlen(a);
    long int bl = strlen(b);

    if (al > bl){
        return 1;
    }else if(al == bl){
        return lexicographic_sort(a, b);
    }else{
        return 0;
    }
}


/// This is the step needed to implement the Quicksort algorithm
void swap(char* a, char* b){
    char *temp;
    int size = strlen(a);
    temp = (char *)malloc((size + 1)*sizeof(char)); 
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
    free(temp);
}

int partition(char** arr, int low, int high, int (*cmp_func)(const char* a, const char* b)){
    
    char *pivot;
    char *temp;
    size_t size = strlen(*(arr + high));
    pivot = (char*)malloc((size + 1)*sizeof(char)); 
    pivot = *(arr + high);
    int i = (low - 1);

    for (int j = low; j <= high - 1; ++j){
        if (!cmp_func(*(arr + j), pivot)){
            i++;
            swap(*(arr + i),*(arr + j));
        }
    }
    swap(*(arr + i + 1),*(arr + high));
    free(pivot);
    return (i + 1);
}

void quicksort(char** arr, int low, int high, int (*cmp_func)(const char* a, const char* b)){
    if(low > high){
        return;
    }
    if (low < high){
        int pi = partition(arr, low, high, cmp_func);
        quicksort(arr, low, pi - 1, cmp_func);
        quicksort(arr, pi + 1, high, cmp_func);
    }
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){
    quicksort(arr, 0, len - 1, cmp_func);
}


int main() 
{
    std::ofstream txtOut;
    txtOut.open("output.txt");

    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++){
        *(arr + i) = (char*)malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = (char*)realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
    printf("\n");


    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++){
        printf("%s\n", arr[i]); 
        txtOut << arr[i];
        txtOut << "\n";
    }
    txtOut << "\n";

    printf("\n");


    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++){
        printf("%s\n", arr[i]); 
        txtOut << arr[i];
        txtOut << "\n";
    }
    txtOut << "\n";
    printf("\n");


    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++){
        printf("%s\n", arr[i]); 
        txtOut << arr[i];
        txtOut << "\n";
    }
    txtOut << "\n";
    printf("\n");


    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++){
        printf("%s\n", arr[i]); 
        txtOut << arr[i];
        txtOut << "\n";
    }

    printf("\n");

    txtOut.close();

    free(arr);

}