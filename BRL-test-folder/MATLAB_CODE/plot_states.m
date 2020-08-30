% clear all 
% clc
% s=load('GaitLibrary_v1.mat');
% params=zeros(10,6);
% 
% k=1;
% for j=1:6
%     for i=1:10
%          params(i,j)= s.GaitLibrary{1,9}.opt.params{1,1}.atime(k);
%          k=k+1;
%     end
% end 
% 
% t=linspace(0,0.4,80);
% q1=zeros(10,80);
% qd1=zeros(10,80);
% for i=1:80
%    for k=1:10
%        q1(k,i)=qcalc(t(i)/0.4,params,k);
%        qd1(k,i)=qdcalc(t(i)/0.4,params,k); 
%    end 
% end    
% 
% params2=zeros(10,6);
% 
% k=1;
% for j=1:6
%     for i=1:10
%          params2(i,j)= s.GaitLibrary{1,9}.opt.params{3,1}.atime(k);
%          k=k+1;
%     end
% end 
% 
% t=linspace(0,0.4,80);
% q2=zeros(10,80);
% qd2=zeros(10,80);
% for i=1:80
%    for k=1:10
%        q2(k,i)=qcalc(t(i)/0.4,params2,k);
%        qd2(k,i)=qdcalc(t(i)/0.4,params2,k); 
%    end 
% end 
% hold on
% plot(q1(3,:))
% 
% plot(q2(3,:))
 
clear 
t=zeros(1,801);
for i=1:800
    t(i+1)=t(i)+0.00125;
end    

input1=zeros(20,801);
input2=zeros(20,801);
flag=0;

for i=1:801
    input1(:,i)=cassie_input([t(i);flag]);
end

flag=1;
for i=1:801
    input2(:,i)=cassie_input([t(i);flag]);
end


stance_1_v1=input1';
stance_2_v1=input2';
A1=reshape(input1,[],1);
B1=reshape(input2,[],1);
writematrix(A1);
writematrix(B1);
% writematrix(stance_1_v1);
% writematrix(stance_2_v1);



