# Copyright (C) 2020 Fluid
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

$(call inherit-product, device/xiaomi/miatoll/device.mk)
$(call inherit-product, vendor/fluid/config/common_full_phone.mk)
$(call inherit-product-if-exist, vendor/GoogleCamera/config.mk)

# Bootanimation Resolution
TARGET_BOOT_ANIMATION_RES := 1080

PRODUCT_NAME := fluid_miatoll
PRODUCT_DEVICE := miatoll
PRODUCT_BRAND := Xiaomi
PRODUCT_MODEL := SM6250
PRODUCT_MANUFACTURER := Xiaomi

PRODUCT_GMS_CLIENTID_BASE := android-xiaomi
IS_PHONE := true
TARGET_INCLUDE_GAPPS := true
TARGET_GAPPS_ARCH := arm64
DISABLE_DEFAULT_CAMERA := true
TARGET_SUPPORTS_GOOGLE_RECORDER := true



ifeq ($(WITH_GAPPS),true)
TARGET_INCLUDE_GAPPS := true
TARGET_GAPPS_ARCH := arm64
TARGET_SUPPORTS_GOOGLE_RECORDER := true
TARGET_INCLUDE_AOSP_REPLACEMENTS := true
else
TARGET_INCLUDE_GAPPS := false
PRODUCT_PACKAGES += \
    Dialer \
    Messaging \
    Browser2 \
    Gallery2
endif

# FLUID STUFF
FLUID_BUILD_TYPE := CXCKRXMS
PRODUCT_PRODUCT_PROPERTIES += \
    ro.fluid.maintainer=clownless \
    ro.fluid.cpu=SDM720G

# APNs
PRODUCT_COPY_FILES += \
    vendor/fluid/prebuilt/common/etc/apns-conf.xml:system/etc/apns-conf.xml