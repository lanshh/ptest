LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := rk-test
LOCAL_FORCE_STATIC_EXECUTABLE := true
LOCAL_C_INCLUDES += \
    bionic \
    external/stlport/stlport \
    $(LOCAL_PATH)/Language \
    external/libpng/

LOCAL_CFLAGS += -w

LOCAL_SRC_FILES := main.c

LOCAL_MODULE_TAGS := optional
LOCAL_STATIC_LIBRARIES := libc libcutils liblog
include $(BUILD_EXECUTABLE)