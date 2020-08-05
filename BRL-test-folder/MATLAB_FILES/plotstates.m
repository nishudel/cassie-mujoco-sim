clear all 
clc
s=load('GaitLibrary_v1.mat');
params=zeros(10,6);

k=1;
for j=1:6
    for i=1:10
         params(i,j)= s.GaitLibrary{1,9}.opt.params{3,1}.atime(k);
         k=k+1;
    end
end 

t=linspace(0,0.4,80);
q=zeros(10,80);
for i=1:80
   for k=1:10
       q(k,i)=qcalc(t(i)/0.4,params,k);
   end 
end    


plot(q(1,:))

