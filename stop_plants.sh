ps aux | grep [start]_plants.sh | awk '{print $2}' | xargs kill
