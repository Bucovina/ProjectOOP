cat "${INPUT_FILENAME}" | valgrind --leak-check=full --track-origins=yes --error-exitcode=0 ./bin/"${EXECUTABLE_NAME}" &
sleep 10 && xdotool search --name "Clicker-Game" key X &&
sleep 1 && xdotool search --name "Clicker-Game" key Y &&
sleep 1 && xdotool search --name "Clicker-Game" key X &&
sleep 1 && xdotool search --name "Clicker-Game" key Z &&
sleep 2 && xdotool search --name "Clicker-Game" key Alt+F4

