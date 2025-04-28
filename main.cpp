#include <opencv2/opencv.hpp>
#include <iostream>

cv::Mat detectFace(cv::Mat image);

int main() {
    cv::VideoCapture cap(0);

    if (!cap.isOpened()) {
        std::cerr << "Error opening camera" << std::endl;
        return -1;
    }

    cv::Mat frame;
    while (true) {
        cap.read(frame);
        if (frame.empty()) {
            std::cerr << "Error reading frame" << std::endl;
            break;
        }

        cv::imshow("Webcam Feed", detectFace(frame));
        if (cv::waitKey(1) == 27) break; // Press ESC to exit
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}

cv::Mat detectFace(cv::Mat image) {
    cv::Mat grayscaleImage;

    cv::cvtColor(image, grayscaleImage, cv::COLOR_BGR2GRAY);

    cv::CascadeClassifier faceCascade;
    if(!faceCascade.load("haarcascade_frontalface_alt.xml")){
        std::cerr << "Error: Haar Cascade loading failed" << std::endl;
        return image;
    }

    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(grayscaleImage, faces, 1.1, 3, 0, cv::Size(30, 30));

    for (const auto& face : faces){
      cv::rectangle(image, face, cv::Scalar(255, 0, 0), 2);
    }

    return image;
}
