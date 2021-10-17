#include <stdio.h>
#include <stdlib.h>

#include "gtest/gtest.h"

#include "logics.h"

#include "test_dec2bin.h"

/*
 * Unit test for dec2bin
 */
TEST(UnitTests, test_dec2bin)
{
  for (int i = 0; i < 512; i++)
    {
      char *r = dec2bin(i, dec2bin_tab0);
      printf("dec2bin(%03d) = %9s\n", i, r);
      EXPECT_STREQ(r, test_dec2bin_res_str[i]);
    }
}

/*
 * Unit test for getbit
 */
TEST(UnitTests, test_getbit)
{
  printf("getbit(357, 0) [%9s] = %d\n", dec2bin(357, dec2bin_tab0), getbit(357, 0));
  EXPECT_EQ(getbit(357, 0), 1);
  
  printf("getbit(357, 1) [%9s] = %d\n", dec2bin(357, dec2bin_tab0), getbit(357, 1));
  EXPECT_EQ(getbit(357, 1), 0);
  
  printf("getbit(357, 2) [%9s] = %d\n", dec2bin(357, dec2bin_tab0), getbit(357, 2));
  EXPECT_EQ(getbit(357, 2), 1);
  
  printf("getbit(357, 3) [%9s] = %d\n", dec2bin(357, dec2bin_tab0), getbit(357, 3));
  EXPECT_EQ(getbit(357, 3), 0);
  
  printf("getbit(357, 4) [%9s] = %d\n", dec2bin(357, dec2bin_tab0), getbit(357, 4));
  EXPECT_EQ(getbit(357, 4), 0);
  
  printf("getbit(357, 5) [%9s] = %d\n", dec2bin(357, dec2bin_tab0), getbit(357, 5));
  EXPECT_EQ(getbit(357, 5), 1);
  
  printf("getbit(357, 6) [%9s] = %d\n", dec2bin(357, dec2bin_tab0), getbit(357, 6));
  EXPECT_EQ(getbit(357, 6), 1);
  
  printf("getbit(357, 7) [%9s] = %d\n", dec2bin(357, dec2bin_tab0), getbit(357, 7));
  EXPECT_EQ(getbit(357, 7), 0);
  
  printf("getbit(357, 8) [%9s] = %d\n", dec2bin(357, dec2bin_tab0), getbit(357, 8));
  EXPECT_EQ(getbit(357, 8), 1);
}

/*
 * Unit test for setbit
 */
TEST(UnitTests, test_setbit)
{
  printf("setbit(357, 0) [%9s] = %d [%9s]\n",
         dec2bin(357, dec2bin_tab0), setbit(357, 0), dec2bin(setbit(357, 0), dec2bin_tab1));
  EXPECT_EQ(setbit(357, 0), 357);
  
  printf("setbit(357, 1) [%9s] = %d [%9s]\n",
         dec2bin(357, dec2bin_tab0), setbit(357, 1), dec2bin(setbit(357, 1), dec2bin_tab1));
  EXPECT_EQ(setbit(357, 1), 359);

  printf("setbit(357, 2) [%9s] = %d [%9s]\n",
         dec2bin(357, dec2bin_tab0), setbit(357, 2), dec2bin(setbit(357, 2), dec2bin_tab1));
  EXPECT_EQ(setbit(357, 2), 357);

  printf("setbit(357, 3) [%9s] = %d [%9s]\n",
         dec2bin(357, dec2bin_tab0), setbit(357, 3), dec2bin(setbit(357, 3), dec2bin_tab1));
  EXPECT_EQ(setbit(357, 3), 365);

  printf("setbit(357, 4) [%9s] = %d [%9s]\n",
         dec2bin(357, dec2bin_tab0), setbit(357, 4), dec2bin(setbit(357, 4), dec2bin_tab1));
  EXPECT_EQ(setbit(357, 4), 373);

  printf("setbit(357, 5) [%9s] = %d [%9s]\n",
         dec2bin(357, dec2bin_tab0), setbit(357, 5), dec2bin(setbit(357, 5), dec2bin_tab1));
  EXPECT_EQ(setbit(357, 5), 357);

  printf("setbit(357, 6) [%9s] = %d [%9s]\n",
         dec2bin(357, dec2bin_tab0), setbit(357, 6), dec2bin(setbit(357, 6), dec2bin_tab1));
  EXPECT_EQ(setbit(357, 6), 357);

  printf("setbit(357, 7) [%9s] = %d [%9s]\n",
         dec2bin(357, dec2bin_tab0), setbit(357, 7), dec2bin(setbit(357, 7), dec2bin_tab1));
  EXPECT_EQ(setbit(357, 7), 485);

  printf("setbit(357, 8) [%9s] = %d [%9s]\n",
         dec2bin(357, dec2bin_tab0), setbit(357, 8), dec2bin(setbit(357, 8), dec2bin_tab1));
  EXPECT_EQ(setbit(357, 8), 357);
}

