# We know about rtc
KERNEL_MODULE_AUTOLOAD += "xfs"
MACHINE_FEATURES_BACKFILL_CONSIDERED = "rtc"
KERNEL_MODULE_AUTOLOAD += "xhci-plat-hcd"
KERNEL_MODULE_AUTOLOAD += "ehci-platform"
KERNEL_MODULE_AUTOLOAD += "ohci-platform"
KERNEL_MODULE_AUTOLOAD += "cfg80211"

MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
    kernel-module-xhci-plat-hcd \
    kernel-module-ehci-platform \
    kernel-module-ohci-platform \
    dinobot-dvb-modules-${MACHINETYPE} \
    dinobot-hihalt-${MACHINETYPE} \
    dinobot-pvr \
    dinobot-lib-helper \
    dinobot-libs-${MACHINETYPE} \
    rt8188fu \
    firmware-rt8188fu \
    ${@bb.utils.contains('MACHINE_FEATURES', 'emmc', 'resizerootfs' , '', d)} \
    dinobot-partitions-${SOC_FAMILY} \
"

MACHINE_FEATURES += "switchoff hdmicec blindscan alsa transcoding hiaccel"

PREFERRED_VERSION_linux-dinobot = "4.4.35"
PREFERRED_VERSION_directfb = "1.7.7"
PREFERRED_PROVIDER_virtual/egl = "dinobot-opengl-${SOC_FAMILY}" 
PREFERRED_PROVIDER_virtual/libgles1 = "dinobot-opengl-${SOC_FAMILY}"
PREFERRED_PROVIDER_virtual/libgles2 = "dinobot-opengl-${SOC_FAMILY}"
PREFERRED_PROVIDER_virtual/kodi = "stb-kodi-${MACHINETYPE}"
PREFERRED_PROVIDER_virtual/blindscan-dvbs = "dinobot-blindscan-${MACHINETYPE}"

PREFERRED_PROVIDER_virtual/kernel = "linux-dinobot"
PREFERRED_RPROVIDER_showiframe = "dinobot-showiframe-${MACHINETYPE}"
PREFERRED_RPROVIDER_aio-grab = "dinobot-grab-${MACHINETYPE}"

MACHINE_EXTRA_RRECOMMENDS += " \
    gstreamer1.0-plugin-dvbmediasink \
    gstreamer1.0-libav \
    "   
require conf/machine/include/tune-cortexa15.inc
require conf/machine/include/soc-family.inc

DVBMEDIASINK_CONFIG = "--with-h265 --with-vb8 --with-vb9 --with-spark --with-wma --with-wmv --with-pcm --with-dts --with-eac3"

DEPENDS_append_pn-enigma2 = " dinobot-libs-${MACHINETYPE} "
