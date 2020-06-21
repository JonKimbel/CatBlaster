# Demo commands

These commands can be executed once you've installed the camera demos as
documented
[here](https://coral.ai/docs/dev-board/camera/#run-a-demo-with-the-camera).

## Get video modes supported by the USB camera.

```
v4l2-ctl --list-formats-ext --device /dev/video1
```

Example output:

```
YUY2:800x600:24/1
YUY2:1920x1080:5/1
```

## Classify objects the camera can see.

```
edgetpu_classify_server \
--model ~/demo_files/mobilenet_v2_1.0_224_quant_edgetpu.tflite \
--labels ~/demo_files/imagenet_labels.txt \
--source /dev/video1:YUY2:1920x1080:5/1
```

Open `<HOSTNAME>:4664` to view. The "source" arg isn't needed for the Coral
camera.

## Detect faces.

```
edgetpu_detect_server \
--model ~/demo_files/mobilenet_ssd_v2_face_quant_postprocess_edgetpu.tflite \
--source /dev/video1:YUY2:1920x1080:5/1
```

Open `<HOSTNAME>:4664` to view. The "source" arg isn't needed for the Coral
camera.

## Detect objects.

```
edgetpu_detect_server \
--model ~/demo_files/mobilenet_ssd_v2_coco_quant_postprocess_edgetpu.tflite \
--labels ~/demo_files/coco_labels.txt \
--source /dev/video1:YUY2:1920x1080:5/1
```

Open `<HOSTNAME>:4664` to view. The "source" arg isn't needed for the Coral
camera.

## Detect objects.

```
edgetpu_detect_server \
--model ~/demo_files/mobilenet_ssd_v2_coco_quant_postprocess_edgetpu.tflite \
--labels ~/demo_files/coco_labels.txt \
--source /dev/video1:YUY2:800x600:24/1
```

Open <HOSTNAME>:4664 to view. The "source" arg isn't needed for the Coral
camera.
