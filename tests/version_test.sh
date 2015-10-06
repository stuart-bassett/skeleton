#!/bin/sh

../src/skeleton -v
if [ $? != 0 ]
then
	exit 1
fi
../src/skeleton --version
exit $?
