#include <jni.h>
#include <string>

#include <unistd.h>
#include <fmod.hpp>

#include <android/log.h>
#define LOGI(FORMAT,...) __android_log_print(ANDROID_LOG_INFO,"jason",FORMAT,##__VA_ARGS__);
#define LOGE(FORMAT,...) __android_log_print(ANDROID_LOG_ERROR,"jason",FORMAT,##__VA_ARGS__);
#include "fmod_jni_water_waterfmod_VoiceFixer.h"

#define MODE_NORMAL 0
#define MODE_LUOLI 1
#define MODE_DASHU 2
#define MODE_JINGSONG 3
#define MODE_GAOGUAI 4
#define MODE_KONGLING 5
using namespace FMOD;
extern "C"
JNIEXPORT void JNICALL Java_fmod_jni_water_waterfmod_VoiceFixer_fix
        (JNIEnv * env, jclass jcls, jstring path_jstr, jint type){
    System    *system;
    Sound     *sound;
    Channel   *channel;
    DSP       *dsp;
    bool playing = true;

    System_Create(&system);
    try {
        system->init(32, FMOD_INIT_NORMAL, NULL);
        //java string -> c char*
        const char* path_cstr = env->GetStringUTFChars(path_jstr,NULL);
        system->createSound(path_cstr, FMOD_DEFAULT, NULL, &sound);
        float frequency;
        switch (type) {
            case MODE_NORMAL:
                LOGI("%s","正常");
                system->playSound(sound, NULL, false, &channel);
                break;
            case MODE_LUOLI:
                LOGI("%s","萝莉");
                //FMOD_DSP_TYPE_PITCHSHIFT提高音调，但是又不改变语速
                system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
                //2.0代表调高一个八度(12345671)
                dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH,2.5);
                system->playSound(sound, NULL, false, &channel);
                channel->addDSP(0, dsp);
                break;
            case MODE_DASHU:
                LOGI("%s","大叔");
                system->createDSPByType(FMOD_DSP_TYPE_PITCHSHIFT, &dsp);
                dsp->setParameterFloat(FMOD_DSP_PITCHSHIFT_PITCH,0.8);
                //system->createDSPByType(FMOD_DSP_TYPE_DELAY, &dsp);
                //dsp->setParameterFloat(FMOD_DSP_DELAY_CH0,200);
                system->playSound(sound, NULL, false, &channel);
                channel->addDSP(0, dsp);
                break;
            case MODE_JINGSONG:
                LOGI("%s","惊悚");
                //FMOD_DSP_TYPE_TREMOLO 颤抖
                system->createDSPByType(FMOD_DSP_TYPE_TREMOLO, &dsp);
                dsp->setParameterFloat(FMOD_DSP_TREMOLO_SKEW,0.5);
                system->playSound(sound, NULL, false, &channel);
                channel->addDSP(0, dsp);
                break;
            case MODE_GAOGUAI:
                LOGI("%s","搞怪");
                //提高语速
                system->createDSPByType(FMOD_DSP_TYPE_NORMALIZE, &dsp);
                system->playSound(sound, NULL, false, &channel);
                channel->addDSP(0, dsp);
                channel->getFrequency(&frequency);
                frequency = frequency*1.6;
                channel->setFrequency(frequency);
                break;
            case MODE_KONGLING:
                LOGI("%s","空灵");
                system->createDSPByType(FMOD_DSP_TYPE_ECHO, &dsp);
                dsp->setParameterFloat(FMOD_DSP_ECHO_DELAY,300);
                dsp->setParameterFloat(FMOD_DSP_ECHO_FEEDBACK,20);
                system->playSound(sound, NULL, false, &channel);
                channel->addDSP(0, dsp);
                break;
            default:
                break;
        }
    } catch (...) {
        LOGE("%s","发送异常");
        goto end;
    }
    system->update();
    //检查是否结束播放
    while(playing){
        channel->isPlaying(&playing);
        usleep(1000);
    }
    end:
    LOGI("%s","end");
    dsp->release();
    system->close();
    system->release();


}
