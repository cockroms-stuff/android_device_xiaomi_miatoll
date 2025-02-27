/*
 * Copyright (C) 2020 The LineageOS Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <cstdlib>
#include <cstring>
#include <sys/sysinfo.h>
#include <vector>

#include <android-base/properties.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>

#include "init_common.h"
#include "vendor_init.h"

using android::base::GetProperty;

std::vector<std::string> ro_props_default_source_order = {
    "",
    "odm.",
    "system.",
    "vendor.",
    "system_ext.",
};

void set_ro_build_prop(const std::string &source, const std::string &prop,
        const std::string &value, bool product = false) {
    std::string prop_name;

        prop_name = "ro." + source + "build." + prop;

    property_override(prop_name.c_str(), value.c_str(), false);
}

void set_device_props(const std::string fingerprint, const std::string description,
        const std::string brand, const std::string device, const std::string model) {
    for (const auto &source : ro_props_default_source_order) {
        set_ro_build_prop(source, "fingerprint", fingerprint);
        set_ro_build_prop(source, "brand", brand, true);
        set_ro_build_prop(source, "device", device, true);
        set_ro_build_prop(source, "model", model, true);
    }

    property_override("ro.product.system.brand", "google");
    property_override("ro.product.system.device", "generic");
    property_override("ro.product.system.manufacturer", "Google");
    property_override("ro.product.system.model", "mainline");
    property_override("ro.product.system.name", "mainline");
    property_override("ro.build.fingerprint", fingerprint.c_str());
    property_override("ro.build.description", description.c_str());
}

void load_device_properties() {
    std::string hwname = GetProperty("ro.boot.hwname", "");
    std::string region = GetProperty("ro.boot.hwc", "");

    if (hwname == "curtana") {
        if (region == "Global_TWO") {
            set_device_props(
                    "google/redfin/redfin:11/RQ1A.210105.003/7005429:user/release-keys",
                    "redfin-user 11 RQ1A.210105.003 7005429 release-keys",
                    "Redmi", "curtana", "Redmi Note 9S");
            property_override("ro.product.device", "Redmi Note 9S");
            property_override("ro.build.version.security_patch", "2021-01-05");
            property_override("ro.vendor.build.security_patch", "2021-01-05");
        } else if (region == "India") {
            set_device_props(
                    "google/redfin/redfin:11/RQ1A.210105.003/7005429:user/release-keys",
                    "redfin-user 11 RQ1A.210105.003 7005429 release-keys",
                    "Redmi", "curtana", "Redmi Note 9 Pro");
            property_override("ro.product.device", "Redmi Note 9 Pro");
            property_override("ro.build.version.security_patch", "2021-01-05");
            property_override("ro.vendor.build.security_patch", "2021-01-05");
        }
    } else if (hwname == "excalibur") {
        set_device_props(
                "google/redfin/redfin:11/RQ1A.210105.003/7005429:user/release-keys",
                "redfin-user 11 RQ1A.210105.003 7005429 release-keys",
                "Redmi", "excalibur", "Redmi Note 9 Pro Max");
        property_override("ro.product.device", "Redmi Note 9 Pro Max");
        property_override("ro.build.version.security_patch", "2021-01-05");
        property_override("ro.vendor.build.security_patch", "2021-01-05");
    } else if (hwname == "gram") {
        set_device_props(
                "google/redfin/redfin:11/RQ1A.210105.003/7005429:user/release-keys",
                "redfin-user 11 RQ1A.210105.003 7005429 release-keys",
                "POCO", "gram", "POCO M2 Pro");
        property_override("ro.product.device", "POCO M2 Pro");
        property_override("ro.build.version.security_patch", "2021-01-05");
        property_override("ro.vendor.build.security_patch", "2021-01-05");
    } else if (hwname == "joyeuse") {
        set_device_props(
                "google/redfin/redfin:11/RQ1A.210105.003/7005429:user/release-keys",
                "redfin-user 11 RQ1A.210105.003 7005429 release-keys",
                "Redmi", "joyeuse", "Redmi Note 9 Pro");
        property_override("ro.product.device", "Redmi Note 9 Pro");
        property_override("ro.build.version.security_patch", "2021-01-05");
        property_override("ro.vendor.build.security_patch", "2021-01-05");
    }
}

void vendor_load_properties() {
    load_common_properties();
    load_device_properties();
}
