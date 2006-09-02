## Automake template for Inform based off of demos folder from inform source
## distro.

SLAGFILES = @PACKAGE@_hints.slg

HINTFILES = @PACKAGE@_hints.h @PACKAGE@_hints.z5

EXTRA_DIST = $(SLAGFILES) slag

PERL = @PERL@

#ROT13 = tr 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ'\
#           'nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM'
ROT13 = tr 'a-mA-Mn-zN-Z' 'n-zN-Za-mA-M' 

SLAG = ./slag

SLAGFLAGS = -q

SUFFIXES = .slg .h .inf .z5

.slg.h:
	@if test "x$(PERL)" = "xno"; \
	then echo "Building hint routines in $@ ..."; \
	echo "[ SLAG_RunMenus; \"Hints unavaliable.\"; ];" > $@; \
	else cat $< | $(ROT13) | $(SLAG) -s $(SLAGFLAGS) - $@; \
	fi

.slg.inf:
	@if test "x$(PERL)" != "xno"; \
	then cat $< | $(ROT13) | $(SLAG) $(SLAGFLAGS) - $@; \
	fi

.inf.z5: %.inf
	@if test "x$(PERL)" != "xno"; \
	then echo "Building Invisiclues in $@ ..."; \
	cd $(top_srcdir)/src; \
	$(MAKE) $(top_srcdir)/hints/$@; \
	mv $(top_srcdir)/src/$@ $(top_srcdir)/hints/$@; \
	fi

all: $(HINTFILES)

$(HINTFILES): $(SLAG)

CLEANFILES = $(HINTFILES)
