#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_digitalsafeapp_MainActivity_showHelloString(
        JNIEnv* env,
        jobject /* this */) {
    std::string str = "Hello from DigitalSafeApp!";
    jstring jstr = env->NewStringUTF(str.c_str());

    return jstr;
}
