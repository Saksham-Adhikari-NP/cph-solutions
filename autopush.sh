#!/bin/bash

WATCH_DIR="/home/osamu_os/Desktop/cp/cp/cph"
cd "$WATCH_DIR"

inotifywait -m -e close_write --format '%w%f' . | while read FILE
do
    echo "Detected change in $FILE"
    git add "$FILE"
    git commit -m "Auto-commit: Updated $(basename "$FILE")"
    git push origin main
done
