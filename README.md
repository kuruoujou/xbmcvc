xbmcvc
======

_xbmcvc_ is a program for controlling XBMC (http://xbmc.org/) with simple voice commands. It uses CMU Sphinx for speech recognition.

Requirements
------------

To use _xbmcvc_, the following libraries need to be installed on your system:

* _pocketsphinx_ along with its prerequisite, _sphinxbase_ (http://cmusphinx.sourceforge.net/wiki/download/) Note: you should use the version from the sourceforge page. In ubuntu at least, the version in the repository is out of date and will not work with xbmcvc.
* _libcurl_ (shipped with cURL, should be present on most systems; if that's not your case, go to http://curl.haxx.se/libcurl/)

For _xbmcvc_ to work, you need an XBMC version which supports JSON-RPC API version 3 or higher, which means any pre-11.0 (pre-Eden) or newer version should work. Older releases (including Dharma) are not supported.

Installation
------------

    git clone https://github.com/kempniu/xbmcvc
    make
    make install

After performing the above steps, you should be able to run the program by executing:

    xbmcvc

__NOTE:__ the user running _xbmcvc_ should be allowed to access your sound card. On the Gentoo distribution, for instance, this is achieved by adding the user to the _audio_ group.

_xbmcvc_ uses JSON-RPC via HTTP for passing commands to XBMC. In order for this to work, you need to go to the network settings page in XBMC (_System_ -> _Settings_ -> _Network_ -> _Services_) and turn _Allow control of XBMC via HTTP_ on.

Usage
-----

At startup, _xbmcvc_ will initialize the speech recognition library and, after successfully self-calibrating to properly tell silence and speech apart, it will start listening to your commands. If you get an error saying _Failed to calibrate voice activity detection_, please check your mixer levels for capturing audio.

_xbmcvc_ recognizes a limited set of commands listed alphabetically in file __model/xbmcvc.vocab__. Just try saying them to the microphone and see what happens - the commands should be pretty self-explanatory.

Language support
----------------

Currently _xbmcvc_ only supports voice commands spoken in English. Additional languages may be added in the future.

Caveats
-------

To avoid confusion, _xbmcvc_ will perform a maximum of 5 actions at a time. You can say more voice commands than that, but only the first five recognized commands will be executed.

If you are trying to control an XBMC instance installed on a different machine than the one you're running _xbmcvc_ on (or your XBMC listens on a non-standard port), make sure you pass the correct hostname and port number to _xbmcvc_ via its __-H__ and __-P__ command line switches, respectively. If you have a username and password set up on the machine, pass the correct username and password with the __-U__ and __-p__ command line switches.

If capturing from the default ALSA device doesn't work for you, you can specify the ALSA device you want to capture speech from using the __-D__ command line switch.

Feedback
--------

I'm always happy to hear feedback. If you have a problem with _xbmcvc_ or you want to share an idea for a new feature, feel free to [create an issue](https://github.com/kempniu/xbmcvc/issues) at GitHub. You can also [catch me on Twitter](http://twitter.com/kempniu).

