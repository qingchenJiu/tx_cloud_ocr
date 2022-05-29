//
//  recdetect.h
//  recdetect
//
//  Created by fujikoli(李鑫) on 2017/9/15.
//  Copyright © 2017年 fujikoli(李鑫). All rights reserved.
//

#ifndef IMAGE_REFINE_H
#define IMAGE_REFINE_H
#define custom_cv yt_tiny_cv
#include <tiny_opencv2/opencv.hpp>

namespace YTCV {
    enum FILTER_TYPE {
        FILTER_BRIGHT = 1,
        FILTER_SHARP,
        FILTER_GRAY,
        FILTER_BINARY,
    };

    enum DETECT_TYPE {
        DETECT_GENERAL = 1,
        DETECT_HORIZONTAL_SCREEN,
        DETECT_VERTICAL_SCREEN,
    };

    class ImageRefiner {
    public:
        static int GlobalInit();
        int BlurDetect(const custom_cv::Mat& src, double &result);
        int RectangleDetect(const custom_cv::Mat& src, std::vector<custom_cv::Point>& squares, double threshold1 = 1.5, double threshold2 = 2.0, int DETECT_TYPE = DETECT_GENERAL);
        int RectangleDetect(const custom_cv::Mat& src, std::vector<custom_cv::Point>& squares, custom_cv::Rect& roi_rect, double threshold1 = 1.5, double threshold2 = 2.0, int DETECT_TYPE = DETECT_GENERAL);
        int CropImage(const custom_cv::Mat& src, std::vector<custom_cv::Point>& squares, custom_cv::Mat &dst);
        int ImageFilter(const custom_cv::Mat& src, custom_cv::Mat& dst, int FILTER_TYPE);
    private:
        static bool _global_init_;
    };
}

#endif /* IMAGE_REFINE_H */
