function q = qcalc(t,params,k)
s=0;
for j=0:5
   s=s+params(k,j+1)*(factorial(5)/(factorial(j)*factorial(5-j)))*(t^(j))*((1-t)^(5-j));
end
q=s;
end