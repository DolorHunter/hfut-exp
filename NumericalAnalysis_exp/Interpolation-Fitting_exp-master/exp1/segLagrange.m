%�ֶβ�ֵ: ��������һ�β�ֵ
%xΪԤ���
function [p, fx, miss] = segLagrange(x)
%ȷ������
for i = -5:4
    if i<x && x<i+1
            x_min = i;
            x_max = i+1;
    end
end
%��ֵ�����ʵֵ
f_min = 1/(1+x_min*x_min);
f_max = 1/(1+x_max*x_max);
%Ԥ������ʵֵ
fx = 1/(1+x*x);
%����ϵ��l
l1 = (x-x_min)/(x_max-x_min);
l2 = (x-x_max)/(x_min-x_max);
%����Ԥ��ֵ
p = l1 * f_max + l2 * f_min;
%�������
miss = fx-p;
%������
fprintf('Ԥ��ֵ: %f\t��ȷֵ: %f\t���: %f\n', p, fx, miss);
end