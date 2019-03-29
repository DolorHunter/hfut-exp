%�������ղ�ֵ
%xΪԤ���
function [p, fx, miss]=Lagrange(x)
l=1;
p=0;
for i = -5:5
    x_k = i;
    for j = -5:5
        x_j = j;
        if x_k~=x_j
            l = l * (x-x_j) / (x_k-x_j);
        end
    end
    y_k = 1/(1+x_k*x_k);
    p = p + l * y_k;
end
%������ʵֵ
fx = 1/(1+x*x);
%�������
miss = fx-p;
%������
fprintf('Ԥ��ֵ: %f\t��ȷֵ: %f\t���: %f\n', p, fx, miss);
end