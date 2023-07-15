
clc
clear
close all

%%
tic
image = imread("test.jpg");
image_processed = rgb2gray(image);
time_end = toc;
time_end = time_end * 1000;
display("Processing time: " + time_end + " ms")

%%
imshow(image);
imshow(image_processed);
