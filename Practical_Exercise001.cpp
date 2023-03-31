#define MAX 100
#include <math.h>
#include <iostream>
void input(int a[], int &n) {
    do {
        printf("\nNhap n: ");
        scanf_s("%d", &n);
        if (n <= 0 || n>MAX) {
            printf("Nhap sai r, Nhap lai: ");
            scanf_s("%d", &n);
        }
    } while (n <= 0 || n > MAX);
    

    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }
}

void Output(int a[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%4d", a[i]);
    }
}

int totalEvenNumber(int a[], int n)
{
    
     
    int total = 0;
    if (n == 0) return 0;
   total = totalEvenNumber(a, n - 1);
    if (a[n - 1] % 2 == 0) total += a[n - 1];
    return total;


   /* if (a == 0) return 0;
    if (a[n - 1] % 2 == 0) return totalEvenNumber(a, n - 1) + a[n - 1];
    return totalEvenNumber(a, n - 1)*/;
}
int totalRealNumber(int a[], int n) {
    int total = 0;
    if (n == 0) return 0;
    total = totalRealNumber(a, n - 1);
    if (a[n - 1] > 0) total += a[n - 1];
    return total;

}
int Exclamation_Mark(int n) { //vocabulary: Exclamtion mark: dấu chấm than; expession biểu thức
    if (n == 1) return 1;
    return n * Exclamation_Mark(n - 1);
}
int totalExpression(int x, int n) // S(x, n) = x + x^2/2! + x^3/3! + … + x^n/n!
{
    int total = 0;
    if (n == 1) return x;
    total = totalExpression(x ,n - 1);
    return (pow(x, 3) / Exclamation_Mark(n)) + totalExpression(x, n - 1);
}
int main() {
    int n;
   
    int a[MAX];
    input(a, n);
    Output(a, n);
    int tong = totalEvenNumber(a, n);
    printf("Tong Chan: %d", tong);
    printf("Tong so thuc: %d ", totalRealNumber(a, n));
    return 0;
}


