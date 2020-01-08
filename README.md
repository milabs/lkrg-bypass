# lkrg-bypass

The repository contains set of methods which I consider to be usefull to test LKRG protection against exploitation.

The history of researching of such methods started a year back with my the very first comment to LKRG community of how I see the LKRG protection can be bypassed:

- https://www.openwall.com/lists/lkrg-users/2018/11/16/2

There were few more discussions later:

- https://www.openwall.com/lists/lkrg-users/2018/11/17/4
- https://www.openwall.com/lists/lkrg-users/2019/02/20/1

Even though it was stated that LKRG is bypassable by design the project continues to be developed by it's main contrubutor Adam Zabrocki.

Personally, I found the LKRG source code very well written and I consider it as a great engineering project wich has an amazing integration into the low level kernel's stuff. I really appreciate Adam's effort he put to develop the project. It's an amazing example of how it's possible to develop a high quality out-of-tree kernel module which has so deep kernel intergation.

The repository is organized as a set of methods which I developed while I was playing with LKRG. The following pre-conditions were considered:

- [CVE-2017-1000112](https://github.com/xairy/kernel-exploits/tree/master/CVE-2017-1000112) exploit was used as a test sample base (cc: @xairy)
- `Ubuntu 16.04.4 LTS` with kernel `4.8.0-53-generic` was used as a test box along with vagrant (vbox)
- `KASLR` bypass was considered to be done by the exploit
- `SMAP`/`SMEP` bypass was not considered to be in the scope of the exploit

