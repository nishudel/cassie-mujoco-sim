function qd = qdcalc(t,params,k)
s=0;
for j=0:4
   s=s+(params(k,j+2)-params(k,j+1))*(factorial(5)/(factorial(j)*factorial(5-j-1)))*(t^(j))*((1-t)^(5-j-1));
end
qd=s/0.4;
end