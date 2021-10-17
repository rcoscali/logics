/*
 * Declarations for logics.c utilities funcs
 *
 */
#ifndef _LOGICS_H_
#define _LOGICS_H_

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <stddef.h>
  
  extern wchar_t map[];
  extern char dec2bin_tab0[10];
  extern char dec2bin_tab1[10];
  
  char *dec2bin(unsigned short in, char *s);
  unsigned char getbit(unsigned short in, int b);
  unsigned short setbit(unsigned short in, int b);
  unsigned char lsb_add(unsigned char a1, unsigned char a2, unsigned char a3);
  unsigned char msb_add(unsigned char a1, unsigned char a2, unsigned char a3);
  unsigned short logic(unsigned short in);
  
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _LOGICS_H_ */
