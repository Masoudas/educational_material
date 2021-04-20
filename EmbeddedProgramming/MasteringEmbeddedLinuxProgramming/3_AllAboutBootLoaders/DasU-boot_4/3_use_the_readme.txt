The U-Boot has a very nice README file in the root folder of the project, which can be used to gain a general
understanding of the boot process.

Then again, for each processor there's a dedicated readme file. These readme files are inside the board folder,
for each CPU producer. Here's a partial list of ls of this folder:

$ ls board
abilis          cloudengines   highbank     nvidia       ste
advantech       cobra5272      hisilicon    olimex       sunxi
...                                         ti

The ti refers to Texas Instrument. If we go inside of it, we can see the list of TI chips being supported:

$ ls ti
am335x  am57xx  beagle  dra7xx  j721e    omap5_uevm  sdp4430
am43xx  am65x   common  evm     ks2_evm  panda       ti816x

Now, inside the am335x folder, we can see the information for this processor, which are very useful, together
with the MAKEFILE. It appears when we make from root, these are the make rules that are used, but we call the
config folder ones in any case.

$ ls am335x
board.c  board.h  Kconfig  MAINTAINERS  Makefile  mux.c  README  u-boot.lds