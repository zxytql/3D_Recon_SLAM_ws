#!/bin/bash
sudo chmod 777 /dev/ttyTCU0
sudo chmod 777 /dev/ttyTHS0
python_script="/home/elephant/myagv_ros/src/myagv_odometry/scripts/start_ydlidar.py"

if [ -f "$python_script" ];then
    python "$python_script"
else
    echo "Python file does not exist"
fi
