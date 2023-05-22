============
vmod_randomstr
============

----------------------
Varnish randomstr Module
----------------------

:Author: mech
:Date: 2023-05-22
:Version: 1.0
:Manual section: 3

SYNOPSIS
========

::

	import randomstr;
	randomstr.randomstr(<int>, <string>);

DESCRIPTION
===========

Varnish Module (vmod) for generating a random string of a given length.

FUNCTIONS
=========

Example VCL::

	backend foo { ... };

	import randomstr;

	sub vcl_recv {
		set req.http.foo = randomstr.randomstr(10);
	}

randomstr
------

Prototype
        ::

		 randomstr.randomst(STRING_LIST input)

Return value
	STRING
Description
	Returns a random string using characters a-zA-Z0-9-_.
Example
	::

		set resp.http.foo = randomstr.randomstr(10);

INSTALLATION
============

The source tree is based on autotools to configure the building, and
does also have the necessary bits in place to do functional unit tests
using the varnishtest tool.

Usage::

 ./configure VARNISHSRC=DIR [VMODDIR=DIR]

`VARNISHSRC` is the directory of the Varnish source tree for which to
compile your vmod. Both the `VARNISHSRC` and `VARNISHSRC/include`
will be added to the include search paths for your module.

Optionally you can also set the vmod install directory by adding
`VMODDIR=DIR` (defaults to the pkg-config discovered directory from your
Varnish installation).

Make targets:

* make - builds the vmod
* make install - installs your vmod in `VMODDIR`
* make check - runs the unit tests in ``src/tests/*.vtc``


HISTORY
=======

Version 1.0: Initial version.

COPYRIGHT
=========

This document is licensed under the same license as the
libvmod-urlcode project. See LICENSE for details.

* Copyright (c) 2023 Fandom Inc.
