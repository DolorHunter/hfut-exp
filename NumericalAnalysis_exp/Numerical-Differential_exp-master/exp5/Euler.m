% ŷ��������ֵ��

% ����������䣬��ֵ����ֵ�����

function [] = Euler(a, b, y0, n)

h = (b-a)/n;
x=a;
y=y0;

while x < b
    y = y + h * Derivative(x,y);
    % ������
    fprintf('Xn=%f\tYn=%f\tYXn=%f\t��=%f\n', x, y, Value(x), Value(x)-y);
    x = x + h;
end

end