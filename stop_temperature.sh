ps aux | grep [start]_temperature.sh | awk '{print $2}' | xargs kill
