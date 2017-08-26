# waterFmodtest

Fmode的音频库使用

首先介绍下Fmode ，这个是一个音频处理的开源C++库，应用也是比较广泛的，常见的我们听到的cocos2d里面就包含这一模块

start：

1.首先上官网下载下fmod的api
http://www.fmod.org/download/

2.其中api\lowlevel里面就有我们这里使用到的变声预编译库
包含三个东西

①.inc的so里面函数的头文件

②.libfmod.so 、libfmod.so 的动态库文件，选择自己要编译的平台
cp 到我们libs目录下

③. cp fmode.jar文件夹 ，并工程中添加依赖。

3.在gradle中配置目录以及要编译的平台


 //配置jni所在的目录

    sourceSets.main {
        jniLibs.srcDirs = ['libs']
        jni.srcDirs = []
    }

  ndk {
            abiFilters "armeabi","x86"
 }
 
 4.配置构建的规则cmake文件
 
 5.自定义native方法VoiceFixer
 
 6.生成头文件
 （备注：安卓stdio下，cd 到java目录 terminal中输入 javah -d ../pakename.classname ）
 
 7.在工程中初始化Fmode的库
   FMOD.init(this);
  有初始化自然也有释放
    FMOD.close();