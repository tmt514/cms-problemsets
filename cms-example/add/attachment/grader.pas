program grader;

uses add;

var
    a, b, ans: longint;

begin
    read(a, b);
    ans := addTwoNumbers(a, b);
    writeln(ans);
end.

