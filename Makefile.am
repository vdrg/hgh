## Autotools settings

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = \
	autogen.sh \
	src/static/resources.xml \
	src/static/screen.css

CLEANFILES =

bin_PROGRAMS = \
	hgh

TESTS = \
	$(check_PROGRAMS)

### Templates (add 2 rules per template, one for .c and one for .h)

### Static resources

src/static/resources.c: src/static/resources.xml $(shell $(GLIB_COMPILE_RESOURCES) --generate-dependencies --sourcedir $(top_srcdir)/src/static $(top_srcdir)/src/static/resources.xml)
	$(AM_V_GEN)$(GLIB_COMPILE_RESOURCES) --generate --sourcedir $(top_srcdir)/src/static --target $@ $<

src/static/resources.h: src/static/resources.xml $(shell $(GLIB_COMPILE_RESOURCES) --generate-dependencies --sourcedir $(top_srcdir)/src/static $(top_srcdir)/src/static/resources.xml)
	$(AM_V_GEN)$(GLIB_COMPILE_RESOURCES) --generate --sourcedir $(top_srcdir)/src/static --target $@ $<


## Build rules: binary

hgh_SOURCES = \
	src/main.c

nodist_hgh_SOURCES = \
	src/templates/base.c \
	src/templates/base.h \
	src/static/resources.c \
	src/static/resources.h

src/hgh-main.$(OBJEXT): $(nodist_hgh_SOURCES)

hgh_CFLAGS = \
	$(BALDE_CFLAGS) \
	-I$(top_builddir)/src \
	-I$(top_srcdir)/src

hgh_LDADD = \
	$(BALDE_LIBS)


## Helpers: Local clean

clean-local:
	rm -f src/{static}/*.{c,h}


## Helpers: Valgrind runners

if USE_VALGRIND
valgrind: all
	$(MAKE) check TESTS_ENVIRONMENT=" \
		G_SLICE=always-malloc \
		G_DEBUG=gc-friendly \
		$(LIBTOOL) \
			--mode=execute \
			$(VALGRIND) \
				--tool=memcheck \
				--leak-check=full \
				--leak-resolution=high \
				--num-callers=20 \
				--show-possibly-lost=no"
endif
