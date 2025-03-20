/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#include "hitungBiner.h"
#include <stdlib.h>
#include <math.h>

boolean isBinerStack(Stack S) {
    Stack temp;
    CreateStack(&temp);
    
    boolean valid = true;
    while (!isEmptyStack(S)) {
        int bit;
        Pop(&S, &bit);
        Push(&temp, bit);
        
        if (bit != 0 && bit != 1) {
            valid = false;
        }
    }

    while (!isEmptyStack(temp)) {
        int bit;
        Pop(&temp, &bit);
        Push(&S, bit);
    }

    return valid;
}

void desimalKeBinerStack(int num, Stack *S) {
    CreateStack(S);
    if (num == 0) {
        Push(S, 0);
        return;
    }
    while (num > 0) {
        Push(S, num % 2);
        num /= 2;
    }
}

void binerKeDesimalStack(Stack *S, int *hasil) {
    *hasil = 0;
    int pangkat = 1;
    int bit;

    while (!isEmptyStack(*S)) {
        Pop(S, &bit);
        *hasil += bit * pangkat;
        pangkat *= 2;
    }
}

void tambahBinerStack(Stack *S1, Stack *S2, Stack *S3) {
    CreateStack(S3);
    int carry = 0, bit1, bit2, sum;

    Stack S1_temp, S2_temp, S_result;
    CreateStack(&S1_temp);
    CreateStack(&S2_temp);
    CreateStack(&S_result);

    // Salin stack asli ke stack sementara agar tidak kehilangan data asli
    while (!isEmptyStack(*S1)) {
        Pop(S1, &bit1);
        Push(&S1_temp, bit1);
    }
    while (!isEmptyStack(*S2)) {
        Pop(S2, &bit2);
        Push(&S2_temp, bit2);
    }

    // Proses penjumlahan bit per bit
    while (!isEmptyStack(S1_temp) || !isEmptyStack(S2_temp) || carry) {
        bit1 = isEmptyStack(S1_temp) ? 0 : Top(S1_temp);
        bit2 = isEmptyStack(S2_temp) ? 0 : Top(S2_temp);

        if (!isEmptyStack(S1_temp)) Pop(&S1_temp, &bit1);
        if (!isEmptyStack(S2_temp)) Pop(&S2_temp, &bit2);

        sum = bit1 + bit2 + carry;
        Push(&S_result, sum % 2);  // Simpan hasil penjumlahan (0 atau 1)
        carry = sum / 2;           // Hitung carry
    }

    // Memindahkan hasil dari S_result ke S3 agar urutan benar
    while (!isEmptyStack(S_result)) {
        Pop(&S_result, &bit1);
        Push(S3, bit1);
    }
}

void kurangBinerStack(Stack *S1, Stack *S2, Stack *S3) {
    int d1 = 0, d2 = 0;
    binerKeDesimalStack(S1, &d1);
    binerKeDesimalStack(S2, &d2);
    
    if (d1 < d2) {
        printf("Hasil negatif tidak didukung dalam biner!\n");
        return;
    }

    CreateStack(S3);
    desimalKeBinerStack(d1 - d2, S3);
}

void kaliBinerStack(Stack *S1, Stack *S2, Stack *S3) {
    int d1 = 0, d2 = 0;
    binerKeDesimalStack(S1, &d1);
    binerKeDesimalStack(S2, &d2);
    CreateStack(S3);
    desimalKeBinerStack(d1 * d2, S3);
}

void bagiBinerStack(Stack *S1, Stack *S2, Stack *S3) {
    int d1 = 0, d2 = 0;
    binerKeDesimalStack(S1, &d1);
    binerKeDesimalStack(S2, &d2);
    CreateStack(S3);
    if (d2 != 0) {
        desimalKeBinerStack(d1 / d2, S3);
    } else {
        printf("Kesalahan! Pembagian dengan nol tidak diperbolehkan.\n");
    }
}

void NOTBinerStack(Stack *S1, Stack *S2) {
    CreateStack(S2);
    Stack temp;
    CreateStack(&temp);
    
    while (!isEmptyStack(*S1)) {
        int bit;
        Pop(S1, &bit);
        Push(&temp, bit);
        Push(S2, bit == 0 ? 1 : 0);
    }
}

void ANDBinerStack(Stack *S1, Stack *S2, Stack *S3) {
    CreateStack(S3);
    Stack temp1, temp2;
    CreateStack(&temp1);
    CreateStack(&temp2);

    while (!isEmptyStack(*S1) && !isEmptyStack(*S2)) {
        int b1, b2;
        Pop(S1, &b1);
        Pop(S2, &b2);
        Push(&temp1, b1);
        Push(&temp2, b2);
        Push(S3, b1 & b2);
    }

    while (!isEmptyStack(temp1)) {
        int bit;
        Pop(&temp1, &bit);
        Push(S1, bit);
    }

    while (!isEmptyStack(temp2)) {
        int bit;
        Pop(&temp2, &bit);
        Push(S2, bit);
    }
}

void ORBinerStack(Stack *S1, Stack *S2, Stack *S3) {
    CreateStack(S3);
    Stack temp1, temp2;
    CreateStack(&temp1);
    CreateStack(&temp2);

    while (!isEmptyStack(*S1) && !isEmptyStack(*S2)) {
        int b1, b2;
        Pop(S1, &b1);
        Pop(S2, &b2);
        Push(&temp1, b1);
        Push(&temp2, b2);
        Push(S3, b1 | b2);
    }

    while (!isEmptyStack(temp1)) {
        int bit;
        Pop(&temp1, &bit);
        Push(S1, bit);
    }

    while (!isEmptyStack(temp2)) {
        int bit;
        Pop(&temp2, &bit);
        Push(S2, bit);
    }
}

void XORBinerStack(Stack *S1, Stack *S2, Stack *S3) {
    CreateStack(S3);
    Stack temp1, temp2;
    CreateStack(&temp1);
    CreateStack(&temp2);

    while (!isEmptyStack(*S1) && !isEmptyStack(*S2)) {
        int b1, b2;
        Pop(S1, &b1);
        Pop(S2, &b2);
        Push(&temp1, b1);
        Push(&temp2, b2);
        Push(S3, b1 ^ b2);
    }

    while (!isEmptyStack(temp1)) {
        int bit;
        Pop(&temp1, &bit);
        Push(S1, bit);
    }

    while (!isEmptyStack(temp2)) {
        int bit;
        Pop(&temp2, &bit);
        Push(S2, bit);
    }
}

