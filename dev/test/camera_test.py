# Camera test
import sys
import cv2

window_name = "Camera test"

def camera_test():
    # assigning path to camera
    camera_id = "/dev/video0"
    video_cap = cv2.VideoCapture(camera_id, cv2.CAP_V4L2)

    if video_cap.isOpened():
        try:
            window_handling = cv2.namedWindow(
                window_name, cv2.WINDOW_AUTOSIZE)
            while True:
                ret_val, frame = video_cap.read()

                if cv2.getWindowProperty(window_name, cv2.WND_PROP_AUTOSIZE) >= 0:
                    cv2.imshow(window_name, frame)
                else:
                    break
                key_code = cv2.waitKey(10) & 0xFF

                # Stop the program using ESC
                if key_code == 27:
                    break

        finally:
            video_capture.release()
            cv2.destroyAllWindows()
    else:
        print("Error: Unable to open camera")


if __name__ == "__main__":
    camera_test()
