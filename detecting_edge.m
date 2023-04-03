% �־��� ������ G��� �ϸ� prewitt_x{G}(x,y)=G*prewitt_x_mask(x,y), ��� ��Ȳ����
% '', prewitt_y{G}(x,y)=G*prewitt_y_mask(x,y), ��� ��Ȳ����

G=imread("lena2.bmp");

prewitt_x_mask=[-1, 0, 1; -1, 0, 1; -1, 0, 1];
prewitt_y_mask=[-1, -1, -1;0, 0, 0; 1, 1, 1];

prewitt_x=convolu(G, prewitt_x_mask)/6;
prewitt_y=convolu(G, prewitt_y_mask)/6;


prewitt_size = sqrt((prewitt_x.*prewitt_x)+(prewitt_y.*prewitt_y));

% ���������� �Ӱ谪 T �̸��� ȭ���� ȭ�Ұ� 0���� �����
T_prewitt=10; % prewitt �Ӱ谪
M=size(G, 1);
N=size(G, 2);
for i=1:M
  for j=1:N
    if prewitt_size(i, j) < T
      prewitt_size_new(i, j)=0;
    else
      prewitt_size_new(i, j)=1;
    endif
  endfor
endfor

G_edge_prewitt=255*(G.*prewitt_size_new);
imshow(G_edge_prewitt);

% �־��� ������ G��� �ϸ� sobel_x{G}(x,y)=G*sobel_x_mask(x,y), ��� ��Ȳ����
% '', sobel_y{G}(x,y)=G*sobel_y_mask(x,y), ��� ��Ȳ����

sobel_x_mask=[-1, 0, 1; -2, 0, 2; -1, 0, 1];
sobel_y_mask=[-1, -2, -1; 0, 0, 0; 1, 2, 1];

sobel_x=convolu(G, sobel_x_mask);
sobel_y=convolu(G, sobel_y_mask);

sobel_size = sqrt((sobel_x.*sobel_x)+(sobel_y.*sobel_y));

% ���������� �Ӱ谪 T �̸��� ȭ���� ȭ�Ұ� 0���� �����
T_sobel=100;

for i=1:M
  for j=1:N
    if sobel_size(i, j) < T_sobel
      sobel_size_new(i, j)=0;
    else
      sobel_size_new(i, j)=1;
    endif
  endfor
endfor

G_edge_sobel=255*sobel_size_new;
figure(2);imshow(G_edge_sobel);
