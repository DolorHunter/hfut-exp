% ��������ɭ����㷨

% a, bΪ����˵�
% delta Ϊ�����
function [S, miss] = Simpson(a, b, delta)
% ���貽��
n=2;
h= (b-a)/n;
% ���躯��Ϊy=sinx/x
% ��0��ʼ����
x=a + 0.00000001; 
%��������ɭ������
S=0;
%ѭ�����loop
loop = 1;
while(loop)
    while(x<=b)
        S = S+(sin(x) / x + 4 * sin(x + h/2) / (x + h / 2) + sin(x+h)/(x+h))*h/6;
        x=x+h;
    end
    miss = quad(@(x)sin(x)./x,0,1) - S;
    if (miss < delta)
        loop = 0;
    else
        n = n * 2;
        h= (b-a)/n;
        x=a + 0.00000001;
        S=0;
    end
end
%������
fprintf('������Ϊy = sin(x)/xʱ, ��������ɭ������Ϊ:%f, ���Ϊ:%f', S, miss);
end