
clc
clear
close all

%
tic
%% 
image = imread("test.jpg");
image_gray = rgb2gray(image);
image_edges = edge(image_gray);
[centers, radii, metric] = imfindcircles(image_edges, [10 10000]);

%% 
time_end = toc;
time_end = time_end * 1000;
centersStrong5 = centers(1:7,:); radiiStrong5 = radii(1:7); metricStrong5 = metric(1:7);
imshow(image);
viscircles(centersStrong5, radiiStrong5,'EdgeColor','b');
display("Processing time: " + time_end + " ms")

