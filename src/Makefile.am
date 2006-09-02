## Automake template for Inform based off of demos folder from inform source
## distro.

zcodedir = $(datadir)/zcode
zcode_DATA = $(ZFILES)

# Included custom *.h files in INFFILES
INFFILES = @PACKAGE@.inf

ZFILES = @PACKAGE@.z5

# Modules (*.m5)
MFILES = 

EXTRA_DIST = $(INFFILES)

INFORM = @INFORM@

INCPATH = @INFORM_INCLUDE_PATH@,$(top_srcdir)/lib,$(top_srcdir)/hints,$(top_srcdir)/docs
MODPATH = @INFORM_MODULE_PATH@,$(top_srcdir)/lib,$(top_srcdir)/hints

INFFLAGS = -ix -E1 @INFORM_SWITCHES@ +include_path=$(INCPATH) +module_path=$(MODPATH)

SUFFIXES = .inf .z5 .h .m5

.inf.z5:; $(INFORM) $(INFFLAGS) $<

.h.m5:; $(INFORM) -M $(INFFLAGS) $<

all: $(MFILES) $(ZFILES)

$(ZFILES): $(INFFILES) $(MFILES) $(INFORM)

$(MFILES): $(INFORM)

CLEANFILES = $(MFILES) $(ZFILES)
