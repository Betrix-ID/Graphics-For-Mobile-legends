#!/system/bin/sh
# Checking ID shell
if [ "$(id -u)" -ne 2000 ]; then
    echo "[ Error |@UnixeID(Yeye)]"
    exit 1
fi
# Smart Notification
shell() {
    sor="$1"
    cmd notification post -I /sdcard/std/prop.png  -S bigtext -t '♨️ Graphics For Mobile legends' 'Tag' "$sor" > /dev/null 2>&1
}
# Style display Terminal
    echo
    echo "     ☆================================☆"
    echo
    echo "       ~ Description. Graphics For Mobile legends.... "
    echo
    echo "       - Author                 :  @UnixeID"
    echo "       - Version                :  1.0"
    echo "       - Release               :  28 - Mar - 2025"
    echo "       - Name Shell         :  Graphics For Mobile legends."
    echo
    echo "    |_______________________________________|"
    echo "    \______________________________________/"
    echo
    echo "   Priority Graphics For Mobile legends "
    sleep 2
    echo
    echo
        rm -rf /data/local/tmp/*
        cp /sdcard/std/src /data/local/tmp
        chmod +x /data/local/tmp/src
        # Pilihan mode
            if [ "$1" = "-F" ]; then
               shell "Applying Graphics For Mobile legends Fps: 120, please wait 1-3 seconds..."
               /data/local/tmp/src -F
           elif [ "$1" = "-l" ]; then
               shell "Applying Graphics For Mobile legends Fps: 90 please wait 1-3 seconds..."
               /data/local/tmp/src -l
          elif [ "$1" =  "-E" ]; then
               shell "Applying Graphics For Mobile legends Fps: 60, please wait 1-3 seconds..."
               /data/local/tmp/src -E
          elif [ "$1" = "-h" ]; then
              /data/local/tmp/src -h
          elif [ "$1" = "--help" ]; then
              /data/local/tmp/src --help
        else
            echo "Usage: ./run.sh [-H|-S|--help] [60|90|120]"
            fi