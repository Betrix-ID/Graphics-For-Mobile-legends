#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#define SCRIPT_VERSION "1.0 [Build Settings Graphics and Fps for Mobile Legends]"

// Cek keberadaan folder atau file
int cek_eksistensi(const char *path) {
    struct stat buffer;
    return (stat(path, &buffer) == 0);
}

// Menampilkan notifikasi
void shell(const char *message, int fps) {
    char command[512];
    snprintf(command, sizeof(command),
             "cmd notification post -I /sdcard/std/prop.png -S bigtext -t '♨️ Graphics for Mobile Legends' 'Tag' '%s %d Hz' > /dev/null 2>&1",
             message, fps);
    system(command);
}

// Fungsi untuk mengatur FPS berdasarkan mode
// Fungsi untuk mengatur FPS berdasarkan mode
void setFps(int fps) {
    printf("\nDescription:\n");
    printf("  This function optimizes graphics settings and frame rate for Mobile Legends.\n");
    printf("  It configures display settings, adjusts refresh rate, and ensures optimal\n");
    printf("  performance by managing processes and resources.\n\n");

    if (cek_eksistensi("/sdcard/std/Main/com.mobile.legends")) {
        system("cp -r /sdcard/std/Main/com.mobile.legends/file /sdcard/Android/data/com.mobile.legends > /dev/null 2>&1");

        char commands[1024];
        snprintf(commands, sizeof(commands), 
                 "cmd display clear-user-preferred-display-mode 0 && "
                 "cmd display set-user-preferred-display-mode $(wm size | awk -F '[ x]+' '{print $3}') $(wm size | awk -F '[ x]+' '{print $4}') %d 0 && "
                 "setprop debug.sf.use_phase_offsets_as_durations 1 &&"
                 "settings put system peak_refresh_rate %d && "
                 "settings put system user_refresh_rate %d && "
                 "settings put system min_refresh_rate %d && "
                 "settings put secure user_refresh_rate %d &&"
                 "cmd package compile -m quicken -f com.mobile.legends >/dev/null 2>&1 &&"
                 "cmd deviceidle except-idle-whitelist +com.mobile.legends > /dev/null 2>&1 &&"
                 "cmd activity clear-watch-heap com.mobile.legends &&"
                 "cmd activity clear-exit-info --user 0 com.mobile.legends &&"
                 "cmd activity set-watch-heap com.mobile.legends 5200000 && "
                 "cmd deviceidle disable && "
                 "cmd activity set-stop-user-on-switch false >/dev/null 2>&1 && "
                 "sync", fps, fps, fps, fps, fps);
        system(commands);
    } else {
        printf("⚠️ Folder sumber tidak ditemukan!\n");
        return;
    }
    
    system("cmd activity start -n com.mobile.legends/com.moba.unityplugin.MobaGameUnityActivity > /dev/null 2>&1");
    sleep(27);
    
    system("cmd activity force-stop --user 0 com.mobile.legends");
    
    if (cek_eksistensi("/sdcard/std/restprop/com.mobile.legends")) {
        system("cp -r /sdcard/std/restprop/com.mobile.legends/file /sdcard/Android/data/com.mobile.legends/ > /dev/null 2>&1");
        system("monkey -p com.mobile.legends -c android.intent.category.LAUNCHER 1");
    } else {
        printf("⚠️ Folder reset tidak ditemukan!\n");
        return;
    }

    sleep(1);
    shell("Successfully Applay Graphics For Mobile legends: %d", fps);
}
void Usage() {
    printf("GFM %s - Mobile Legends Graphics and FPS Optimization Utility\n", SCRIPT_VERSION);
    printf("Usage: GFM [OPTION] [FPS]\n\n");    
    printf("Options:\n");
    printf("  -E         Set FPS to 60 Hz\n");
    printf("  -l         Set FPS to 98 Hz\n");
    printf("  -F         Set FPS to 120 Hz\n");
    printf("  -h, --help Display this help message and exit\n\n");
    printf("Description:\n");
    printf("  GFM is a lightweight system optimization tool designed to\n");
    printf("  enhance the graphics settings and frame rate of Mobile Legends.\n");
    printf("  It dynamically configures the graphics settings and\n");
    printf("  adjusts the FPS to match the selected refresh rate.\n\n");
    printf("Examples:\n");
    printf("  Set FPS to 60 Hz:\n");
    printf("      GFM -E\n\n");
    printf("  Set FPS to 90 Hz:\n");
    printf("      GFM -l\n\n");
    printf("  Set FPS to 120 Hz:\n");
    printf("      GFM -F\n\n");
    printf("System Requirements:\n");
    printf("  - Device must have access to the necessary configuration files\n");
    printf("  - Root access **may** be required depending on the Android version\n");
    printf("  - Mobile Legends must be installed in the default directory\n\n");
    printf("For more information, visit:\n");
    printf("  Mobile Legends Optimization Guide: https://m.mobilelegends.com/en/\n");
    printf("  Android Debugging Guide: https://developer.android.com/studio/command-line/adb\n\n");
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        Usage();
    }

    int selectedFps = 0;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-E") == 0) {  
            selectedFps = 60;
        } else if (strcmp(argv[i], "-l") == 0) { 
            selectedFps = 98;
        } else if (strcmp(argv[i], "-F") == 0) { 
            selectedFps = 120;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            Usage();
        } else {  
            printf("Unknown option: %s\n", argv[i]);  
            Usage();  
        }  
    }

    if (selectedFps > 0) {
        setFps(selectedFps);
    }

    sleep(1);
    printf("\n");
    printf(" ⚠️ This module is protected by copyright and is\n");
    printf(" intended for use by regular users only. Any use of\n");
    printf(" this module, including its code, design, or features,\n");
    printf(" by other developers without written permission from\n");
    printf(" the copyright owner is strictly prohibited.\n");
    printf("______________________________________________(+)\n\n");  

    return 0;
}