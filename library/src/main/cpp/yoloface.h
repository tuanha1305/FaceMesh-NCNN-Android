//
// Created by Tuấn Hà Anh on 09/01/2023.
//

#ifndef FACEMESH_NCNN_YOLOFACE_H
#define FACEMESH_NCNN_YOLOFACE_H


#include <opencv2/core/core.hpp>

#include <net.h>
struct Landmarks
{
    float x;
    float y;
    float score;
};
struct Object
{
    cv::Rect_<float> rect;
    int label;
    float prob;
    std::vector<Landmarks> pts;
};


class YoloFace
{
public:
    YoloFace();

    int load(const char* modeltype, int target_size, const float* mean_vals, const float* norm_vals, bool use_gpu = false);

    int load(AAssetManager* mgr, const char* modeltype, int target_size, const float* mean_vals, const float* norm_vals, bool use_gpu = false);

    int detect(const cv::Mat& rgb, std::vector<Object>& objects, float prob_threshold = 0.25f, float nms_threshold = 0.45f);

    int draw(cv::Mat& rgb, const std::vector<Object>& objects);

private:

    ncnn::Net yoloface;

    int target_size;
    float mean_vals[3];
    float norm_vals[3];
    int image_w;
    int image_h;
    int in_w;
    int in_h;

    ncnn::UnlockedPoolAllocator blob_pool_allocator;
    ncnn::PoolAllocator workspace_pool_allocator;
};


#endif //FACEMESH_NCNN_YOLOFACE_H
