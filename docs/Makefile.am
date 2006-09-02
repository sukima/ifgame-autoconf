## Automake template for Inform based off of demos folder from inform source
## distro.

INFORM_TEXT_FILES = intro.txt

HFILES = intro.h

EXTRA_DIST = $(INFORM_TEXT_FILES) npc.txt puzzles.txt story.txt

SUFFIXES = .txt .h

.txt.h:; \
	if test -f $@; then rm $@; fi; \
	echo "! This file is generated automatically." > $@; \
	echo "! Edit $< to make changes." >> $@; \
	echo >> $@; \
	echo "Constant HAVE_$*Text;" >> $@; \
	echo "[ $*Text;" >> $@; \
	cat $< | sed 's/"/~/g' | sed 's/^.*$$/  print "&^";/' >> $@; \
	echo "];" >> $@; \
	echo >> $@; \
	echo "! vim:et:sw=2 ft=inform" >> $@

all: $(HFILES)

$(HFILES):

CLEANFILES = $(HFILES)
