#include <stdio.h>
#include <math.h>
#include <time.h>
#include <headers_for_hash.h>


void test_for_hash_for_idx();
void test_for_super_power();

//This test is made not by randomizer
void test_for_hash_for_idx() {
  int counter = 0;
  int test[10] = {560, 21256, 26339, 26533, 33387, 34716, 50818, 64331, 66538, 85982};
  int ans_for_test[10] = {51611, 19036008, 430514, 450910, 6332511, 7402908, 21276701, 10572491, 12653502, 5882297};

  for(int i = 0; i < 10; ++i) {
    if (hash_for_idx(test[i]) != ans_for_test[i])
      printf("Test #%d doesn't work, val we got is %d, val we should get is %d\n", i, hash_for_idx(test[i]), ans_for_test[i]);
    else
      counter++;
  }
  printf("Testing has ended\n");
  if(counter != 10)
    printf("Some tests didn't work(\n");
}

//This test is checking our powering prog

void test_for_super_power() {
  int a, b;
  int mod = 23767001, precision = 1e-9;
  int n_el = 100000, i;
  int *arr_of_meanings, *arr_of_powers;

  srand(time(NULL));
  arr_of_meanings = (int*)calloc(n_el, sizeof(int));
  arr_of_powers = (int*)calloc(n_el, sizeof(int));

  for(i = 0; i < n_el; ++i) {
    arr_of_meanings[i] = rand()%101 + 1;
    arr_of_powers[i] = rand()%5;
  }

  for(i = 0; i < n_el; ++i) {
    a = pow(arr_of_meanings[i], arr_of_powers[i]);
    a = a % mod;
    b = super_power(arr_of_powers[i], arr_of_meanings[i], mod);

    if(a != b) {
      printf("Test # %d didn't work. Number is %d, power is %d. Meaning from computer is %d, meaning from my func is %d", i, arr_of_meanings[i], arr_of_powers[i], a, b);
    }
  }

  free(arr_of_meanings);
  free(arr_of_powers);
}

