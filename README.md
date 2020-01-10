# lkrg-bypass

The repository contains set of methods which I consider to be useful to test LKRG protection against exploitation.

The history of researching of such methods started a year back with my the very first comment to LKRG community of how I see the LKRG protection can be bypassed:

- https://www.openwall.com/lists/lkrg-users/2018/11/16/2

There were few more discussions later:

- https://www.openwall.com/lists/lkrg-users/2018/11/17/4
- https://www.openwall.com/lists/lkrg-users/2019/02/20/1

Even though it was stated that LKRG is bypassable by design the project continues to be developed by it's main contributor Adam Zabrocki.

Personally, I found the LKRG source code very well written and I consider it as a great engineering project wich has an amazing integration into the low level kernel's stuff. I really appreciate Adam's effort he put to develop the project. It's an amazing example of how it's possible to develop a high quality out-of-tree kernel module which has so deep kernel integration.

The repository is organized as a set of methods which I developed while I was playing with LKRG. The following pre-conditions were considered:

- [CVE-2017-1000112](https://github.com/xairy/kernel-exploits/tree/master/CVE-2017-1000112) exploit was used as a test sample base (cc: @xairy)
- `Ubuntu 16.04.4 LTS` with kernel `4.8.0-53-generic` was used as a test box along with vagrant (vbox)
- `SMAP`/`SMEP` bypass was not considered to be in the scope of the exploit

Here I have to say few words about `SMAP`/`SMEP`. I'm pretty sure that of two features only one makes sense: `SMAP`. `SMEP` it's not a big deal and it has nothing against the ROP which is widely used by exploits. So, let's not consider `SMEP` as a problem at all because it's possible to make the exploitation without execution the code from user-mode address space. `SMAP` is the only valuable security feature of the CPU but the exploitation can be done without touching the user space from the context of the kernel. In other words, it's possible to have a ROP chain reliably delivered to the kernel without the need of bypassing `SMAP`. Again, let's put it out of the scope at least now.
