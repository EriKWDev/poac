add_poac_target(poac_core_resolver
    SOURCES
        sat.cc
        resolve.cc
    INCLUDES
        ${POAC_HPP_INCLUDES}
        ${OPENSSL_INCLUDE_DIR}
    LIBRARIES
        ${POAC_HPP_LIBS}
        poac_util_net
        poac_util_semver
        poac_util_misc
        poac_util_pretty
)
