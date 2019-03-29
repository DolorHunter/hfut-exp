% ţ����ɽ����ⷽ��

% �����ֵ������ޣ���������������ɽ������
% ������Ƹ�������ɽ����

function lamda = NewtonDownhill(x0, loss, max_time)
% lamda Ϊ ��ɽ����
lamda = 1;

x = x0;
y = 0;
x_kp = x - lamda * Value(x, y)/Derivative(x, y); % xk+1

% stepΪ����
step = 1;
while abs(Value(x, y)-x) > loss & step <= max_time
    x = x - lamda * Value(x, y)/Derivative(x, y); % k��
    x_kp = x_kp - lamda * Value(x, y)/Derivative(x, y); % ��Զ��k+1��
    % ������� lamda
    fprintf('��ǰΪ��%d��\t��ɽ����Ϊ:%f\t���Ƹ�Ϊ:%f\n', step, lamda, x);
    step = step + 1;
    lamda = lamda / 2; % �����۰�
end
if abs(Value(x_kp, y)) < abs(Value(x, y))
    fprintf('������%d�������,��ɽʧ��.', step);
else
    fprintf('������%d�������,��ɽ�ɹ�.', step);

end