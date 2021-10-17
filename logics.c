#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <stddef.h>

wchar_t map[] =
{   'a', '_', 'c', 'd', 'e', 'f', 'a', 'i', 'j', 'k', 'l', 't', 'm', 'n', 'o', 'p', 
    'w', 'z', 's', 't', 'u', 'e', 'a', 'b', 'e', 'z', '0', '1', '2', '0', '0', '0', 
    '6', '7', '8', '9', '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 
    'n', 'o', 'o', 'o', 'd', 't', 'd', 'v', 'w', '0', '0', '0', 'e', 't', 'a', '?', 
    'T', '!', 'V', 'W', '0', '0', 'Y', '!', 'E', 'T', 'A', '?', '*', '-', '+', '/', 
    '{', '}', '[', ']', '=', '&', '%', '£', '"', '!', '(', ')', 'a', 'b', 'c', 'd', 
    'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 'A', 
    'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'N', 'M', 'u', 'u', 'u', 
    'v', 'w', 'x', 'i', 'p', 's', 'i', 'l', 'o', 'n', 'n', 'n', 'n', 'n', 'n', 'z', 
    '%', '%', '/', '9', '8', '7', '6', '5', '4', '3', '2', '1', '0', '|', '!', '"', 
    '£', '$', 'o', 'h', 'd', 'e', 'a', 'r', '!', '%', '&', '/', '(', '(', '(', '(', 
    ')', '*', ';', ':', '_', 'A', 'A', 'A', 'A', 'B', 'S', 'I', 'D', 'E', 'O', 'W', 
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', 
    '6', '7', '8', '?', '8', '?', '8', '?', '8', '?', '9', '!', '!', '!', '!', '!', 
    'E', 'G', 'I', 'N', '.', 'C', 'E', 'R', 'T', 'I', 'F', 'I', 'C', 'A', 'T', 'E', 
    'a', '_', 'c', 'd', 'e', 'f', 'a', 'i', 'j', 'k', 'l', 't', 'm', 'n', 'o', 'p', 
    'w', 'z', 's', 't', 'u', 'e', 'a', 'b', 'e', 'z', '0', '1', '2', '0', '0', '0', 
    '6', '7', '8', '9', '0', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 
    'n', 'o', 'o', 'o', 'd', 't', 'd', 'v', 'w', '0', '0', '0', 'e', 't', 'a', '?', 
    'T', '!', 'V', 'W', '0', '0', 'Y', '!', 'E', 'T', 'A', '?', '*', '-', '+', '/', 
    '{', '}', '[', ']', '=', '&', '%', '£', '"', '!', '(', ')', 'a', 'b', 'c', 'd', 
    'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 'A', 
    'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'N', 'M', 'u', 'u', 'u', 
    'v', 'w', 'x', 'i', 'p', 's', 'i', 'l', 'o', 'n', 'n', 'n', 'n', 'n', 'n', 'z',
    '%', '%', '/', '9', '8', '7', '6', '5', '4', '3', '2', '1', '0', '|', '!', '"', 
    '£', '$', 'o', 'h', 'd', 'e', 'a', 'r', '!', '%', '&', '/', '(', '(', '(', '(', 
    ')', '*', ';', ':', '_', 'A', 'A', 'A', 'A', 'B', 'S', 'I', 'D', 'E', 'O', 'W', 
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', 
    '6', '7', '8', '?', '8', '?', '8', '?', '8', '?', '9', '!', '!', '!', '!', '!', 
    'E', 'G', 'I', 'N', '.', 'C', 'E', 'R', 'T', 'I', 'F', 'I', 'C', 'A', 'T', 'E'
    };

char dec2bin_tab0[10];
char dec2bin_tab1[10];

/*
 * dec2bin
 */
char *
dec2bin(unsigned short in, char *s)
{
  for (int i = 8; i >= 0; i--)
    {
      s[i] = '0' + in %2;
      in = in/2;
    }
  return s;
}

/*
 * getbit
 */
unsigned char
getbit(unsigned short in, int b)
{
  return ((in & (1 << b)) != 0);
}

/*
 * setbit
 */
unsigned short
setbit(unsigned short in, int b)
{
  return (in | (1 << b));
}

/*
 * lsb_add
 */
unsigned char
lsb_add(unsigned char a1, unsigned char a2, unsigned char a3)
{
  unsigned char r = a1 + a2 + a3;
  return r & 1;
}

/*
 * msb_add
 */
unsigned char
msb_add(unsigned char a1, unsigned char a2, unsigned char a3)
{
  unsigned char r = a1 + a2 + a3;
  return (r & 2)/2;
}

/*
 * logic
 */
unsigned short logic(unsigned short in)
{
  /* Get input from input arg */
  unsigned short in0 = getbit(in, 0);
  unsigned short in1 = getbit(in, 1);
  unsigned short in2 = getbit(in, 2);
  unsigned short in3 = getbit(in, 3);
  unsigned short in4 = getbit(in, 4);
  unsigned short in5 = getbit(in, 5);
  unsigned short in6 = getbit(in, 6);
  unsigned short in7 = getbit(in, 7);
  unsigned short in8 = getbit(in, 8);

  /* Compute each bit from input and logic circuit */
  unsigned short out5 = in0;
  unsigned short out1 = in5;
  unsigned short out3 = lsb_add(in2, in3, in4);
  unsigned short out6 = in0 ^ in5;
  unsigned short out8 = in8 ^ out6;
  unsigned short out7 = in1 & in7;
  unsigned short out2 = in6 ^ msb_add(in2, in3, in4);  
  unsigned short out0 = in8 ^ out2;
  unsigned short out4 = lsb_add(in2, in3, in4) | !in5 | in0;

  /* Put back result in the return arg */
  unsigned short out = 0;
  if (out0) out = setbit(out, 0);
  if (out1) out = setbit(out, 1);
  if (out2) out = setbit(out, 2);
  if (out3) out = setbit(out, 3);
  if (out4) out = setbit(out, 4);
  if (out5) out = setbit(out, 5);
  if (out6) out = setbit(out, 6);
  if (out7) out = setbit(out, 7);
  if (out8) out = setbit(out, 8);

  /* Return result value */
  return out;
}

#ifndef TESTS
int main(int argc, char **argv)
{
  unsigned short in = 0, out = 0;
  int n = 10;
  char flag[11];
  bzero(dec2bin_tab0, 10);
  bzero(dec2bin_tab1, 10);
  bzero(flag, 11);

  do
    {
      printf("in[%03d] = %9s  ", 10-n, dec2bin(in, dec2bin_tab0));
      out = logic(in);
      flag[10-n] = map[out];
      printf("out[%03d] = %9s (%03d) flag[%d] = '%c'\n", 10-n, dec2bin(out, dec2bin_tab0), out, 10-n, flag[10-n]);
      in = out;
    }
  while(--n);
  printf("flag = {FLG:%s}\n", flag);

  exit(0);
}
#endif

