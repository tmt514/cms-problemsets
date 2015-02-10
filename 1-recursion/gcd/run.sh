#!/bin/bash

if [ "$1" == "zip" ]; then
  zip -R att/testdata.zip input/* output/*
elif [ "$1" == "solution" ]; then

  for f in $(ls input/input*.txt); do
    out=${f//input/output}
    sol/solution < $f > $out
  done

elif [ "$1" == "statement" ]; then
  pandoc statement/statement.md -o statement/statement.pdf

else
  echo "[Usage]";
  echo "   ./run.sh zip - zip all data into attachments.";
  echo "   ./run.sh solution - use ./solution to generate all output.";
  echo "   ./run.sh statement - use statement/statement.md to generate pdf.";
fi
