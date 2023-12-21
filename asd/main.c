#include <stdio.h>
#include <stdlib.h>

int main()
{

    int flag = 1;
    int rows, cols;

    // Kullan�c�dan matris boyutlar�n� al
    printf("Matrisin satir sayisini girin: ");
    scanf("%d", &rows);

    printf("Matrisin sutun sayisini girin: ");
    scanf("%d", &cols);

    // Matrisin boyutlar�na g�re bellekten alan tahsis et
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Matrisin elemanlar�n� kullan�c�dan al veya ba�ka bir �ekilde doldur
    printf("Matris elemanlarini girin:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }



    // Matrisi ekrana yazd�r
    printf("Matris:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }

    // alt sat�r�ndaki k�s�mlar� kontrol eder
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

    // sa� taraftaki k�s�mlar� kontrol eder
    for (int i = 0;i<rows;i++){
        for(int j=0;j<cols-1;j++){

            if(areCoprime(matrix[j][i],matrix[j+1][i])){
                continue;
            }else{
                flag=0;
            }
        }
    }

    //matris kararl�ysa ekrana yazar
    if(flag == 0){
        printf("kararl� matris de�ildir");
    }else{
            printf("kararl� matristir");
    }

    scanf("");

    return 0;
}


// �ki say�n�n en b�y�k ortak b�lenini (GCD) bulan fonksiyon
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// �ki say�n�n aralar�nda asal olup olmad���n� kontrol eden fonksiyon
int areCoprime(int a, int b) {
    return gcd(a, b) == 1;
}
