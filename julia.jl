using OpenCV
const cv = OpenCV

function image_show(image, window_name)
    cv.namedWindow("Image", cv.WINDOW_NORMAL); cv.setWindowTitle("Image", window_name)
    cv.moveWindow("Image", 0, 0); cv.resizeWindow("Image", size(image)[2]÷2, size(image)[3]÷2)  
    cv.imshow("Image", image); cv.waitKey(0); cv.destroyAllWindows()
end


function imageCircles(image_orig, image_edges)
    return circles = cv.HoughCircles(image_edges, Int64(cv.HOUGH_GRADIENT), Float64(1.3), Float64(60), Float64(50), Float64(70), Int64(0), Int64(500))
end


@time begin
image = cv.imread("test.jpg");
image_gray = cv.cvtColor(image, cv.COLOR_BGR2GRAY)
image_edges = cv.Canny(image, Float64(50), Float64(100)) 
image_circles = imageCircles(image, image_edges)
end

image_show(image, "Original")
image_show(image_edges, "Processed")
