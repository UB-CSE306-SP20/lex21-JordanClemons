#include <stdio.h>
#include <stdlib.h>
#include "CUnit.h"
#include "Basic.h"
#include "blocksWorld.h"

void test00(void){
  CU_ASSERT_EQUAL(0,0);
}

//Blackbox testing

void createTest(void){
  int * retVal = create(5);
  for(int x = 0; x < 5; x++){
    CU_ASSERT_EQUAL(*(retVal+x), 0);
  }
}

void onTableTest(void){
  int * createVal = create(5);
  bool retVal = onTable(0, createVal);
  CU_ASSERT_EQUAL(retVal, false);
  retVal = onTable(3, createVal);
  CU_ASSERT_EQUAL(retVal, true);
  retVal = onTable(6, createVal);
  CU_ASSERT_EQUAL(retVal, false);
  createVal = move(1,2, createVal);
  retVal = onTable(1, createVal);
  CU_ASSERT_EQUAL(retVal, false);
  retVal = onTable(2, createVal);
  CU_ASSERT_EQUAL(retVal, true);
  
}

void openTest(void){
  int * createVal = create(5);
  bool retVal = open(0, createVal);
  CU_ASSERT_EQUAL(retVal, true);
  for(int x = 0; x < 5; x++){
    retVal = open(x, createVal);
    CU_ASSERT_EQUAL(retVal, true);
  }
  createVal = move(2,3, createVal);
  retVal = open(3, createVal);
  CU_ASSERT_EQUAL(retVal, false);

}

void onTest(void){
  int * createVal = create(5);
  int retVal = on(6, createVal);
  CU_ASSERT_EQUAL(retVal, 6);
  for(int x = 0; x < 5; x++){
    retVal = on(x, createVal);
    CU_ASSERT_EQUAL(retVal, 0);
  }
  createVal = move(2,3, createVal);
  retVal = on(2, createVal);
  CU_ASSERT_EQUAL(retVal, 3);

}

void aboveTest(void){
  int * createVal = create(5);
  bool retVal = above(1,2, createVal);
  CU_ASSERT_EQUAL(retVal, false);
  createVal = move(1,2, createVal);
  retVal = above(1,2, createVal);
  CU_ASSERT_EQUAL(retVal, true);
  
}


/* The main() function for setting up and running the tests.
 * Returns a CUE_SUCCESS on successful running, another
 * CUnit error code on failure.
 */
int main()
{
  CU_pSuite Suite = NULL;

  /* initialize the CUnit test registry */
  if (CUE_SUCCESS != CU_initialize_registry()) { return CU_get_error(); }

  /* add a suite to the registry */
  Suite = CU_add_suite("Suite_of_tests_with_valid_inputs", NULL, NULL);
  if (NULL == Suite) {
    CU_cleanup_registry();
    return CU_get_error();
  }

  /* add the tests to Suite */
  if (
      (NULL == CU_add_test(Suite, "test 00", test00))
      ||(NULL == CU_add_test(Suite, "create test", createTest))
      ||(NULL == CU_add_test(Suite, "on table test", onTableTest))
      ||(NULL == CU_add_test(Suite, "open test", openTest))
      ||(NULL == CU_add_test(Suite, "on test", onTest))
      ||(NULL == CU_add_test(Suite, "above test", aboveTest))



       )
    {
      CU_cleanup_registry();
      return CU_get_error();
    }

  /* Run all tests using automated interface, with output to 'test-Results.xml' */
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();
  // CU_set_output_filename("test");
  // CU_automated_run_tests();

  CU_cleanup_registry();
  return CU_get_error();
}
