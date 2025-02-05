SUMMARY = "showiframe for ${MACHINE}"
SECTION = "base"
PRIORITY = "optional"
LICENSE = "CLOSED"
RDEPENDS:${PN} = "libjpeg-turbo"

PACKAGE_ARCH = "${MACHINE_ARCH}"

PV = "${SRCDATE}"

RPROVIDES:${PN}  = "showiframe"
RREPLACES:${PN}  = "showiframe"
RCONFLICTS:${PN} = "showiframe"

SRC_URI = "http://source.mynonpublic.com/dinobot/${MACHINETYPE}-showiframe-${SRCDATE}.tar.gz"

S = "${WORKDIR}"

do_install() {
    install -d ${D}${bindir}
    install -m 0755 ${S}/showiframe ${D}${bindir}
}

do_package_qa() {
}

FILES:${PN}  = "${bindir}/showiframe"
