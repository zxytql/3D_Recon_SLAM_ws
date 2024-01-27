
# 清除img文件
cd ~/3D_Recon_SLAM_ws/rosbag/depth
rm -r *.png
cd ~/3D_Recon_SLAM_ws/rosbag/rgb
rm -r *.png

# 清除生成的txt
cd ~/3D_Recon_SLAM_ws/rosbag
rm depth.txt groundtruth.txt rgb.txt
