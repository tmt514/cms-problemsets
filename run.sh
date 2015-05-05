#!/bin/bash

if [ "$1" == "zip" ]; then
  zip -R attachment/testdata.zip testdata
elif [ "$1" == "solution" ]; then

  for f in $(ls testdata/*.in); do
    out=${f/%in/out}
    ./judge/solution < $f > $out
  done

elif [ "$1" == "description" ]; then
  if [ -f description/header.tex ]; then
    HEADER="-H description/header.tex"
  else
    HEADER=
  fi
  pandoc $HEADER description/description.md -o description/description.pdf
  if [ $? == 0 ]; then
    scp description/description.pdf tmt514@icpc.csie.org:./public_html
  fi
elif [ "$1" == "statement" ]; then
  if [ -f description/header.tex ]; then
    HEADER="-H description/header.tex"
  else
    HEADER=
  fi
  pandoc $HEADER description/statement.md -o description/description.pdf
  if [ $? == 0 ]; then
    scp description/statement.pdf tmt514@icpc.csie.org:./public_html
  fi
else
  echo "[Usage]";
  echo "   ./run.sh zip - zip all data into attachments.";
  echo "   ./run.sh solution - use ./solution to generate all output.";
  echo "   ./run.sh description - use description/description.md to generate pdf.";
  echo "   ./run.sh statement - use description/statement.md to generate pdf.";
fi
