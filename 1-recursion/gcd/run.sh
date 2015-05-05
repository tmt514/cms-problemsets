#!/bin/bash

if [ "$1" == "zip" ]; then
  zip -R attachment/testdata.zip testdata
elif [ "$1" == "solution" ]; then

  for f in $(ls testdata/*.in); do
    out=${f/%in/out}
    ./judge/solution < $f > $out
  done

elif [ "$1" == "description" ]; then
  pandoc description/statement.md -o statement/statement.pdf

else
  echo "[Usage]";
  echo "   ./run.sh zip - zip all data into attachments.";
  echo "   ./run.sh solution - use ./solution to generate all output.";
  echo "   ./run.sh description - use ./solution to generate all output.";
fi
