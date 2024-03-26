#! /bin/bash

pdftk $1 dump_data | grep 'NumberOfPages' | sed 's/^\w\+: //' > info.txt
pdftk $1 dump_data | grep -A1 -B1 'BookmarkLevel: 1' | grep -v 'BookmarkLevel: 1' | sed 's/^\w\+: //' | sed '/--/d' >> info.txt

g++ book.cpp

./a.out | sed "s/^/\.\/p $1 /" 