/*
 * Unit test for msb_add
 */
TEST(UnitTests, test_msb_add)
{
  printf("msb_add(0,0,0) = %d\n", msb_add(0,0,0)); EXPECT_EQ(msb_add(0,0,0), 0);
  printf("msb_add(0,0,1) = %d\n", msb_add(0,0,1)); EXPECT_EQ(msb_add(0,0,1), 0);
  printf("msb_add(0,1,0) = %d\n", msb_add(0,1,0)); EXPECT_EQ(msb_add(0,1,0), 0);
  printf("msb_add(0,1,1) = %d\n", msb_add(0,1,1)); EXPECT_EQ(msb_add(0,1,1), 1);
  printf("msb_add(1,0,0) = %d\n", msb_add(1,0,0)); EXPECT_EQ(msb_add(1,0,0), 0);
  printf("msb_add(1,0,1) = %d\n", msb_add(1,0,1)); EXPECT_EQ(msb_add(1,0,1), 1);
  printf("msb_add(1,1,0) = %d\n", msb_add(1,1,0)); EXPECT_EQ(msb_add(1,1,0), 1);
  printf("msb_add(1,1,1) = %d\n", msb_add(1,1,1)); EXPECT_EQ(msb_add(1,1,1), 1);
}

/*
 * Unit test for lsb_add
 */
TEST(UnitTests, test_lsb_add)
{
  printf("lsb_add(0,0,0) = %d\n", lsb_add(0,0,0)); EXPECT_EQ(lsb_add(0,0,0), 0);
  printf("lsb_add(0,0,1) = %d\n", lsb_add(0,0,1)); EXPECT_EQ(lsb_add(0,0,1), 1);
  printf("lsb_add(0,1,0) = %d\n", lsb_add(0,1,0)); EXPECT_EQ(lsb_add(0,1,0), 1);
  printf("lsb_add(0,1,1) = %d\n", lsb_add(0,1,1)); EXPECT_EQ(lsb_add(0,1,1), 0);
  printf("lsb_add(1,0,0) = %d\n", lsb_add(1,0,0)); EXPECT_EQ(lsb_add(1,0,0), 1);
  printf("lsb_add(1,0,1) = %d\n", lsb_add(1,0,1)); EXPECT_EQ(lsb_add(1,0,1), 0);
  printf("lsb_add(1,1,0) = %d\n", lsb_add(1,1,0)); EXPECT_EQ(lsb_add(1,1,0), 0);
  printf("lsb_add(1,1,1) = %d\n", lsb_add(1,1,1)); EXPECT_EQ(lsb_add(1,1,1), 1);
}

/*
 *
 */
TEST(UnitTests, test_logic)
{
#define TEST_LOGIC_TRY(vin,vout)                               \
  printf("in(%03d) = %9s  ", vin, dec2bin(vin, dec2bin_tab0));    \
  out = logic(vin);                                            \
  printf("out = %9s (%03d)\n", dec2bin(out, dec2bin_tab0), vout); \
  EXPECT_EQ(out, vout);
         
  unsigned short out;

  // Random
  TEST_LOGIC_TRY(357,318);
  TEST_LOGIC_TRY(511,443);
  TEST_LOGIC_TRY(1,368);
  // From 0 ten times
  TEST_LOGIC_TRY(0,16);
  TEST_LOGIC_TRY(16,24);
  TEST_LOGIC_TRY(24,21);
  TEST_LOGIC_TRY(21,373);
  TEST_LOGIC_TRY(373,307);

  TEST_LOGIC_TRY(307,315);
  TEST_LOGIC_TRY(315,310);
  TEST_LOGIC_TRY(310,70);
  TEST_LOGIC_TRY(70,29);
  TEST_LOGIC_TRY(29,381);

         
}

/*
 * Entry point for test_logics
 */
int
main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
