#!/bin/sh

../src/skeleton -h
if [ $? != 0 ]
then
	exit 1
fi
../src/skeleton --help
exit $?
