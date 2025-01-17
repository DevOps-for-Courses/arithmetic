#include "munit/munit.h"

#include "arithmetic.h"

/*
 * The following tests are deterministic, checking all pairs of the values (in
 * { 0.0, 1.0, 2.0, 0.5, and -1.0 }) for each arithmetic operation.
 */

const double values[] = { 0.0, 1.0, 2.0, 0.5, -1.0 };
const int num_values = sizeof(values) / sizeof(double);

MunitResult test_add_deterministic(const MunitParameter params[],
                                   void *user_data_or_fixture) {
  for (int i = 0; i < num_values; i++) {
    for (int j = 0; j < num_values; j++) {
      double x = values[i];
      double y = values[j];

      munit_assert_double_equal(add(x, y), x + y, 6);
    }
  }

  return MUNIT_OK;
}

MunitResult test_sub_deterministic(const MunitParameter params[],
                                   void *user_data_or_fixture) {
  for (int i = 0; i < num_values; i++) {
    for (int j = 0; j < num_values; j++) {
      double x = values[i];
      double y = values[j];

      munit_assert_double_equal(subtract(x, y), x - y, 6);
    }
  }

  return MUNIT_OK;
}

MunitResult test_mul_deterministic(const MunitParameter params[],
                                   void *user_data_or_fixture) {
  for (int i = 0; i < num_values; i++) {
    for (int j = 0; j < num_values; j++) {
      double x = values[i];
      double y = values[j];

      munit_assert_double_equal(multiply(x, y), x * y, 6);
    }
  }

  return MUNIT_OK;
}

MunitResult test_div_deterministic(const MunitParameter params[],
                                   void *user_data_or_fixture) {
  for (int i = 0; i < num_values; i++) {
    for (int j = 0; j < num_values; j++) {
      double x = values[i];
      double y = values[j];

      munit_assert_double_equal(divide(x, y), x / y, 6);
    }
  }

  return MUNIT_OK;
}

/*
 * The following tests are randomized, performing each operation using two
 * randomly selected values. (These tests should be run using multiple
 * iterations.)
 */

MunitResult test_add_random(const MunitParameter params[],
                            void* user_data_or_fixture) {
  const double x = munit_rand_double();
  const double y = munit_rand_double();
  munit_assert_double_equal(add(x, y), x + y, 6);

  return MUNIT_OK;
}

MunitResult test_sub_random(const MunitParameter params[],
                            void *user_data_or_fixture) {
  const double x = munit_rand_double();
  const double y = munit_rand_double();
  munit_assert_double_equal(subtract(x, y), x - y, 6);

  return MUNIT_OK;
}

MunitResult test_mul_random(const MunitParameter params[],
                            void *user_data_or_fixture) {
  const double x = munit_rand_double();
  const double y = munit_rand_double();
  munit_assert_double_equal(multiply(x, y), x * y, 6);

  return MUNIT_OK;
}

MunitResult test_div_random(const MunitParameter params[],
                            void *user_data_or_fixture) {
  const double x = munit_rand_double();
  const double y = munit_rand_double();
  munit_assert_double_equal(divide(x, y), x / y, 6);

  return MUNIT_OK;
}

/*
 * test runner
 */

int main(int argc, char *argv[]) {
  // entries: { name, test, setup, teardown, options, parameters }
  MunitTest addition[] = {
    { "/deterministic", test_add_deterministic, NULL, NULL,
      MUNIT_TEST_OPTION_SINGLE_ITERATION, NULL },
    { "/randomized", test_add_random, NULL, NULL,
      MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  };
  MunitTest subtraction[] = {
    { "/deterministic", test_sub_deterministic, NULL, NULL,
      MUNIT_TEST_OPTION_SINGLE_ITERATION, NULL },
    { "/randomized", test_sub_random, NULL, NULL,
      MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  };
  MunitTest multiplication[] = {
    { "/deterministic", test_mul_deterministic, NULL, NULL,
      MUNIT_TEST_OPTION_SINGLE_ITERATION, NULL },
    { "/randomized", test_mul_random, NULL, NULL,
      MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  };
  MunitTest division[] = {
    { "/deterministic", test_div_deterministic, NULL, NULL,
      MUNIT_TEST_OPTION_SINGLE_ITERATION, NULL },
    { "/randomized", test_div_random, NULL, NULL,
      MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  };

  // entries: { name, tests, suites, iterations, options }
  MunitSuite suites[] = {
    { "/add", addition, NULL, 1, MUNIT_SUITE_OPTION_NONE },
    { "/subtract", subtraction, NULL, 1, MUNIT_SUITE_OPTION_NONE },
    { "/multiply", multiplication, NULL, 1, MUNIT_SUITE_OPTION_NONE },
    { "/divide", division, NULL, 1, MUNIT_SUITE_OPTION_NONE },
    { NULL, NULL, NULL, 0, MUNIT_SUITE_OPTION_NONE },
  };
  MunitSuite suite =
    { "arithmetic", NULL, suites, 1000000, MUNIT_SUITE_OPTION_NONE };

  return munit_suite_main(&suite, NULL, argc, argv);
}
