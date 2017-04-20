# Wearin

There's a phrase, 'I played that song so often I wore out the grooves'—and this would
actually happen with much-loved records. That our music slowly decays in specific ways is part
of what makes it ours.

Run the program from the command line via `wearin popsong.mp3` and it will randomly flip
100 bytes in the song. Or run the script `wearin.tsr` to automatically add wear to
any song you play on your computer.

## Compiling

Buckle up, because unlike Python et al, you'll have to compile this program. To do so, type 

`make`

at the command prompt. You should now see the executable `wearin` next to the source, `wearin.c`.

If you don't have a C compiler, you will be informed. Apple users may need to register
with Apple, Inc and download the otherwise free Xcode. Linux/Cygwin users, try installing
`clang` from your package manager.

## The shell script

The `wearin.tsr` script runs in the background and adds wear any time you play a song
using any music player on your computer. It does so by checking for new MP3 or M4A
files in the list of files the system is using (via the `lsof` command). Every time
a new music file appears, the script runs `wearin` on it.

[As long as we're emulating '90s media, we can emulate '90s computing: TSR=terminate
and stay resident, which is what MS DOS called these sorts of background processes.]

Bug: some music players will leave an mp3 file 'open' (according to the operating
system) long after the track is done playing. If there are several such files left open,
`wearin.tsr` will keep wearing them down.


## Rate of decay
The default is to insert 100 glitches with each run. Many glitchings are necessary
because the MP3 format has a great deal of redundancy and error-checking,
and the odds are good that most of the inserted glitches have no audible effect.

You will find `int flips=100` at the top of `wearin.c`; adjust the number of byte-flips
per run to your desired rate of decay.

## Warning!

Wear headphones at your own risk! Glitching can sometimes manifest in suddenly loud
noises far beyond the loudest recorded songs.

## Other warning!

There is no undo! The TSR will find /any/ mp3 that your computer deems open. Unless
you are all in on the slow decay of your music collection, keep offline backups of
your mp3s, and make sure `wearin.tsr` is not running when you make those backups.
