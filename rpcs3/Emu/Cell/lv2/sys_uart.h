#pragma once

#include "Emu/Memory/Memory.h"
#include "Emu/Cell/ErrorCodes.h"

struct uart_packet
{
	u8 magic;
	u8 size;
	u8 cmd;
	u8 data[1];
};

// SysCalls
error_code sys_uart_initialize();
error_code sys_uart_receive(ppu_thread& ppu, vm::ptr<char> buffer, u64 size, u32 unk);
error_code sys_uart_send(ppu_thread& ppu, vm::cptr<u8> buffer, u64 size, u64 flags);
error_code sys_uart_get_params(vm::ptr<char> buffer);

error_code sys_sm_get_ext_event2(vm::ptr<u32> stack1, vm::ptr<u32> stack2, vm::ptr<u32> stack3, u32 maybe_bool);
error_code sys_sm_get_params(vm::ptr<u64> a, vm::ptr<u64> b, vm::ptr<u64> c, vm::ptr<u64> d);

struct mouse_info
{
	u32 o_0;
	u32 state;
};
error_code sys_hid_510();
error_code sys_hid_514(u32 a, vm::ptr<u32> b, u32 c);