#include <stdio.h>
#include <stdlib.h>
#include "CUnit.h"
#include "Basic.h"
#include "blocksWorld.h"

void test00(void){
  CU_ASSERT_EQUAL(0,0);
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
