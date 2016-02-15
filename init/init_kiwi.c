/*
   Copyright (c) 2016, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#include "init_msm.h"

void common_properties();

void init_msm_properties(unsigned long msm_id, unsigned long msm_ver, char *board_type)
{
    char platform[PROP_VALUE_MAX];
    char model[110];
    FILE* fp;
    int rc;

    UNUSED(msm_id);
    UNUSED(msm_ver);
    UNUSED(board_type);

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    fp = fopen("/proc/app_info", "rb");
    while (fgets(model, 100, fp))
        if (strstr(model, "huawei_fac_product_name") != NULL)
            break;

    /* Honor 5x USA L24 */
    if (strstr(model, "L24") != NULL) {
        common_properties();
        property_set("ro.build.description", "KIW-L24-user 5.1.1 GRJ90 C567B140 release-keys");
        property_set("ro.build.fingerprint", "HONOR/KIW-L24/HNKIW-Q:5.1.1/HONORKIW-L24/C567B140:user/release-keys");
    }
    /* Honor 5x Russia L23 */
    else if (strstr(model, "L23") != NULL) {
        common_properties();
        property_set("ro.build.description", "KIW-L23-user 5.1.1 GRJ90 C567B140 release-keys");
        property_set("ro.build.fingerprint", "HONOR/KIW-L23/HNKIW-Q:5.1.1/HONORKIW-L23/C567B140:user/release-keys");
    }
    /* Honor 5x India L22 */
    else if (strstr(model, "L22") != NULL) {
        common_properties();
        property_set("ro.build.description", "KIW-L22-user 5.1.1 GRJ90 C567B140 release-keys");
        property_set("ro.build.fingerprint", "HONOR/KIW-L22/HNKIW-Q:5.1.1/HONORKIW-L22/C567B140:user/release-keys");
    }
    /* Honor 5x EU L21 */
    else if (strstr(model, "L21") != NULL) {
        common_properties();
        property_set("ro.build.description", "KIW-L21-user 5.1.1 GRJ90 C432B130 release-keys");
        property_set("ro.build.fingerprint", "HONOR/KIW-L21/HNKIW-Q:5.1.1/HONORKIW-L21/C432B130:user/release-keys");
    }
    /* Honor 5x A10 Unknown Variant 
    else if (strstr(model, "A10") != NULL) {
        property_set("ro.build.description", "KIW-A10-user 5.1.1 GRJ90 C432B130 release-keys");
        property_set("ro.build.fingerprint", "HONOR/KIW-A10/HNKIW-Q:5.1.1/HONORKIW-A10/C432B130:user/release-keys");
    }*/
    /* Honor 5x A20 Unknown Variant 
    else if (strstr(model, "A20") != NULL) {
        property_set("ro.build.description", "KIW-A20-user 5.1.1 GRJ90 C432B130 release-keys");
        property_set("ro.build.fingerprint", "HONOR/KIW-A20/HNKIW-Q:5.1.1/HONORKIW-A20/C432B130:user/release-keys");
    }*/
}

void common_properties();
{
    property_set("ro.product.model", "MSM8916 for arm64");
    property_set("ro.product.name", "msm8916_64");
}