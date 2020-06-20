# Get video modes supported by the USB camera.
# Example output:
#   YUY2:800x600:24/1
#   YUY2:1920x1080:5/1
v4l2-ctl --list-formats-ext --device /dev/video1

# Classify objects the camera can see.
# (Open turret:4664 to view)
edgetpu_classify_server \
--source /dev/video1:YUY2:1920x1080:5/1  \
--model ~/demo_files/mobilenet_v2_1.0_224_quant_edgetpu.tflite \
--labels ~/demo_files/imagenet_labels.txt

# Detect faces.
# (Open turret:4664 to view)
edgetpu_detect_server \
--source /dev/video1:YUY2:1920x1080:5/1  \
--model ~/demo_files/mobilenet_ssd_v2_face_quant_postprocess_edgetpu.tflite

# Detect objects.
# (Open turret:4664 to view)
edgetpu_detect_server \
--source /dev/video1:YUY2:1920x1080:5/1  \
--model ~/demo_files/mobilenet_ssd_v2_coco_quant_postprocess_edgetpu.tflite \
--labels ~/demo_files/coco_labels.txt

# Detect objects.
# (Open turret:4664 to view)
edgetpu_detect_server \
--source /dev/video1:YUY2:800x600:24/1  \
--model ~/demo_files/mobilenet_ssd_v2_coco_quant_postprocess_edgetpu.tflite \
--labels ~/demo_files/coco_labels.txt
