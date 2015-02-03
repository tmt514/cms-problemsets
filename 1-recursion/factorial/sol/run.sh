#!/bin/bash

for f in $(ls ../input/input*.txt); do
  out=${f//input/output}
  ./factorial < $f > $out
done
