#include <stdio.h>
#include <stdlib.h>

int main()
{

    int flag = 1;
    int rows, cols;

    // Kullanýcýdan matris boyutlarýný al
    printf("Matrisin satir sayisini girin: ");
    scanf("%d", &rows);

    printf("Matrisin sutun sayisini girin: ");
    scanf("%d", &cols);

    // Matrisin boyutlarýna göre bellekten alan tahsis et
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Matrisin elemanlarýný kullanýcýdan al veya baþka bir þekilde doldur
    printf("Matris elemanlarini girin:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }



    // Matrisi ekrana yazdýr
    printf("Matris:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // alt satýrýndaki kýsýmlarý kontrol eder
    for (int i = 0;i<rows-1;i++){
        for(int j = 0;j<cols;j++){

            if(areCoprime(matrix[i][j],matrix[i+1][j])){
                continue;
            }else{
                flag=0;
                break;
            }
        }
    }

    // sað taraftaki kýsýmlarý kontrol eder
    for (int i = 0;i<rows;i++){
        for(int j=0;j<cols-1;j++){

            if(areCoprime(matrix[j][i],matrix[j+1][i])){
                continue;
            }else{
                flag=0;
            }
        }
    }

    //matris kararlýysa ekrana yazar
    if(flag == 0){
        printf("kararlý matris deðildir");
    }else{
            printf("kararlý matristir");
    }

    scanf("");

    return 0;
}


// Ýki sayýnýn en büyük ortak bölenini (GCD) bulan fonksiyon
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Ýki sayýnýn aralarýnda asal olup olmadýðýný kontrol eden fonksiyon
int areCoprime(int a, int b) {
    return gcd(a, b) == 1;
}
