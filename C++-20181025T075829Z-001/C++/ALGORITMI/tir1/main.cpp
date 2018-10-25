{Solutie propusa de comisie}
const MaxN=1000;
var v:
array[1..maxn]of word;
c,d:
array[0..maxn] of word;
n,i,j,k:
longint;
operatii:
boolean;
f:
text;
procedure citire;
begin
assign(f,'tir1.in');
reset(f);
readln(f,n);
readln(f,k);
for i:
    =1 to n do
         if not seekeoln(f) then read(f,v[i]);
close(f);
end;
procedure ordonare;
var aux:
word;
p, q, t:
word;
begin
p:
    =n;
repeat
q:
    =0;
for t:
    =1 to p-1 do
         if v[t]>v[t+1] then begin
     aux:
                 =v[t];
v[t]:
    =v[t+1];
v[t+1]:
    =aux;
q:
    =t;
end;
p:
    =q;
until p=0;
end;

procedure calcul;
begin
c[0]:
    =1;
for j:
    =1 to n do
     for i:
             =0 to k-v[j] do
                      if c[i]>0 then
                          if (c[i+v[j]]>c[i]+1)or(c[i+v[j]]=0) then
                              begin
      c[i+v[j]]:
                              =c[i]+1;
d[i+v[j]]:
    =i;
end;
end;

procedure afis(p:word);
begin
if p<>0 then begin
afis(d[p]);
write(f, p-d[p],' ');
end;
end;

begin
citire;
ordonare;
calcul;
assign(f, 'tir1.out');
rewrite(f);
if c[k]=0 then write(f,0)
            else begin
                writeln(f, c[k]-1);
afis(k);
end;

close(f);
end.
