#!/bin/sh
mini_paint $1 > out1.txt
aa	$1 > out2.txt
diff out1.txt out2.txt
