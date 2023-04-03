% 주어진 영상을 G라고 하면 prewitt_x{G}(x,y)=G*prewitt_x_mask(x,y), 모든 상황에서
% '', prewitt_y{G}(x,y)=G*prewitt_y_mask(x,y), 모든 상황에서

G=imread("lena2.bmp");

prewitt_x_mask=[-1, 0, 1; -1, 0, 1; -1, 0, 1];
prewitt_y_mask=[-1, -1, -1;0, 0, 0; 1, 1, 1];

prewitt_x=convolu(G, prewitt_x_mask)/6;
prewitt_y=convolu(G, prewitt_y_mask)/6;


prewitt_size = sqrt((prewitt_x.*prewitt_x)+(prewitt_y.*prewitt_y));

% 에지강도가 임계값 T 미만인 화소의 화소값 0으로 만들기
T_prewitt=10; % prewitt 임계값
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

% 주어진 영상을 G라고 하면 sobel_x{G}(x,y)=G*sobel_x_mask(x,y), 모든 상황에서
% '', sobel_y{G}(x,y)=G*sobel_y_mask(x,y), 모든 상황에서

sobel_x_mask=[-1, 0, 1; -2, 0, 2; -1, 0, 1];
sobel_y_mask=[-1, -2, -1; 0, 0, 0; 1, 2, 1];

sobel_x=convolu(G, sobel_x_mask);
sobel_y=convolu(G, sobel_y_mask);

sobel_size = sqrt((sobel_x.*sobel_x)+(sobel_y.*sobel_y));

% 에지강도가 임계값 T 미만인 화소의 화소값 0으로 만들기
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
