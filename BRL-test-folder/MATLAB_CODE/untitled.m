clear

s=load('GaitLibrary_v1.mat');
%params - for bezier
params1=zeros(10,6);
params2=zeros(10,6);

%first leg stance
k=1;

    for j=1:6
        for i=1:10
            params1(i,j)=s.GaitLibrary{1,9}.opt.params{1,1}.atime(k);
            k=k+1;
        end   
    end

s=load('GaitLibrary_v1.mat');

k=1;

    for j=1:6
        for i=1:10
            params2(i,j)=s.GaitLibrary{1,9}.opt.params{3,1}.atime(k);
            k=k+1;
        end   
    end
    
s1=0;
s2=0;
 t1=0;   
t2=1;
m=1;
 for j=0:4
   s1=s1+(params1(m,j+2)-params1(m,j+1))*(factorial(5)/(factorial(j)*factorial(5-j-1)))*(t1^(j))*((1-t1)^(5-j-1))
end


for j=0:4
   s2=s2+(params2(m,j+2)-params2(m,j+1))*(factorial(5)/(factorial(j)*factorial(5-j-1)))*(t2^(j))*((1-t2)^(5-j-1))
end

