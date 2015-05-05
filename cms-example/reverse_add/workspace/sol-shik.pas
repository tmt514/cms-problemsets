unit reverse_add;

interface

procedure reverseAdd(x : LongInt);

implementation

uses graderlib;

procedure reverseAdd(x : LongInt);
begin
    reportAnswer(1, x - 1);
end;

end.

