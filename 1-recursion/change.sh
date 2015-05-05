TASK=$1

mv $TASK/sol $TASK/judge
mv $TASK/input $TASK/testdata
for f in $(ls $TASK/testdata/input*.txt); do
  g=${f//input/test};
  mv $f $g;
  mv $g ${g//txt/in};
done

mv $TASK/output $TASK/pout
for f in $(ls $TASK/pout/output*.txt); do
  g=${f/pout/testdata};
  g=${g/output/test};
  g=${g//txt/out};
  mv $f $g;
done

mv $TASK/att $TASK/attachment
mv $TASK/statement $TASK/description
