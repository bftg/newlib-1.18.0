/* Copyright (c) 2002 Red Hat Incorporated.
   All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:

     Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.

     Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.

     The name of Red Hat Incorporated may not be used to endorse
     or promote products derived from this software without specific
     prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
   IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
   ARE DISCLAIMED.  IN NO EVENT SHALL RED HAT INCORPORATED BE LIABLE FOR ANY
   DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
   ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS   
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/*
FUNCTION
	<<iswspace>>---whitespace wide character test

INDEX
	iswspace

ANSI_SYNOPSIS
	#include <wctype.h>
	int iswspace(wint_t <[c]>);

TRAD_SYNOPSIS
	#include <wctype.h>
	int iswspace(<[c]>)
	wint_t <[c]>;

DESCRIPTION
<<iswspace>> is a function which classifies wide-character values that
are categorized as whitespace.

RETURNS
<<iswspace>> returns non-zero if <[c]> is a whitespace wide character.

PORTABILITY
<<iswspace>> is C99.

No supporting OS subroutines are required.
*/
#include <_ansi.h>
#include <newlib.h>
#include <wctype.h>
#include <ctype.h>
#include <string.h>
#include "local.h"

int
_DEFUN(iswspace,(c), wint_t c)
{
#ifdef _MB_CAPABLE
  c = _jp2uc (c);
  return ((c >= 0x0009 && c <= 0x000d) || c == 0x0020 ||
	  c == 0x00A0 || c == 0x1680 ||
	  (c >= 0x2000 && c <= 0x2006) ||
	  (c >= 0x2008 && c <= 0x200b) ||
	  c == 0x2028 || c == 0x2029 ||
	  c == 0x205f || c == 0x3000);
#else
  return (c < 0x100 ? isspace (c) : 0);
#endif /* _MB_CAPABLE */
}

