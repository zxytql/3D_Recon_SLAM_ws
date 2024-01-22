import numpy
import rosbag
import cv2
import os
from sensor_msgs.msg import Image
from cv_bridge import CvBridge
from cv_bridge import CvBridgeError

rgb_path = '/home/elephant/3D_Recon_SLAM_ws/rosbag/rgb/'# absolute path of extracted rgb images
depth_path = '/home/elephant/3D_Recon_SLAM_ws/rosbag/depth/'# absolute path of extracted depth images

bag_path = '/home/elephant/3D_Recon_SLAM_ws/rosbag/rgb_depth_1.bag'

rgb_txt_path = '/home/elephant/3D_Recon_SLAM_ws/rosbag/rgb.txt'
depth_txt_path = '/home/elephant/3D_Recon_SLAM_ws/rosbag/depth.txt'

bridge = CvBridge()
with open(rgb_txt_path, 'w') as txt_file_rgb:
    with open(depth_txt_path, 'w') as txt_file_depth:
        with rosbag.Bag(bag_path, 'r') as bag:
            # Write header lines
            txt_file_depth.write("# depth maps\n")
            txt_file_depth.write(f"# file: {bag_path}\n")
            txt_file_depth.write("# timestamp filename\n")

            txt_file_rgb.write("# rgb maps\n")
            txt_file_rgb.write(f"# file: {bag_path}\n")
            txt_file_rgb.write("# timestamp filename\n")        

            num_rgb = 1
            num_depth = 1

            for topic,msg,t in bag.read_messages():
                    
                if topic == "/camera/depth/image_raw": 
                    # 深度图
                    cv_image = bridge.imgmsg_to_cv2(msg, '16UC1')
                    # 归一化
                    normalized_depth = cv_image.astype(numpy.float32) / numpy.max(cv_image)
                    normalized_depth *= 255
                    cv_image = normalized_depth.astype(numpy.uint8)

                    timestr = "%.8f" %  msg.header.stamp.to_sec() # 时间戳命名
                    image_name = timestr + '.png'# an extension is necessary
                    # image_name = str(num_depth) + '.png'# 编号命名
                    cv2.imwrite(depth_path + image_name, cv_image)  

                    # 实际应用可直接保存为 numpy array
                    # np.save(depth_path + image_name, cv_image)  

                    # Write timestamp and filename to the text file
                    txt_file_depth.write("{:.6f} /depth/{:.6f}.png\n".format(t.to_sec(), t.to_sec()))
                    print(depth_path + image_name) # Shell输出
                    num_depth += 1

                if topic == "/camera/color/image_raw": 
                    # RGB
                    cv_image = bridge.imgmsg_to_cv2(msg, "bgr8")
                    timestr = "%.8f" %  msg.header.stamp.to_sec()
                    image_name = timestr + '.png'# an extension is necessary
                    # image_name = str(num_rgb) + '.png'

                    print(rgb_path + image_name) # Shell输出
                    cv2.imwrite(rgb_path + image_name, cv_image)

                    # Write timestamp and filename to the text file
                    txt_file_rgb.write("{:.6f} /rgb/{:.6f}.png\n".format(t.to_sec(), t.to_sec()))
                    num_rgb +=1 
