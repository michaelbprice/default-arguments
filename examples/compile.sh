#!/bin/bash

: ${FAIL:=0}

COMMAND=`grep "GCC>" $1.cpp | sed 's/\/\/ GCC> //'`
echo "Compiling : $COMMAND -DFAIL=$FAIL -o $1.out $1.cpp"
`$COMMAND -DFAIL=$FAIL -o $1.out $1.cpp`
echo "Running : $1.out"
`./$1.out`

