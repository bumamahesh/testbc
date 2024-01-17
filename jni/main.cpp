

#include <android/native_window.h>
#include <android/native_window_jni.h>
#include <camera/NdkCameraManager.h>
#include <android/log.h>
#include <android/camera.h>
#include <camera/NdkCameraMetadata.h>
#include <camera/NdkCameraManager.h>
#include <camera/NdkCameraDevice.h>

void captureImage()
{
#if 1
    ACameraManager* cameraManager = nullptr;
    ACameraDevice* cameraDevice = nullptr;
    ACaptureRequest* captureRequest = nullptr;
    ACameraOutputTarget* outputTarget = nullptr;

    // Initialize camera manager
    camera_status_t status = ACameraManager_create(&cameraManager);
    if (status != ACAMERA_OK) {
        __android_log_print(ANDROID_LOG_ERROR, "CameraCapture", "Failed to create CameraManager");
        return;
    }

    // Get camera ID (Assuming cameraId "0" for the back camera)
    const char* cameraId = "0";

    // Open the camera
    status = ACameraManager_openCamera(cameraManager, cameraId, nullptr, &cameraDevice);
    if (status != ACAMERA_OK) {
        __android_log_print(ANDROID_LOG_ERROR, "CameraCapture", "Failed to open camera");
        ACameraManager_delete(cameraManager);
        return;
    }

    // Create a capture request
    status = ACameraDevice_createCaptureRequest(cameraDevice, ACAMERA_TEMPLATE_PREVIEW, &captureRequest);
    if (status != ACAMERA_OK) {
        __android_log_print(ANDROID_LOG_ERROR, "CameraCapture", "Failed to create capture request");
        ACameraDevice_close(cameraDevice);
        ACameraManager_delete(cameraManager);
        return;
    }

    // Get the native window from an ANativeWindow or other sources
    ANativeWindow* nativeWindow = nullptr;  // Replace with your actual native window

    // Create an output target
    status = ACaptureRequest_addTarget(captureRequest, outputTarget);
    if (status != ACAMERA_OK) {
        __android_log_print(ANDROID_LOG_ERROR, "CameraCapture", "Failed to add output target");
        ACameraOutputTarget_free(outputTarget);
        ACameraDevice_close(cameraDevice);
        ACameraManager_delete(cameraManager);
        return;
    }

    // Capture the image
    status = ACameraCaptureSession_capture(cameraCaptureSession, nullptr, 1, &captureRequest, nullptr);
    if (status != ACAMERA_OK) {
        __android_log_print(ANDROID_LOG_ERROR, "CameraCapture", "Failed to capture image");
    }

    // Clean up
    ACaptureRequest_free(captureRequest);
    ACameraDevice_close(cameraDevice);
    ACameraManager_delete(cameraManager);
#endif
}

int main()
{
    captureImage();
    return 0;
}
