# Arithmetic

We're all familiar with basic arithmetic operations -- addition, subtraction,
multiplication, and division. The C programming language supports these operations using their customary operators (+, -, *, and /).

This exercise is designed to demonstrate [GitHub Classroom], particularly
automated feedback. This repository includes starter code and unit tests for
the aforementioned arithmetic functions. Completing the assignment requires
implementing these functions.

**Expected duration:** 1 hour (or less)

## Learning Objectives

* Demonstrate working knowledge of Git, including cloning a repository,
  committing changes, and sharing (i.e., `push`ing) those changes
* Use automated feedback to correct stylistic issues and implementation errors
  in source code

## Instructions

Use the provided link (distributed separately) to access this assignment in
[GitHub Classroom].

Implement the arithmetic functions in `arithmetic.c`. The functions are already
defined, but currently return incorrect values.

### Testing

Unit tests are provided to facilitate automated testing. Do **not** modify the
test code! A correct implementation of the functions will pass all the
automated tests.

To test your implementation locally, do the following (the command, prefixed by
a `$` signifying the terminal prompt, *and* its output are shown so you know
what to expect):

1. Compile the source code:

   ~~~ terminal
   $ make
   git clone https://github.com/nemequ/munit.git munit
   Cloning into 'munit'...
   remote: Enumerating objects: 615, done.
   remote: Total 615 (delta 0), reused 0 (delta 0), pack-reused 615 (from 1)
   Receiving objects: 100% (615/615), 245.72 KiB | 3.56 MiB/s, done.
   Resolving deltas: 100% (401/401), done.
   cc    -c -o arithmetic.o arithmetic.c
   cc    -c -o test_arithmetic.o test_arithmetic.c
   cc    -c -o munit/munit.o munit/munit.c
   cc -L munit -lm -o test_arithmetic arithmetic.o test_arithmetic.o munit/munit.o
   ~~~

2. Run the stylistic checks ([cpplint] and [cppcheck]):

   ~~~ terminal
   $ make lint
   cpplint arithmetic.c arithmetic.h
   Done processing arithmetic.c
   Done processing arithmetic.h
   cppcheck --error-exitcode=1 --enable=style arithmetic.c arithmetic.h
   Checking arithmetic.c ...
   1/2 files checked 64% done
   Checking arithmetic.h ...
   2/2 files checked 100% done
   ~~~

3. Run the unit tests:

   ~~~ terminal
   $ make test
   ./test_arithmetic
   Running test suite with seed 0xff12d712...
   arithmetic/add/deterministic         [ OK    ] [ 0.00000400 / 0.00000200 CPU ]
   arithmetic/add/randomized            [ OK    ] [ 0.00000033 / 0.00000033 CPU ]
                                           Total: [ 0.32583000 / 0.32515800 CPU ]
   arithmetic/subtract/deterministic    [ OK    ] [ 0.00000100 / 0.00000100 CPU ]
   arithmetic/subtract/randomized       [ OK    ] [ 0.00000031 / 0.00000031 CPU ]
                                           Total: [ 0.31326200 / 0.31345400 CPU ]
   arithmetic/multiply/deterministic    [ OK    ] [ 0.00000000 / 0.00000100 CPU ]
   arithmetic/multiply/randomized       [ OK    ] [ 0.00000031 / 0.00000031 CPU ]
                                           Total: [ 0.31006100 / 0.30980200 CPU ]
   arithmetic/divide/deterministic      [ OK    ] [ 0.00000100 / 0.00000100 CPU ]
   arithmetic/divide/randomized         [ OK    ] [ 0.00000031 / 0.00000031 CPU ]
                                           Total: [ 0.31290700 / 0.31244200 CPU ]
   8 of 8 (100%) tests successful, 0 (0%) test skipped.
   ~~~

Of course, the unit tests will **not** pass until you implement the required
functions!

## Submission

Create an archive of your Git repository (you can use GitHub's "Clone or
download" button when viewing your repository for this purpose) and submit that
archive using the LMS.

**Note:** GitHub Classroom revokes write access to the repository at the due
date for the assignment.

### Grading

The following grading rubric will be used for this assignment:

| Item | Points |
| :--- | -----: |
| Unit Tests (8 @ 1 point each) | 8 |
| Stylistic Checks | 2 |

No partial credit will be awarded for failed tests, including the stylistic
checks, although it will be awarded for individual tests. For example, if you
pass 4 of 8 unit tests, then you will earn 4 points.

### Automated Tests

GitHub Actions tests your code when you push your changes to GitHub (i.e.,
continuous integration (CI)). The entire class shares the resources provided
for automated grading. You should test locally *before* pushing to GitHub.

To encourage judicious use of shared resources, a **1-point penalty** will be
applied for *each* workflow execution in excess of 10 runs. This penalty deters
the excessive use of shared resources, particularly when you can perform the
automated tests locally. You can check the number of workflow runs by clicking
on the "Actions" tab of your GitHub repository.

You should complete this assignment at least one day prior to the due date so
that you have time to resolve any failures in the automated tests. If you have
questions regarding how to interpret their output, you should contact your
instructor.

[cppcheck]: https://cppcheck.sourceforge.io/
[cpplint]: https://github.com/cpplint/cpplint
[GitHub Classroom]: https://classroom.github.com/
