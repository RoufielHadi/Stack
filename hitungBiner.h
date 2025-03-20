/*
Author: Roufiel Hadi
NIM: 241524028
Kelas: 1A
Prodi: Sarjana Terapan Teknik Informatika
Jurusan: Teknik Komputer dan Informatika
Politeknik Negeri Bandung
*/

#ifndef BILANGANBINER_H
#define BILANGANBINER_H

#include <stdio.h>
#include "boolean.h"
#include "stack.h"

boolean isBinerStack(Stack S);
/* Tujuan : Memvalidasi apakah angka dalam stack merupakan bilangan biner atau tidak */
/* Parameter : S (input) */
/* Mengembalikan true jika bilangan hanya terdiri dari 0 dan 1, false jika tidak */

void desimalKeBinerStack(int num, Stack *S);
/* Tujuan : Mengubah bilangan desimal ke bilangan biner dalam bentuk stack */
/* Parameter : num (input), S (output) */

void binerKeDesimalStack(Stack *S, int *hasil);
/* Tujuan : Mengubah bilangan biner dalam stack ke bilangan desimal */
/* Parameter : S (input-output), hasil (output) */

void modStack(Stack *S, int b);
/* Tujuan : Menghitung modulus dari dua bilangan dalam stack */
/* Parameter : S (input-output), b (input) */

void divStack(Stack *S, int b);
/* Tujuan : Menghitung hasil pembagian bulat dalam stack */
/* Parameter : S (input-output), b (input) */

void tambahBinerStack(Stack *S1, Stack *S2, Stack *S3);
/* Tujuan : Melakukan penjumlahan dua bilangan biner dalam bentuk stack */
/* Parameter : S1, S2 (input), S3 (output) */

void kurangBinerStack(Stack *S1, Stack *S2, Stack *S3);
/* Tujuan : Melakukan pengurangan dua bilangan biner dalam bentuk stack */
/* Parameter : S1, S2 (input), S3 (output) */

void kaliBinerStack(Stack *S1, Stack *S2, Stack *S3);
/* Tujuan : Melakukan perkalian dua bilangan biner dalam bentuk stack */
/* Parameter : S1, S2 (input), S3 (output) */

void bagiBinerStack(Stack *S1, Stack *S2, Stack *S3);
/* Tujuan : Melakukan pembagian dua bilangan biner dalam bentuk stack */
/* Parameter : S1, S2 (input), S3 (output) */

void NOTBinerStack(Stack *S1, Stack *S2);
/* Tujuan : Melakukan operasi NOT pada bilangan biner dalam stack */
/* Parameter : S1 (input), S2 (output) */

void ANDBinerStack(Stack *S1, Stack *S2, Stack *S3);
/* Tujuan : Melakukan operasi AND pada dua bilangan biner dalam stack */
/* Parameter : S1, S2 (input), S3 (output) */

void ORBinerStack(Stack *S1, Stack *S2, Stack *S3);
/* Tujuan : Melakukan operasi OR pada dua bilangan biner dalam stack */
/* Parameter : S1, S2 (input), S3 (output) */

void XORBinerStack(Stack *S1, Stack *S2, Stack *S3);
/* Tujuan : Melakukan operasi XOR pada dua bilangan biner dalam stack */
/* Parameter : S1, S2 (input), S3 (output) */

#endif
