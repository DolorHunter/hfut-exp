%����ţ�ٲ�ֵ
%xΪԤ���
function [p, fx, miss] = Newton(x)
l=1;
p=0;
for i = 1:9
    if i==1 || i==4|| i==9
        x_k=i;
        for j = 1:9
            if j==1 || j==4 || j==9
                x_j=j;
                if x_k~=x_j
                    l = l * (x_k-x_j);
                end
            end
        end
        y_k = sqrt(x);
        p = p + y_k/l;
    end
end
%������ʵֵ
fx = sqrt(x);
%�������
miss = fx-p;
%������
fprintf('Ԥ��ֵ: %f\t��ȷֵ: %f\t���: %f\n', p, fx, miss);
end