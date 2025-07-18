#!/bin/bash

WATCH_DIR="/home/osamu_os/Desktop/cp/cp/cph"
cd "$WATCH_DIR"

inotifywait -m -e close_write --format '%w%f' . | while read FILE
do
    if [[ "$FILE" == *.cpp ]]; then
        echo "Detected C++ file change: $FILE"
        git add "$FILE"
        git commit -m "Auto-commit: Updated $(basename "$FILE")"
        git push origin main
    fi
done

