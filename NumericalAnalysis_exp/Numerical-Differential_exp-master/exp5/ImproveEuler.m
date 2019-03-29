% �Ľ�ŷ��������ֵ��

% ����������䣬��ֵ����ֵ�����

function [] = ImproveEuler(a, b, y0, n)

h = (b-a)/n;
x=a;
y=y0;

while x < b
    yp = y + h * Derivative(x, y); % ��ʾ���
    yc = y + h * Derivative(x, y); % ��ʽ���
    y = 0.5 * (yp + yc);
    % ������
    fprintf('Xn=%f\tYn=%f\tYXn=%f\t��=%f\n', x, y, Value(x), Value(x)-y);
    x = x + h;
end

end