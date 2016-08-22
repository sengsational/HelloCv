#include <jni.h>
#include <string>
//DRS 20160822d - Added include, passes compile check, fails external build
#include <opencv2/core>

extern "C" {
    jstring
    Java_com_company_cpp_hellocv_MainActivity_stringFromJNI(
            JNIEnv *env,
            jobject /* this */) {
        std::string hello = "Hello from C++";
        return env->NewStringUTF(hello.c_str());
    }

    //DRS 20160822c - Added native method
    jstring
    Java_com_company_cpp_hellocv_MainActivity_validate(JNIEnv *env, jobject, jlong addrGray, jlong addrRgba) {
        //DRS 20160822d - Added OpenCv object (not successfully passing compile check)
        //cv::Rect();
        //cv::Mat();
        std::string hello2 = "Hello from validate";
        return env->NewStringUTF(hello2.c_str());
    }
}
