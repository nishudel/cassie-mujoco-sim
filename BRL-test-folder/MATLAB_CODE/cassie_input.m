function input= cassie_input(t)
%The input will contain an array that has the values of q and qd evaluated
%at t_step=t(1) and flag = t(2) to indicate change in stance leg 


s=load('GaitLibrary_v1.mat');
%params - for bezier
params=zeros(10,6);

%first leg stance
if (t(2)<0.5)
    k=1;
    for j=1:6
        for i=1:10
            params(i,j)=s.GaitLibrary{1,9}.opt.params{1,1}.atime(k);
            k=k+1;
        end   
    end
end 

%second leg stance
if (t(2)<2 && t(2)>0.5)
    k=1;
    for j=1:6
        for i=1:10
            params(i,j)=s.GaitLibrary{1,9}.opt.params{3,1}.atime(k);
            k=k+1;
        end   
    end
end 

q=zeros(10,1);
qd=zeros(10,1);

for i=1:10
    q(i)=qcalc(t(1),params,i);
    qd(i)=qdcalc(t(1),params,i);
end

input=[q;qd];

end