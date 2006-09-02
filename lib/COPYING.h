
message
"    This program is distributed in the hope that it will be useful,
^    but WITHOUT ANY WARRANTY; without even the implied warranty of
^    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
^    GNU General Public License for more details.^";

!		pAb-032871  Fri, Jan 26, 2001  2:54:31 PM

! Changed to a relative include because the path to lib is part of
! the automake system.
	include "COPYING_tx";
!	include ">COPYING_tx.h.";
!	include ">COPYING_LIB_tx.h.";

[ COPYING        !  This is a lot of text for the Z-Machine to print-up in
                 !  one shot, so occasionally, these routines ask the user
  whichLicense   !  to press a key for more, eg: "confirm".  I hope the
  whichPage      !  other routine's weird spelling -=- C0PY1NG -=- will
  input          !  prevent this from conflicting with any routine names,
  width margin   !  arrays, or globals you might already have in your own
  txOut;         !  program.

@erase_window -1;

box	"   The following document was meant   "
	"  to be passed around. If you do not  "
	" already have a transcript going, you "
	"   can start one now and save this    "
	"       license to a text file.        "
	""
	" Would you like a transcript?   [Y/N] ";

@read_char 1 input;
if(input == 'y' or 'Y')	{txOut++;	@output_stream 2;}
@erase_window -1;

width = (0 -> 33);	if(width == 0)	{width = 80;}
if(width > 60){
	margin = (width / 2) - 30;
	@set_window 1;
	@split_window 2;
	style reverse; font off;

	@set_cursor 1 1;	spaces(width);
	@set_cursor 1 margin;
	print " Press any key (except ~X~, ~Z~, ~C~, and ~.~) to continue.";
	@set_cursor 2 1;	spaces(width);
	@set_cursor 2 margin;
	print "            Press ~X~, ~Z~, ~C~, or ~.~ to cancel.";
	@set_cursor 1 1;

	@set_window 0;
	style roman; font on;
}
font off;
switch(whichLicense){
	0: C0PY1NG();
	!1: C0PY1NG_L1B();
  }
!	This routine begins by turning font off, and then turns it on again
!	at at the end [also does this if cancelled partway through].  If
!	you want to *keep* fonts turned off in your Inform program, for
!	whatever reason, follow any COPYING(); function calls with another
!	"font off;" [or delete the "font on;"s AND "off;"s if the whole
!	thing is supposed to be fixed-width].

do{

whichPage++;

if(	((whichLicense == 0) && (whichPage ~= 8 or 9)) ||
	((whichLicense == 1) && (whichPage ~= 12 or 13)) )
	{@read_char 1 input;}
switch(input){
  'x' , 'X' ,
  'z' , 'Z' ,
  'c' , 'C' ,
  '.' :	whichPage=20;

  default:	switch(whichLicense){
		0: C0PY1NG(whichPage);
		!1: C0PY1NG_L1B(whichPage);
	}
  }
}until(	((whichLicense == 0) && (whichPage > 9)) ||
	((whichLicense == 1) && (whichPage > 13)) );

@erase_window -1;

if(txOut == 1){
  @output_stream -2;
  new_line;	spaces((width / 2) - 7);
  print	"Transcript Off.^^";
  }
font on;
];
