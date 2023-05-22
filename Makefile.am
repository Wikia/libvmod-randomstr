AM_CPPFLAGS = @VMOD_INCLUDES@

vmoddir = @VMOD_DIR@
vmod_LTLIBRARIES = libvmod_randomstr.la

libvmod_randomstr_la_LDFLAGS = -module -export-dynamic -avoid-version

libvmod_randomstr_la_SOURCES = vmod_randomstr.c

nodist_libvmod_randomstr_la_SOURCES = \
	vcc_if.c \
	vcc_if.h

vmod_randomstr.c: vcc_if.h

vmod_selector.lo: $(nodist_libvmod_selector_la_SOURCES)

vcc_if.h: vcc_if.c

vcc_if.c: vmod_randomstr.vcc
	@VMODTOOL@ $(top_srcdir)/src/vmod_randomstr.vcc

check:
	PATH=@LIBVARNISHAPI_SBINDIR@:$$PATH \
	@VARNISHTEST@ -Dvmod_topbuild=$(abs_top_builddir) $(srcdir)/tests/*.vtc

EXTRA_DIST = \
	vmod_randomstr.vcc \
	$(VMOD_TESTS)

CLEANFILES = $(builddir)/vcc_if.c $(builddir)/vcc_if.h
