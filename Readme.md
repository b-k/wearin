# Wearin

There's a phrase, 'I played that song so often I wore out the grooves'. This was in
fact possible, just as it's possible to play a cassette tape so many times it snaps.

I [BK] have music on whatever medium that already has glitches, and have grown to expect
them. Those glitches are part of the song as I know it, a reminder of where the music
came from. Sometimes I hear the song played without the glitch and I'm thrown off.

Run the program from the command line via `wearin popsong.mp3`. It will randomly flip
100 bytes in the song, or run the script `wearin.tsr` to automatically add wear to
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
the TSR will keep wearing them down.


## Rate of decay
The default is to insert 100 glitches with each run. Many glitchings are necessary
because the MP3 format has a great deal of redundancy and error-checking,
and the odds are good that most of the inserted glitches have no audible effect.

You will find `int flips=100` at the top of `wearin.c`; adjust the number of byte-flips
per run to your desired rate of decay.

## Warning!

Wear headphones at your own risk! Glitching can sometimes manifest in suddenly loud
noises far beyond the loudest recorded songs.
