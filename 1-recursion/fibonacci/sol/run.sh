#!/bin/bash

if [ "$1" == "zip" ]; then
  zip -R att/testdata.zip input/* output/*
elif [ "$1" == "solution" ]; then

  for f in $(ls ../input/input*.txt); do
    out=${f//input/output}
    ./solution < $f > $out
  done

else
  echo "[Usage]";
  echo "   ./run.sh zip - zip all data into attachments.";
  echo "   ./run.sh solution - use ./solution to generate all output.";
fi
