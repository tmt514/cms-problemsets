unit graderlib;

interface 

procedure reportAnswer(a, b : LongInt);

implementation

procedure reportAnswer(a, b : LongInt);
begin
    writeln(a, ' ', b);
end;

end.
