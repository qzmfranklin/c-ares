licenses(['notice'])

# How to write this BUILD file?
#
# Read through INSTALL.md.
#
# Short version on Linux:
#   ./buildconf
#   ./configure
#   ./make -j8 &> build.log

pkg_dir = package_name() if package_name else '.'

if native.repository_name() != '@':
    gendir = '$(GENDIR)/external/' + native.repository_name().lstrip('@')
else:
    gendir = '$(GENDIR)'

cc_library(
    name = 'ares',
    visibility = [
        '//visibility:public',
    ],
    srcs = [
        'ares__close_sockets.c',
        'ares__get_hostent.c',
        'ares__read_line.c',
        'ares__timeval.c',
        'ares_cancel.c',
        'ares_create_query.c',
        'ares_data.c',
        'ares_destroy.c',
        'ares_expand_name.c',
        'ares_expand_string.c',
        'ares_fds.c',
        'ares_free_hostent.c',
        'ares_free_string.c',
        'ares_getenv.c',
        'ares_gethostbyaddr.c',
        'ares_gethostbyname.c',
        'ares_getnameinfo.c',
        'ares_getopt.c',
        'ares_getsock.c',
        'ares_init.c',
        'ares_library_init.c',
        'ares_llist.c',
        'ares_mkquery.c',
        'ares_nowarn.c',
        'ares_options.c',
        'ares_parse_a_reply.c',
        'ares_parse_aaaa_reply.c',
        'ares_parse_mx_reply.c',
        'ares_parse_naptr_reply.c',
        'ares_parse_ns_reply.c',
        'ares_parse_ptr_reply.c',
        'ares_parse_soa_reply.c',
        'ares_parse_srv_reply.c',
        'ares_parse_txt_reply.c',
        'ares_platform.c',
        'ares_process.c',
        'ares_query.c',
        'ares_search.c',
        'ares_send.c',
        'ares_strcasecmp.c',
        'ares_strdup.c',
        'ares_strerror.c',
        'ares_timeout.c',
        'ares_version.c',
        'ares_writev.c',
        'bitncmp.c',
        'inet_net_pton.c',
        'inet_ntop.c',
        'windows_port.c',

    ],
    hdrs = [
        'ares.h',
        # These two headers files are generated.
        #'ares_build.h',
        #'ares_config.h',
        'ares_data.h',
        'ares_dns.h',
        'ares_getenv.h',
        'ares_getopt.h',
        'ares_inet_net_pton.h',
        'ares_iphlpapi.h',
        'ares_ipv6.h',
        'ares_library_init.h',
        'ares_llist.h',
        'ares_nowarn.h',
        'ares_platform.h',
        'ares_private.h',
        'ares_rules.h',
        'ares_setup.h',
        'ares_strcasecmp.h',
        'ares_strdup.h',
        'ares_version.h',
        'bitncmp.h',
        'config-win32.h',
        'nameser.h',
        'setup_once.h',
    ] + [
        ':generated_headers',
    ],
    copts = [
        '-D_GNU_SOURCE',
        '-D_HAS_EXCEPTIONS=0',
        '-DNOMINMAX',
        '-DHAVE_CONFIG_H',
        '-I%s' % gendir,
    ],
    includes = ['.'] if package_name() else [],
)

GENERATED_HEADERS = [
    'ares_build.h',
    'ares_config.h',
]

genrule(
    name = 'generated_headers',
    outs = GENERATED_HEADERS,
    srcs = glob([
        '**/*',

        # TODO: More specifically list the files.  The list below is not
        # complete yet, but is a good starting point.
        #'**/*.in',
        #'Makefile.am',
        #'Makefile.inc',
        #'acinclude.m4',
        #'ares_init.c',
        #'ares_ipv6.h',
        #'configure.ac',
        #'m4/cares-functions.m4',
    ], exclude = [
        # TODO: Once the list above is completed, this 'exclude' cluase should
        # be removed.
        '*.1',
        '*.3',
    ]),
    tools = [
        'buildconf',
    ],
    cmd = ' && '.join([
        'cd %s' % pkg_dir,
        './buildconf &> /dev/null',
        './configure &> /dev/null',
        'cd -',
    ] + [ 'mv {0}/{1} $(location {1})'.format(pkg_dir, f) \
                for f in GENERATED_HEADERS
    ]),
)
