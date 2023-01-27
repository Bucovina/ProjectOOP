cat "${INPUT_FILENAME}" | ./bin/"${EXECUTABLE_NAME}" &
sleep 3 && xdotool search --name "Clicker-Game" key X &&
sleep 1 && xdotool search --name "Clicker-Game" key Y &&
sleep 1 && xdotool search --name "Clicker-Game" key X &&
sleep 1 && xdotool search --name "Clicker-Game" key Z &&
sleep 2 && xdotool search --name "Clicker-Game" key Alt+F4
