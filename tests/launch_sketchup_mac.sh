#!/bin/bash
# Launches SketchUp on macOS, activates it (required to get it to focus and
# actually start), then waits for it to exit.
SKETCHUP_EXECUTABLE="$1"
shift

("$SKETCHUP_EXECUTABLE" "$@" & SKETCHUP_PID=$!) && \
  sleep 5 && \
  osascript -e 'tell application "SketchUp" to activate' && \
  wait $SKETCHUP_PID
