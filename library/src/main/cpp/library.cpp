#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_ufaceplus_facemesh_library_NativeLib_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}