LDFLAGS := -L munit
LDLIBS := -lm

test_arithmetic: arithmetic.o test_arithmetic.o munit/munit.o
	$(CC) $(LDFLAGS) $(LDLIBS) -o $@ $^

arithmetic.o: munit/munit.h

munit/munit.h:
	git clone https://github.com/nemequ/munit.git munit

.PHONY: mostlyclean
mostlyclean:
	$(RM) *.o

.PHONY: clean
clean: mostlyclean
	$(RM) -r munit
	$(RM) test_arithmetic

.PHONY: lint
lint: cpplint cppcheck

.PHONY: cppcheck
cppcheck: arithmetic.c arithmetic.h
	cppcheck --error-exitcode=1 --enable=style $^

.PHONY: cpplint
cpplint: arithmetic.c arithmetic.h
	cpplint $^

.PHONY: test
test: test_arithmetic
	./test_arithmetic
