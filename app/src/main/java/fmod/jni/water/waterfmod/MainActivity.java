  package fmod.jni.water.waterfmod;

import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import org.fmod.FMOD;

import java.io.File;

  public class MainActivity extends AppCompatActivity {


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        FMOD.init(this);

    }

      @Override
      protected void onDestroy() {
          super.onDestroy();
          FMOD.close();
      }
      public void mFix(View btn){
          final String path= Environment.getExternalStorageDirectory()+ File.separator+"water.mp3";
          Log.i("path:",path);
          switch (btn.getId()){
              case R.id.btn_normal:

                  new Thread(new Runnable() {
                      @Override
                      public void run() {
                          VoiceFixer.fix(path,VoiceFixer.MODE_NORMAL);
                      }
                  }).start();
                  break;
              case R.id.btn_dashu:
                  new Thread(new Runnable() {
                      @Override
                      public void run() {
                          VoiceFixer.fix(path,VoiceFixer.MODE_DASHU);
                      }
                  }).start();

                  break;
              case R.id.btn_gaoguai:
                  new Thread(new Runnable() {
                      @Override
                      public void run() {
                          VoiceFixer.fix(path,VoiceFixer.MODE_GAOGUAI);
                      }
                  }).start();

                  break;
              case R.id.btn_jingsong:
                  new Thread(new Runnable() {
                      @Override
                      public void run() {
                          VoiceFixer.fix(path,VoiceFixer.MODE_JINGSONG);
                      }
                  }).start();

                  break;
              case R.id.btn_kongling:
                  new Thread(new Runnable() {
                      @Override
                      public void run() {
                          VoiceFixer.fix(path,VoiceFixer.MODE_KONGLING);
                      }
                  }).start();

                  break;
              case R.id.btn_luoli:
                  new Thread(new Runnable() {
                      @Override
                      public void run() {
                          VoiceFixer.fix(path,VoiceFixer.MODE_LUOLI);
                      }
                  }).start();

                  break;
            default:
                break;

          }
      }
  }
