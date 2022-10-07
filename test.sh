#!/bin/sh
if test ! -f test; then
	./build.sh
fi
out=`echo "Hello, 世界" | ./test`
if test "$out" = "Hello, [世][界]"; then
	echo "test passed"
else
	echo "test fail"
fi
