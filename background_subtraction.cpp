//
// Created by Aashka Desai on 2/20/24.
//

#include <opencv2/opencv.hpp>
#include <opencv2/video/background_segm.hpp>

int main(int argc, char* argv[])
{
    // Open the video file
    cv::VideoCapture capture("/Users/aashkadesai/CLionProjects/AdvanceCV/HW_02/VIDEO_Walking_through_Back_Yard_DO_NOT_REMOVE.mp4");
    if (!capture.isOpened()) {
        std::cerr << "Could not open video file." << std::endl;
        return -1;
    }

    // Create MOG2 Background Subtractor object.
    auto pMOG2 = cv::createBackgroundSubtractorMOG2();
    pMOG2->setDetectShadows(false);
    cv::Mat frame, fgMaskMOG2, backgroundModel;

    // Skip the initial part of the video where nothing happens
    capture.set(cv::CAP_PROP_POS_FRAMES, 10);

    // Define a solid color for the background
    cv::Scalar solidBackgroundColor(0, 255, 0); // Green

    while(true) {
        if (!capture.read(frame)) break;

        // Apply the background subtractor to the frame
        pMOG2->apply(frame, fgMaskMOG2);

        // Retrieve the current background model
        pMOG2->getBackgroundImage(backgroundModel);

        // Result frame filled with the solid background color
        cv::Mat result(frame.size(), frame.type(), solidBackgroundColor);

        // Copy objects from the original frame to the result frame
        frame.copyTo(result, fgMaskMOG2);

        // Display the result
        cv::imshow("Original Frame", frame);
        cv::imshow("Foreground Mask", fgMaskMOG2);

        if (!backgroundModel.empty()) {
            cv::imshow("Background Model", backgroundModel);
        }

        cv::imshow("Result with Solid Background", result);

        // Wait for a key press for a short period
        if (cv::waitKey(30) >= 0) break;
    }

    return 0;
}
