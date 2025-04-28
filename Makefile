all:
	g++ main.cpp -o camface -I/usr/include/opencv4 -L /usr/local/lib -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_objdetect

