% ������������㷨

% a, bΪ����˵�
% delta Ϊ�����
function [T, miss] = Trapezoid(a, b, delta)
% ���貽��
n=2;
h= (b-a)/n;
% ���躯��Ϊy=sinx/x
% ��0��ʼ����
x=a + 0.00000001; 
%��������������
T=0;
%ѭ�����loop
loop = 1;
while(loop)
    while(x<=b)
        T = T + (sin(x) / x + sin(x + h) / (x + h)) * h / 2;
        x=x+h;
    end
    miss = quad(@(x)sin(x)./x,0,1) - T;
    if (miss < delta)
        loop = 0;
    else
        n = n * 2;
        h= (b-a)/n;
        x=a + 0.00000001;
        T=0;
    end
end
%������
fprintf('������Ϊy = sin(x)/xʱ, ��������������Ϊ:%f, ���Ϊ:%f', T, miss);
end