AC_PREREQ(2.59)
AC_COPYRIGHT([Copyright (c) 2011 Varnish Software AS])
AC_INIT([libvmod-randomstr], [master])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR(src/vmod_randomstr.vcc)
AM_CONFIG_HEADER(config.h)

AC_CANONICAL_SYSTEM
AC_LANG(C)

AM_INIT_AUTOMAKE([foreign])

AC_GNU_SOURCE
AC_PROG_CC
AC_PROG_CC_STDC
if test "x$ac_cv_prog_cc_c99" = xno; then
	AC_MSG_ERROR([Could not find a C99 compatible compiler])
fi
AC_PROG_CPP

AC_PROG_INSTALL
AC_PROG_LIBTOOL
AC_PROG_MAKE_SET

# Check for rst utilities
AC_CHECK_PROGS(RST2MAN, [rst2man rst2man.py], "no")
if test "x$RST2MAN" = "xno"; then
	AC_MSG_WARN([rst2man not found - not building man pages])
fi
AM_CONDITIONAL(HAVE_RST2MAN, [test "x$RST2MAN" != "xno"])

# Check for pkg-config
PKG_PROG_PKG_CONFIG

# Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS([sys/stdlib.h])

# Check for python
AC_CHECK_PROGS(PYTHON, [python3 python3.1 python3.2 python2.7 python2.6 python2.5 python2 python], [AC_MSG_ERROR([Python is needed to build this vmod, please install python.])])

# Varnish include files tree
VARNISH_VMOD_INCLUDES
VARNISH_VMOD_DIR
VARNISH_VMODTOOL

# backwards compat with older pkg-config
# - pull in AC_DEFUN from pkg.m4
m4_ifndef([PKG_CHECK_VAR], [
# PKG_CHECK_VAR(VARIABLE, MODULE, CONFIG-VARIABLE,
# [ACTION-IF-FOUND], [ACTION-IF-NOT-FOUND])
# -------------------------------------------
# Retrieves the value of the pkg-config variable for the given module.
AC_DEFUN([PKG_CHECK_VAR],
[AC_REQUIRE([PKG_PROG_PKG_CONFIG])dnl
AC_ARG_VAR([$1], [value of $3 for $2, overriding pkg-config])dnl

_PKG_CONFIG([$1], [variable="][$3]["], [$2])
AS_VAR_COPY([$1], [pkg_cv_][$1])

AS_VAR_IF([$1], [""], [$5], [$4])dnl
])# PKG_CHECK_VAR
])

PKG_CHECK_MODULES([libvarnishapi], [varnishapi])
PKG_CHECK_VAR([LIBVARNISHAPI_BINDIR], [varnishapi], [bindir])
PKG_CHECK_VAR([LIBVARNISHAPI_SBINDIR], [varnishapi], [sbindir])

AC_PATH_PROG([VARNISHTEST], [varnishtest], [],
    [$LIBVARNISHAPI_BINDIR:$LIBVARNISHAPI_SBINDIR:$PATH])
AC_PATH_PROG([VARNISHD], [varnishd], [],
    [$LIBVARNISHAPI_SBINDIR:$LIBVARNISHAPI_BINDIR:$PATH])

AC_CONFIG_FILES([
	Makefile
	src/Makefile
])
AC_OUTPUT
