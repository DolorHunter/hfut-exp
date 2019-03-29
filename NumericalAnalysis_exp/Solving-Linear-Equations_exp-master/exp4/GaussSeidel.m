% Gauss-Seidel������ⷽ����

% ����: ϵ�о���A, ��������N, ��ʼ����, �����e
% ���: ������

function [x1, x2, x3] = GaussSeidel(N, x0, e)
count = 0;
x1=x0;
x2=x0;
x3=x0;
x1_val = 1.1;
x2_val = 1.2;
x3_val = 1.3;
while count < N && e < abs(x1_val - x1) && e < abs(x2_val - x2) && e < abs(x3_val - x3)
    count = count + 1;
   x1 = 0.72 + 0.1 * x2 + 0.2 * x3;
   x2 = 0.83 + 0.1 * x1 + 0.2 * x3;
   x3 = 0.84 + 0.2 * x1 + 0.2 * x2;
   % ������
    fprintf('������%d�ε���, x1=%f\tx2=%f\tx3=%f\n', count, x1, x2, x3);
end
end