
#include <stdio.h>
#include <stdlib.h>

void read_sales_file(double* sales){
    FILE* fp = fopen("sampleinput.txt", "r");
    for (int i = 0; i < 12; ++i) {
        fscanf(fp, "%lf", &sales[i]); 

    }
    fclose(fp); 
}

void swap(double* a, double* b) 
{
    double temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void selectionSort(double arr[], char* months[], int n) 
{ 
    int i;
    int j;
    int max_index; 
    for (i = 0; i < n - 1; i++) { 
        max_index = i; 
        for (j = i + 1; j < n; j++) 
            if (arr[j] > arr[max_index]) 
                max_index = j; 
        swap(&arr[max_index], &arr[i]); 
        char* temp = months[max_index];
        months[max_index] = months[i];
        months[i] = temp;
    } 
}
void printArray(double arr[], int size, char* months[]) 
{ 
    printf("Month\t     Sales\n");
    for (int i = 0; i < size; i++)
        printf("%s\t     $%.2f\n", months[i], arr[i]);
}


int main(int argc, char* argv[]) {
    char* inputMonths[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    double sales[12]; 
    read_sales_file(sales); 

    printf("-----------------------------------------------------\n");

    printf("Monthly Sales Report for 2022:\n"); 
        printf("Month:\t    Sales:\n");
        for (int i = 0; i < 12; ++i) {
        printf("%s     \t$%.2f\n", inputMonths[i], sales[i]);
    }
    printf("\n"); 

    printf("-----------------------------------------------------\n");

    int max_sales_index = 0;
    int min_sales_index = 0;
    for (int i = 1; i < 12; ++i) {
        if(sales[i] > sales[max_sales_index]){
            max_sales_index = i;
        }
        if(sales[i] < sales[min_sales_index]){
            min_sales_index = i;
        }
    }
    printf("Minimum: $%.2f %s \n", sales[min_sales_index], inputMonths[min_sales_index]); 
    printf("Maximum: $%.2f %s ", sales[max_sales_index], inputMonths[max_sales_index]);

    printf("\n-----------------------------------------------------\n");

    printf("Six-Month Moving Average Report:\n"); 
    for (int i = 0; i < 12 - 5; ++i) {
        double sum_of_sales = 0;
        for (int j = i; j < i + 6; ++j) {
            sum_of_sales += sales[j];
        }
        printf("%s - %s: $%.2f\n", inputMonths[i], inputMonths[i + 5], sum_of_sales / 6);
    }

    printf("\n-----------------------------------------------------\n");

    printf("Sales Report (Highest to Lowest):\n"); 
    int n = sizeof(sales) / sizeof(sales[0]); 
    selectionSort(sales, inputMonths,n);
    printArray(sales, n, inputMonths);

    printf("\n-----------------------------------------------------\n");


    printf("\n");
}



