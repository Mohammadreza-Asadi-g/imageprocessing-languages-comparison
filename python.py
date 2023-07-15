"""
Author: Mohammadreza Asadi G.
"""

import sys
import cv2 as cv
import numpy as np    
import datetime

def main():
    time_start = datetime.datetime.now()
    # Processes:
    image = cv.imread("test.jpg")
    image_orig = image.copy()
    image_gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY) 
    image_edges = cv.Canny(image_gray, 50, 100)
    time_end = datetime.datetime.now()
    image_circles = imageCircles(image, image_edges)
    #
    time_elapsed = time_end - time_start

    message = f"Processing time: {time_elapsed.microseconds * 10**-3} ms"
    print(message)
    image_result = np.hstack([image_orig, image_circles])
    cv.putText(image_result, message, (100, 100), cv.FONT_HERSHEY_SIMPLEX, 2, (0, 255, 0), 5)
    imageShow(image_result, "Results")


def imageCircles(image_orig, image_edges):
    circles = cv.HoughCircles(image_edges, cv.HOUGH_GRADIENT, dp=1.3, minDist=60, param1=50, param2=70, minRadius=0, maxRadius=500) 
    for i in circles[0, :]:
        cv.circle(image_orig, (int(i[0]), int(i[1])), 10, (0, 255, 0), -1)
        cv.rectangle(image_orig, (int(i[0])-int(i[2]), int(i[1])-int(i[2])), (int(i[0])+int(i[2]), int(i[1])+int(i[2])), (0, 255, 0), 3)
    return image_orig

def imageShow(image, window_name):
    cv.namedWindow("Image", cv.WINDOW_NORMAL); cv.setWindowTitle("Image", window_name)
    cv.moveWindow("Image", 0, 0); cv.resizeWindow("Image", image.shape[1]//2, image.shape[0]//2)  
    cv.imshow("Image", image); cv.waitKey(0); cv.destroyAllWindows()

if __name__ == "__main__":
    sys.exit(main())