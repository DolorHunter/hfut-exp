 %����ţ�ٿ���˹����㷨% ������������㷨

% a, bΪ����˵�
% delta Ϊ�����
function [C, miss] = Cortes(a, b, delta)
% ���貽��
n=2;
h= (b-a)/n;
% ���躯��Ϊy=sinx/x
% ��0��ʼ����
x=a + 0.00000001; 
%��������˹������
C=0;
%ѭ�����loop
loop = 1;
while(loop)
    while(x<=b)
        C = C + (32 * sin(x + h / 4) / (x + h / 4) + 12 * sin(x + h / 2) / (x + h / 2) + 32 * sin(x + h * 3 / 4) /(x + h * 3 / 4) + 14 * sin(x + h) / (x + h)) * h / 90;
        x=x+h;
    end
    a=a + 0.00000001; % a=0��ĸΪ0�޷�����.
    C = C + (7 * (sin(a) / a + sin(b) / b) * h / 90);
    miss = quad(@(x)sin(x)./x,0,1) - C;
    loop=0;
    if (miss < delta)
        loop = 0;
    else
        n = n * 2;
        h= (b-a)/n;
        x=a + 0.00000001;
        C=0;
    end
end
%������
fprintf('������Ϊy = sin(x)/xʱ, ��������˹������Ϊ:%f, ���Ϊ:%f', C, miss);
end