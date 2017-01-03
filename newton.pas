program Newton_raphson;
uses crt;
label ulang;
var
x, x1, y, y1, z, f, f1, f2 : real;
i:integer;
ab : char;
begin
ulang:
clrscr;
repeat
begin
writeln('tentukan akar persamaan dari (x)=3x+sin(x)+exp x dengan metode newton raphson');
writeln;
write('masukan nilai x1= ');
readln(x1);
y1 := 3 * x1+ sin(x1) - exp(x1);
f1 := 3 + cos(x1) - exp(x1);
f2 := -sin(x1) - exp(x1);
z :=(y1*f2)/(f1*f1);
writeln('nilai f(x1) = ',y1:0:5);
writeln('nilai f^(x1) = ',f1:0:5);
writeln('nilai f^^(x1) = ',f2:0:5);
if abs(z) < 1 then
writeln('nilai x1 OK (',z:0:5,') <1');
end;
until abs(z)<1;
readln;
i := 1;
writeln('penyelesaian persamaan karakteristik dengan  newton raphson');
writeln('-----------------------------------------------------------');
writeln('      n                  x          F(x)             error ');
repeat
begin
i:= i + 1 ; x := x1-(y1/f1);
y:= 3* x + sin(x) - exp(x);
f:= 3 + cos(x) -exp(x);
if i < 10 then
writeln('::',i,'::',x,'::',y,'::',abs(y),':')
else
writeln('::',i,'::',x,'::',y,'::',abs(y),':');
x1:= x;
y1:= y;
f1:=f;
end;
until abs(y) < 1E-08;
writeln('--------------------------------------------------------------');
writeln('akar persamaannya x= ',x);
writeln('errornya = ',abs(y));
write('apakah anda ingin mengulanginuya (y/t) =');
readln(ab);
if (ab='y') or (ab='Y') then
begin
goto ulang;
end
end.
